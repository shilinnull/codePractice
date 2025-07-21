#ifndef TCP_ECHO_SERVER_HPP
#define TCP_ECHO_SERVER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "Logger.hpp"
#include "Comm.hpp"
#include "InetAddr.hpp"

const int gbacklog = 8;

class TcpEchoServer
{
public:
    TcpEchoServer(uint16_t port = 8080)
        : _port(port)
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

    void Start()
    {
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

            // 单进程
            HandlerIO(sockfd, clientaddr);
        }
    }

    ~TcpEchoServer()
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
                std::string echo_string = "server echo# ";
                echo_string += buffer;
                LOG(LogLevel::DEBUG) << client.ToString() << "say: " << buffer;
                write(sockfd, echo_string.c_str(), echo_string.size());
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
};

#endif // TCP_ECHO_SERVER_HPP