#pragma once

#include "Connection.hpp"
#include "Logger.hpp"
#include "Socket.hpp"
#include "Util.hpp"
#include "Channel.hpp"

class Listener : public Connection
{
public:
    Listener(uint16_t port)
        : _listensockfd(std::make_unique<TcpSocket>()), _port(port)
    {
        _listensockfd->BuildListenSocketMethod(_port);
        _sockfd = _listensockfd->SockFd();
        _events = EPOLLIN | EPOLLET;
        SetNonBlock(_sockfd);
    }

    void Recver() override
    {
        for (;;)
        {
            InetAddr clientaddr;
            int error = 0;
            int sockfd = _listensockfd->Accept(&clientaddr, &error);
            if (sockfd < 0)
            {
                if (error == EAGAIN)
                    break;
                else if (error == EINTR)
                    continue;
                else
                    break;
            }

            SetNonBlock(sockfd);
            // 构建新的连接
            std::shared_ptr<Connection> conn = std::make_shared<Channel>(sockfd, clientaddr);
            conn->SetCallBack(_cb);
            // 添加到Reactor中
            Owner()->AddConnection(conn);
        }
    }

    void Sender() override
    {
        LOG(LogLevel::DEBUG) << "Listener Sender";
    }
    void Excepter() override
    {
        LOG(LogLevel::DEBUG) << "Listener Excepter";
    }

    ~Listener()
    {
    }

private:
    std::unique_ptr<Socket> _listensockfd;
    uint16_t _port;
};
