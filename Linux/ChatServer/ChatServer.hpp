#ifndef UDP_SERVER_HPP
#define UDP_SERVER_HPP

#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <functional>

#include "Logger.hpp"
#include "InetAddr.hpp"

using callback_t = std::function<void(int sockfd, std::string message, InetAddr addr)>; // hij

class ChatServer
{
public:
    ChatServer(const uint16_t &port, callback_t cb)
        : _port(port), _sockfd(-1), _isRunning(false), _cb(cb)
    {
    }

    void Init()
    {
        // 1. 创建socket
        _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (_sockfd < 0)
        {
            LOG(LogLevel::FATAL) << "create socket error";
            exit(1);
        }
        LOG(LogLevel::INFO) << "create socket success : " << _sockfd;

        // 2. bind
        InetAddr local(_port); // 使用InetAddr类来封装地址信息

        int n = bind(_sockfd, local.Addr(), local.Length());
        if (n < 0)
        {
            LOG(LogLevel::FATAL) << "bind socket error";
            exit(2);
        }
        LOG(LogLevel::INFO) << "bind socket success : " << _sockfd;
    }

    void Start()
    {
        _isRunning = true;
        while (_isRunning)
        {
            char buffer[1024];
            buffer[0] = 0;

            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            // 1. 读取数据
            ssize_t n = recvfrom(_sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&peer, &len);
            if (n > 0)
            {
                buffer[n] = 0; // 清空
                InetAddr clientAddr(peer);

                LOG(LogLevel::DEBUG) << "[" << clientAddr.IP() << ":" << clientAddr.Port() << "]"
                                     << "# " << buffer;
                // 2. 调用回调函数 处理任务
                std::string message = buffer;
                _cb(_sockfd, message, clientAddr); // 调用回调函数处理接收到的消息
            }
        }
        _isRunning = false;
    }

    void Stop()
    {
        _isRunning = false;
    }
    ~ChatServer()
    {
        if (_sockfd >= 0)
        {
            close(_sockfd);
            LOG(LogLevel::INFO) << "close socket success : " << _sockfd;
        }
    }

private:
    uint16_t _port; // 服务器端口号
    int _sockfd;    // 套接字描述符

    callback_t _cb; // 回调函数

    bool _isRunning; // 服务器是否在 -运行
};

#endif // UDP_SERVER_HPP