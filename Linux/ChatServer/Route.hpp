#ifndef CHATSERVER_ROUTE_HPP
#define CHATSERVER_ROUTE_HPP

#include <vector>

#include "InetAddr.hpp"
#include "Logger.hpp"

class Route
{
private:
    bool isExists(const InetAddr &addr) const 
    {
        for (const auto &user : _online_users)
        {
            if (user == addr)
            {
                return true; // 用户已存在
            }
        }
        return false; // 用户不存在
    }

    void Adduser(const InetAddr &addr)
    {
        if(!isExists(addr))
            _online_users.push_back(addr);
    }

    void DeleteUser(const InetAddr &addr)
    {
        for (auto it = _online_users.begin(); it != _online_users.end(); ++it)
        {
            if (*it == addr)
            {
                _online_users.erase(it);
                break; // 删除后退出循环
            }
        }
    }

    void SentMessageToAll(int sockfd, const std::string &message, const InetAddr &sender_addr)
    {
        for (const auto &user : _online_users)
        {
            LOG(LogLevel::DEBUG) << "route[" <<  message  << "] to: "<< user.ToString();
            std::string info = user.ToString();
            info += "# ";
            info += message;

            sendto(sockfd, info.c_str(), info.size(), 0, user.Addr(), user.Length());
        }
    }

public:
    Route()
    {}

    void RouteMessageToAll(int sockfd, const std::string &message, const InetAddr &sender_addr)
    {
        Adduser(sender_addr); // 添加用户到在线列表
        SentMessageToAll(sockfd, message, sender_addr); // 将消息发送给所有在线用户

        // DeleteUser(sender_addr); // 删除用户
    }

    ~Route()
    {}

private:
    std::vector<InetAddr> _online_users; // 在线用户列表
};

#endif // CHATSERVER_ROUTE_HPP