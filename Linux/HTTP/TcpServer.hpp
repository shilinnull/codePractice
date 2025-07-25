#pragma once

#include <memory>
#include <functional>

#include <unistd.h>
#include <signal.h>

#include "Socket.hpp"
#include "InetAddr.hpp"

using callback_t = std::function<std::string(std::string&)>;

class TcpServer
{
public:
    TcpServer(uint16_t port, callback_t cb)
        : _port(port), _listensocket(std::make_unique<TcpSocket>()), _cb(cb)
    {
        _listensocket->BuildListenSocketMethod(_port);
    }

    void Run()
    {
        signal(SIGCHLD, SIG_IGN);

        for (;;)
        {
            InetAddr addr;
            std::shared_ptr<Socket> sockfd = _listensocket->Accept(&addr);
            if (sockfd == nullptr)
                continue;

            if (fork() == 0)
            {
                // child
                _listensocket->Close();
                HandlerRequest(sockfd, addr); // 处理
                exit(0);                      // 处理完后需要进行退出
            }
            sockfd->Close();
        }
    }

    ~TcpServer() {}

private:
    void HandlerRequest(std::shared_ptr<Socket> sockfd, InetAddr addr)
    {
        std::string inbuffer;
        for (;;)
        {
            ssize_t n = sockfd->Recv(&inbuffer);
            if (n > 0)
            {
                LOG(LogLevel::DEBUG) << "处理前: " <<  addr.ToString() << "# " << inbuffer;
                
                // 回掉函数，交给上层处理
                std::string send_str = _cb(inbuffer);
                if(send_str.empty())
                    continue;
                LOG(LogLevel::DEBUG) << "处理后, 准备发送: " << send_str;
                sockfd->Send(send_str);
            }
            else if (n == 0)
            {
                LOG(LogLevel::DEBUG) << addr.ToString() << ", quit me too";
                break;
            }
            else
            {
                LOG(LogLevel::DEBUG) << addr.ToString() << "read err, quit";
                break;
            }
        }
        sockfd->Close(); // 处理完记得关闭
    }

private:
    uint16_t _port;
    std::unique_ptr<Socket> _listensocket;

    callback_t _cb;
};
