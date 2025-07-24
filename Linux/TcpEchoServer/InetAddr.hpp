#ifndef INET_ADDR_HPP
#define INET_ADDR_HPP

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

class InetAddr
{
private:
    void Host2Net()
    {
        bzero(&_addr, sizeof(_addr));
        _addr.sin_family = AF_INET; // 使用IPv4地址族
        _addr.sin_addr.s_addr = inet_addr(_ip.c_str());
        _addr.sin_port = htons(_port);
    }
    void Net2Host()
    {
        _ip = inet_ntoa(_addr.sin_addr);
        _port = ntohs(_addr.sin_port);
    }

public:
    InetAddr(struct sockaddr_in &addr)
        : _addr(addr)
    {
        Net2Host(); // 将网络字节序转换为主机字节序
    }

    InetAddr(uint16_t &port, const std::string &ip = "0.0.0.0")
        : _port(port), _ip(ip)
    {
        Host2Net(); // 将主机字节序转换为网络字节序
    }

    const std::string &IP() const { return _ip; }
    uint16_t Port() const { return _port; }

    const struct sockaddr *Addr() const
    {
        return reinterpret_cast<const struct sockaddr *>(&_addr);
    }
    struct sockaddr *Addr()
    {
        return reinterpret_cast<struct sockaddr *>(&_addr);
    }
    socklen_t Length() const
    {
        return sizeof(_addr);
    }

    std::string ToString() const
    {
        return _ip + ":" + std::to_string(_port);
    }

    bool operator==(const InetAddr &addr) const
    {
        return (_ip == addr._ip) && (_port == addr._port);
    }

    ~InetAddr()
    {
    }

private:
    struct sockaddr_in _addr;
    std::string _ip;
    uint16_t _port;
};

#endif // INET_ADDR_HPP