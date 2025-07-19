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

using callback_t = std::function<std::string(const std::string &word, const std::string &whoip, uint16_t whoport)>;

class DictServer
{
public:
    DictServer(const uint16_t &port, callback_t cb)
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
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET; // 采用网络通信, AF_INET填充一个struct sockaddr_in结构体,为了用于网络通信
        // local.sin_addr.s_addr = inet_addr(_ip.c_str()); // 1.string->uint32_t 2.htonl
        local.sin_addr.s_addr = INADDR_ANY; // 绑定到任意IP地址
        local.sin_port = htons(_port);      // 转成网络字节序, 给别人发消息,也要把自己的port和ip发送给对方

        int n = bind(_sockfd, (struct sockaddr *)&local, sizeof(local));
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
        LOG(LogLevel::INFO) << "server start running";
        while (_isRunning)
        {
            char buffer[1024];
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            bzero(buffer, sizeof(buffer));
            // 1. 读取数据
            ssize_t n = recvfrom(_sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&peer, &len);
            if (n < 0)
            {
                LOG(LogLevel::ERROR) << "recvfrom error";
                continue;
            }
            else
            {
                buffer[n] = 0; // 清空
                uint16_t client_port = ntohs(peer.sin_port);
                std::string client_ip = inet_ntoa(peer.sin_addr);

                std::string word = buffer;
                LOG(LogLevel::DEBUG) << "[" << client_ip << ":" << client_port << "]"
                                     << "# " << word;
                // 2. 调用回调函数 处理任务
                std::string result = _cb(word, client_ip, client_port);
                sendto(_sockfd, result.c_str(), result.size(), 0, (struct sockaddr *)&peer, len);
            }
        }
        _isRunning = false;
    }

    void Stop()
    {
        _isRunning = false;
    }
    ~DictServer()
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