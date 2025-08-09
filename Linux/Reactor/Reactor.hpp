#pragma once

#include <unordered_map>
#include <memory>
#include <time.h>

#include "Util.hpp"
#include "Epoller.hpp"
#include "Connection.hpp"

class Reactor
{
    const static int size = 128;

private:
    bool IsExist(std::shared_ptr<Connection> &conn)
    {
        auto it = _connections.find(conn->Sockfd());
        return it != _connections.end();
    }

    bool IsExist(int sockfd)
    {
        auto it = _connections.find(sockfd);
        return it != _connections.end();
    }

public:
    Reactor() : _epoller(std::make_unique<Epoller>()) {}

    void AddConnection(std::shared_ptr<Connection> &conn)
    {
        if (IsExist(conn))
        {
            LOG(LogLevel::WARNING) << conn->Sockfd() << "conn in Reactor!";
            return;
        }
        conn->SetOwner(this); // 回指当前reactor
        _connections.insert(std::make_pair(conn->Sockfd(), conn));
        _epoller->AddEvent(conn->Sockfd(), conn->Events());
        LOG(LogLevel::INFO) << conn->Sockfd() << " conn add to Reactor";
    }

    void EnableReadWrite(int sockfd, bool enableread, bool enablewrite)
    {
        if (!IsExist(sockfd))
        {
            LOG(LogLevel::WARNING) << sockfd << " conn not in Reactor[EnableReadWrite]";
            return;
        }
        // 1. 修改connection对象
        uint32_t events = (enableread ? EPOLLIN : 0) | (enablewrite ? EPOLLOUT : 0) | EPOLLET;
        _connections[sockfd]->SetEvents(events);

        // 2. 写入到内核
        _epoller->ModEvent(sockfd, events);
        // _epoller->ModEvent(_connections[sockfd]->Sockfd(), _connections[sockfd]->Events());
    }

    void DelConnection(int sockfd)
    {
        if (!IsExist(sockfd))
        {
            LOG(LogLevel::WARNING) << sockfd << " conn not in Reactor[delete]!";
            return;
        }
        // 1. 从epoll中删除
        _epoller->DelEvent(sockfd);
        // 2. 从map中删除
        _connections.erase(sockfd);
        // 3. 关闭sockfd
        close(sockfd);

        LOG(LogLevel::INFO) << sockfd << " conn del to Reactor";
    }

    void LoopOnce(int timeout)
    {
        int n = _epoller->Wait(_revs, size, timeout);
        for (int i = 0; i < n; i++)
        {
            int sockfd = _revs[i].data.fd;
            uint32_t events = _revs[i].events;

            // 关注到读写事件上-->统一报错
            if (events & EPOLLHUP)
                events = (EPOLLIN | EPOLLOUT);
            if (events & EPOLLERR)
                events = (EPOLLIN | EPOLLOUT);

            // 就绪了
            if ((events & EPOLLIN) && IsExist(sockfd))
            {
                _connections[sockfd]->Recver();
            }
            if ((events & EPOLLOUT) && IsExist(sockfd))
            {
                _connections[sockfd]->Sender();
            }
        }
    }

    void ShowConnection()
    {
        std::cout << "#############################" << std::endl;
        for (auto &conn : _connections)
        {
            std::cout << conn.second->Sockfd() << " : "
                      << Event2String(conn.second->Events()) << std::endl;
        }
        std::cout << "#############################" << std::endl;
    }

    void Dispatcher()
    {
        int timeout = 1000;
        for (;;)
        {
            // 1. 处理事件
            LoopOnce(timeout);
            // 2. 连接管理
            ShowConnection();
    }
    }
    ~Reactor() {}

private:
    std::unordered_map<int, std::shared_ptr<Connection>> _connections; // 连接管理
    std::unique_ptr<Epoller> _epoller;                                 // epoll管理
    struct epoll_event _revs[size];                                    // epoll事件数组
};