#pragma once
#include "Epoller.hpp"
#include "Connection.hpp"

class Channel : public Connection
{
    static const int buffersize = 1024;

public:
    Channel(int sockfd, InetAddr &addr)
    {
        _sockfd = sockfd;
        _peer = addr;
        _events = EPOLLIN | EPOLLET;
    }

    void Recver() override
    {
        for (;;)
        {
            char buffer[buffersize];
            ssize_t n = recv(_sockfd, buffer, sizeof(buffer) - 1, 0);
            if (n > 0)
            {
                buffer[n] = 0;
                _inbuffer += buffer;
            }
            else if (n == 0)
            {
                LOG(LogLevel::INFO) << "client quit, client is : " << _peer.ToString();
                Excepter();
                return; 
            }
            else
            {
                if (errno == EAGAIN)
                {
                    break;
                }
                else if (errno == EINTR)
                {
                    continue;
                }
                else
                {
                    LOG(LogLevel::INFO) << "recv error, client is : " << _peer.ToString();
                    Excepter();
                    return; 
                }
            }
        }

        // 一定把数据全部读完成了
        _outbuffer = _cb(_inbuffer);
        std::cout << "_outbuffer: " << _outbuffer << std::endl;

        // if (!_outbuffer.empty())
        //     Owner()->EnableReadWrite(_sockfd, true, true);

        // 最佳实践 -- 直接发送
        if(!_outbuffer.empty())
            Sender();
    }

    void Sender() override
    {
        for (;;)
        {
            ssize_t n = send(_sockfd, _outbuffer.c_str(), _outbuffer.size(), 0);
            if (n > 0)
            {
                _outbuffer.erase(0, n);
                if (_outbuffer.empty())
                    break;
            }
            else if (n == 0)
                break;
            else if (n < 0)
            {
                if (errno == EAGAIN)
                    break;
                else if (errno == EINTR)
                    continue;
                else
                {
                    Excepter();
                    return;
                }
            }
        }
        // 1. 发送完成 2. 缓冲区写满
        if (!_outbuffer.empty())
            Owner()->EnableReadWrite(_sockfd, true, true);
        else
            Owner()->EnableReadWrite(_sockfd, true, false);
    }

    void Excepter() override
    {
        Owner()->DelConnection(_sockfd);
    }

    ~Channel() {}
};
