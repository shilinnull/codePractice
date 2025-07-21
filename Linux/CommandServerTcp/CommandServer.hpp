#ifndef TCP_ECHO_SERVER_HPP
#define TCP_ECHO_SERVER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <functional>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "Logger.hpp"
#include "Comm.hpp"
#include "InetAddr.hpp"

const int gbacklog = 8;

using callback_t = std::function<std::string(const std::string &)>;

class CommandServer
{
public:
    CommandServer(callback_t cb, uint16_t port = 8080)
        : _listenSocketfd(-1), _port(port), _cb(cb)
    {
    }

    void Init()
    {
        // 1. socket
        _listenSocketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (_listenSocketfd < 0)
        {
            LOG(LogLevel::FATAL) << "create tcp socket error";
            exit(SOCKET_CREATE_ERR);
        }
        LOG(LogLevel::INFO) << "create tcp socket success, fd: " << _listenSocketfd;

        // 2. bind
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(_port);
        local.sin_addr.s_addr = htonl(INADDR_ANY);

        if (bind(_listenSocketfd, (struct sockaddr *)&local, sizeof(local)) != 0)
        {
            LOG(LogLevel::FATAL) << "bind socket error";
            exit(SOCKET_BIND_ERR);
        }
        LOG(LogLevel::INFO) << "bind socket success, fd: " << _listenSocketfd;

        // 3. listen
        if (listen(_listenSocketfd, gbacklog) != 0)
        {
            LOG(LogLevel::FATAL) << "listen sockte error";
            exit(SOCKTE_LISTEN_ERR);
        }
        LOG(LogLevel::INFO) << "listen sockte success, fd: " << _listenSocketfd;
    }

    class ThreadData
    {
    public:
        ThreadData(int sockfd, CommandServer *self, const InetAddr &addr)
            : _sockfd(sockfd), _self(self), _addr(addr)
        {
        }
        // private:
        int _sockfd;
        CommandServer *_self;
        InetAddr _addr;
    };

    static void *Routine(void *args)
    {
        ThreadData *td = static_cast<ThreadData *>(args);
        pthread_detach(pthread_self());               // 分离线程
        td->_self->HandlerIO(td->_sockfd, td->_addr); // 处理任务

        delete td;
        return nullptr;
    }

    void Start()
    {
        // signal(SIGCHLD, SIG_IGN); // 忽略子进程退出的信号
        for (;;)
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            int sockfd = accept(_listenSocketfd, (struct sockaddr *)&peer, &len);
            if (sockfd < 0)
            {
                LOG(LogLevel::WARNING) << "accept client error";
                continue;
            }

            InetAddr clientaddr(peer);

            LOG(LogLevel::INFO) << "获取新连接成功, sockfd: " << sockfd << " client addr: " << clientaddr.ToString();

            pthread_t tid;
            ThreadData *td = new ThreadData(sockfd, this, clientaddr);
            pthread_create(&tid, nullptr, Routine, (void *)td);
        }
    }

    ~CommandServer()
    {
    }

private:
    void HandlerIO(int sockfd, InetAddr client)
    {
        char buffer[1024];
        for (;;)
        {
            buffer[0] = 0;
            ssize_t n = read(sockfd, buffer, sizeof(buffer) - 1);
            if (n > 0)
            {
                buffer[n] = 0;
                LOG(LogLevel::DEBUG) << client.ToString() << " say: " << buffer;
                std::string result = _cb(buffer);
                write(sockfd, result.c_str(), result.size());
            }
            else if (n == 0)
            {
                LOG(LogLevel::INFO) << "client "
                                    << client.ToString() << " quit, me too, close fd: " << sockfd;
                break;
            }
            else
            {
                LOG(LogLevel::WARNING) << "read client "
                                       << client.ToString() << " error, sockfd : " << sockfd;
                break;
            }
        }
        close(sockfd); // 需要关闭，要不然会导致文件描述符泄露
    }

private:
    int _listenSocketfd;
    uint16_t _port;
    callback_t _cb;
};

#endif // TCP_ECHO_SERVER_HPP