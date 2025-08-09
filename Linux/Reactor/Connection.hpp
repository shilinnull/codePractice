#pragma once

#include <functional>
#include <sys/epoll.h>
#include "Logger.hpp"
#include "Reactor.hpp"
#include "InetAddr.hpp"

class Reactor;

using callback_t = std::function<std::string(std::string &inbuffer)>;

class Connection
{
public:
    Connection() : _events(0), _owner(nullptr)
    {
    }
    virtual void Recver() = 0;
    virtual void Sender() = 0;
    virtual void Excepter() = 0;
    virtual ~Connection() {}
    int Sockfd() { return _sockfd; }
    void SetSocketfd(int sockfd) { _sockfd = sockfd; }
    void SetEvents(uint32_t events) { _events = events; }
    uint32_t Events() { return _events; }
    void SetAddr(const InetAddr &addr) { _peer = addr; }
    Reactor *Owner() { return _owner; }
    void SetOwner(Reactor *r) { _owner = r; }
    void SetCallBack(callback_t cb) { _cb = cb; }

protected:
    int _sockfd;            // 连接的socketfd
    uint32_t _events;       // 连接的事件
    InetAddr _peer;         // 连接的地址
    std::string _inbuffer;  // 连接的输入缓冲区
    std::string _outbuffer; // 连接的输出缓冲区

    Reactor *_owner; // 方便添加使用Reactor方法

    callback_t _cb;
};