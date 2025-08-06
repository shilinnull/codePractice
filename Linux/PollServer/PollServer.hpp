#ifndef POLL_SERVER
#define POLL_SERVER

#include <algorithm>
#include <poll.h>
#include "Socket.hpp"

const static int gsize = sizeof(fd_set) * 8;
const static int gdefaultfd = -1;

class PollServer
{
public:
    PollServer(uint16_t port)
        : _listensock(std::make_unique<TcpSocket>())
    {
        _listensock->BuildListenSocketMethod(port);
        for (int i = 0; i < gsize; i++)
        {
            _fd_array[i].fd = gdefaultfd;
            _fd_array[i].events = _fd_array[i].revents = 0;
        }
        _fd_array[0].fd = _listensock->SockFd();
        _fd_array[0].events = POLLIN; // 监听读事件
    }

    void Accepter()
    {
        InetAddr clientadddr;
        int sockfd = _listensock->Accept(&clientadddr);
        if (sockfd > 0)
        {
            LOG(LogLevel::INFO) << "get a new sockfd: " << sockfd << ", client addr: " << clientadddr.ToString();
            int pos = 0;
            for (; pos < gsize; pos++)
            {
                if (_fd_array[pos].fd == gdefaultfd)
                {
                    _fd_array[pos].fd = sockfd;
                    _fd_array[pos].events = POLLIN; // 监听读事件
                    break;
                }
            }
            // 已经满了
            if (pos == gsize)
            {
                LOG(LogLevel::WARNING) << "server is full!";
                close(sockfd);

                // 可以选择扩容
            }
        }
    }

    void Recver(int index)
    {
        int sockfd = _fd_array[index].fd;
        char buffer[1024];

        ssize_t n = recv(sockfd, buffer, sizeof buffer, 0);
        if (n > 0)
        {
            buffer[n] = 0;
            std::cout << "client say@ " << buffer << std::endl;
            std::string echo_string = "server echo# ";
            echo_string += buffer;
            send(sockfd, echo_string.c_str(), echo_string.size(), 0);
        }
        else if (n == 0)
        {
            LOG(LogLevel::INFO) << "client quit, me too: " << _fd_array[index].fd;
            _fd_array[index].fd = gdefaultfd;
            _fd_array[index].events = _fd_array[index].revents = 0;
            close(sockfd);
        }
        else
        {
            LOG(LogLevel::WARNING) << "recv error: " << _fd_array[index].fd;
            _fd_array[index].fd = gdefaultfd;
            _fd_array[index].events = _fd_array[index].revents = 0;
            close(sockfd);
        }
    }

    void EventDispatcher()
    {
        LOG(LogLevel::INFO) << "fd就绪,有新事件到来";
        for (int i = 0; i < gsize; i++)
        {
            if (_fd_array[i].fd == gdefaultfd)
                continue;
            // 读事件就绪
            if (_fd_array[i].revents & POLLIN)
            {
                if (_fd_array[i].fd == _listensock->SockFd())
                    Accepter(); // 连接管理器
                else
                    Recver(i); // IO处理器
            }
        }
    }

    void Run()
    {
        for (;;)
        {
            int timeout = -1; // -1表示阻塞等待
            int n = poll(_fd_array, gsize, timeout);
            switch (n)
            {
            case 0:
                LOG(LogLevel::DEBUG) << "timeout...";
                break;
            case -1:
                LOG(LogLevel::ERROR) << "poll error";
                break;
            default:
                EventDispatcher();
                break;
            }
        }
    }

    ~PollServer() {}

private:
    std::unique_ptr<Socket> _listensock;
    struct pollfd _fd_array[gsize];
};
#endif