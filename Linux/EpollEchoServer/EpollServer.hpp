#ifndef EPOLL_SERVER
#define EPOLL_SERVER

#include <memory>
#include <sys/epoll.h>

#include "Socket.hpp"

const static int gsize = 64;

class EpollServer
{
public:
    EpollServer(uint16_t port)
        : _listensock(std::make_unique<TcpSocket>()), _epfd(-1)
    {
        _listensock->BuildListenSocketMethod(port);
        _epfd = epoll_create(128); // 创建
        if (_epfd < 0)
        {
            LOG(LogLevel::FATAL) << "epoll_create failed";
            return;
        }
        LOG(LogLevel::INFO) << "Listen sockfd is: " << _listensock->SockFd()
                            << " epoll fd is : " << _epfd;

        // 添加listensock到epoll
        struct epoll_event ev;
        ev.events = EPOLLIN | EPOLLET;  // ET模式， 默认是LT
        ev.data.fd = _listensock->SockFd(); // 将监听套接字的文件描述符存入事件数据中
        int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, _listensock->SockFd(), &ev);
        if (n < 0)
        {
            LOG(LogLevel::WARNING) << "epoll_ctl failed";
            return;
        }
    }

    void Accepter()
    {
        InetAddr clientaddr;
        int sockfd = _listensock->Accept(&clientaddr);
        if (sockfd > 0)
        {
            LOG(LogLevel::FATAL) << "获取一个新连接, fd : " << sockfd
                                 << " 客户端地址是: " << clientaddr.ToString();
            struct epoll_event ev;
            ev.events = EPOLLIN;
            ev.data.fd = sockfd;
            int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, sockfd, &ev);
            if (n < 0)
            {
                LOG(LogLevel::WARNING) << "epoll_ctl failed";
                close(sockfd);
                return;
            }
            LOG(LogLevel::INFO) << "添加新连接到epoll中: " << sockfd;
        }
    }
    void Recver(int sockfd)
    {
        char buffer[1024];
        ssize_t n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (n > 0)
        {
            buffer[n] = 0;
            std::cout << "Client Say@ " << buffer;
            std::string echo_string = "echo server# ";
            echo_string += buffer;

            send(sockfd, echo_string.c_str(), echo_string.size(), 0);
        }
        else if (n == 0)
        {
            LOG(LogLevel::INFO) << "client quit, me too, fd is : " << sockfd;

            int n = epoll_ctl(_epfd, EPOLL_CTL_DEL, sockfd, nullptr);
            if (n < 0)
            {
                LOG(LogLevel::WARNING) << "epoll_ctl del error";
            }
            close(sockfd);
        }
        else
        {
            LOG(LogLevel::INFO) << "recv error, fd is : " << sockfd;
            int n = epoll_ctl(_epfd, EPOLL_CTL_DEL, sockfd, nullptr);
            if (n < 0)
            {
                LOG(LogLevel::WARNING) << "epoll_ctl del error";
            }
            close(sockfd);
        }
    }
    void Dispatcher(int num)
    {
        LOG(LogLevel::INFO) << "有事件就绪了...";
        for (int i = 0; i < num; i++)
        {
            int fd = _revs[i].data.fd;
            uint32_t events = _revs[i].events;

            if (events & EPOLLIN)
            {
                if (fd == _listensock->SockFd())
                {
                    Accepter();
                }
                else
                {
                    Recver(fd);
                }
            }
            if (events & EPOLLOUT)
            {
                // ...
            }
        }
    }

    void Run()
    {
        // int timeout = 1000;
        int timeout = -1;
        for (;;)
        {
            // 不可以直接accept，需要知道哪些事件就绪了
            int n = epoll_wait(_epfd, _revs, gsize, timeout);
            switch (n)
            {
            case 0:
                LOG(LogLevel::DEBUG) << "time out...";
                break;
            case -1:
                LOG(LogLevel::FATAL) << "epoll error ...";
                break;
            default:
                // Dispatcher(n);
                LOG(LogLevel::INFO) << "有事件就绪了...";
                break;
            }
        }
    }

    ~EpollServer()
    {
    }

private:
    std::unique_ptr<Socket> _listensock;
    int _epfd;
    struct epoll_event _revs[gsize];
};

#endif