#ifndef SELECT_SERVER
#define SELECT_SERVER

#include <algorithm>
#include "Socket.hpp"

const static int gsize = sizeof(fd_set) * 8;
const static int gdefaultfd = -1;

class SelectServer
{
public:
    SelectServer(uint16_t port)
        : _listensock(std::make_unique<TcpSocket>())
    {
        _listensock->BuildListenSocketMethod(port);
        for (int i = 0; i < gsize; i++)
        {
            _fd_array[i] = gdefaultfd;
        }
        _fd_array[0] = _listensock->SockFd();
    }

    void Accepter()
    {
        InetAddr clientadddr;
        int sockfd = _listensock->Accept(&clientadddr);
        if (sockfd > 0)
        {
            LOG(LogLevel::INFO) << "get new sockfd: " << sockfd << ", client addr: " << clientadddr.ToString();
            // 不可以直接recv/read
            // 将新的sock托管给select
            int pos = 0;
            for (; pos < gsize; pos++)
            {
                if (_fd_array[pos] == gdefaultfd)
                {
                    _fd_array[pos] = sockfd;
                    break;
                }
            }
            // 已经满了
            if (pos == gsize)
            {
                LOG(LogLevel::WARNING) << "server is full!";
                close(sockfd);
            }
        }
    }

    void Recver(int index)
    {
        int sockfd = _fd_array[index];
        char buffer[1024];

        ssize_t n = recv(sockfd, buffer, sizeof buffer, 0);
        if(n > 0)
        {
            buffer[n] = 0;
            std::cout << "client say@ " << buffer << std::endl;
            std::string echo_string = "server echo# ";
            echo_string += buffer;
            send(sockfd, echo_string.c_str(), echo_string.size(), 0);
        }
        else if(n == 0)
        {
            LOG(LogLevel::INFO) << "client quit, me too: " << _fd_array[index];
            _fd_array[index] = gdefaultfd;
            close(sockfd);
        }
        else
        {
            LOG(LogLevel::WARNING) << "recv error: " << _fd_array[index];
            _fd_array[index] = gdefaultfd;
            close(sockfd);
        }
    }

    void EventDispatcher(fd_set &rfds)
    {
        LOG(LogLevel::INFO) << "fd就绪,有新事件到来";
        for (int i = 0; i < gsize; i++)
        {
            if (_fd_array[i] == gdefaultfd)
                continue;
            // 读事件就绪
            if (FD_ISSET(_fd_array[i], &rfds))
            {
                if (_fd_array[i] == _listensock->SockFd())
                    Accepter(); // 连接管理器
                else
                    Recver(i); // IO处理器
            }
            // else if(FD_ISSET(fd_array[i], &wrfds)) // 写事件就绪
            // {

            // }
        }
    }

    void Run()
    {
        for (;;)
        {
            struct timeval timeout = {3, 0}; // 设置超时时间
            fd_set rfds;
            FD_ZERO(&rfds);                       // 清0
            FD_SET(_listensock->SockFd(), &rfds); // 设置
            int maxfd = gdefaultfd;
            for (int i = 0; i < gsize; i++)
            {
                if (_fd_array[i] == gdefaultfd)
                    continue;
                FD_SET(_fd_array[i], &rfds);
                maxfd = std::max(maxfd, _fd_array[i]);
                LOG(LogLevel::DEBUG) << " 添加fd: " << _fd_array[i];
            }
            // 就绪事件通知机制
            int n = select(maxfd + 1, &rfds, nullptr, nullptr, nullptr /*&timeout*/);
            switch (n)
            {
            case 0:
                LOG(LogLevel::DEBUG) << "timeout...: " << timeout.tv_sec << ": " << timeout.tv_usec;
                break;
            case -1:
                LOG(LogLevel::ERROR) << "select error";
                break;
            default:
                // 一定有事件就绪了, 就绪事件，派发到不同的处理模块
                EventDispatcher(rfds);
                break;
            }
        }
    }

    ~SelectServer() {}

private:
    std::unique_ptr<Socket> _listensock;
    int _fd_array[gsize];
};
#endif