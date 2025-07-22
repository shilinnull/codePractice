#pragma once

#include <memory>

#include <unistd.h>
#include <signal.h>

#include "Socket.hpp"
#include "InetAddr.hpp"

class TcpServer
{
public:
    TcpServer(uint16_t port)
        : _port(port), _listensocket(std::make_unique<TcpSocket>())
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
                LOG(LogLevel::DEBUG) << addr.ToString() << "# " << inbuffer;
                sockfd->Send(inbuffer);
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
};
