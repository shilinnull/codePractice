#pragma once

#include <sys/epoll.h>
#include "Logger.hpp"


class Epoller
{
private:
    int OperEventHelper(int sockfd, uint32_t events, int op)
    {
        struct epoll_event ev;
        ev.data.fd = sockfd;
        ev.events = events;
        return epoll_ctl(_epfd, op, sockfd, &ev);
    }

public:
    Epoller()
    {
        _epfd = epoll_create(128);
        if(_epfd < 0)
        {
            LOG(LogLevel::FATAL) << "epoll create fatal!";
            exit(1);
        }
        LOG(LogLevel::INFO) << "create epoll fd success, epfd: " << _epfd;
    }

    void AddEvent(int sockfd, uint32_t events)
    {
        int n = OperEventHelper(sockfd, events, EPOLL_CTL_ADD);
        if (n != 0)
        {
            LOG(LogLevel::INFO) << "add: " << sockfd << " events: "
                                << Event2String(events) << " to epoller failed";
            return;
        }
        LOG(LogLevel::INFO) << "add: " << sockfd << " events: "
                            << Event2String(events) << " to epoller success";
    }
    void DelEvent(int sockfd)
    {
        int n = epoll_ctl(_epfd, EPOLL_CTL_DEL, sockfd, nullptr);
        if (n != 0)
        {
            LOG(LogLevel::INFO) << "Del: " << sockfd << " from epoller failed";
            return;
        }
        LOG(LogLevel::INFO) << "Del: " << sockfd << " from epoller success";
    }

    void ModEvent(int sockfd, uint32_t events)
    {
        int n = OperEventHelper(sockfd, events, EPOLL_CTL_MOD);
        if (n != 0)
        {
            LOG(LogLevel::INFO) << "Mod: " << sockfd << " events: "
                                << Event2String(events) << " to epoller failed";
            return;
        }
        LOG(LogLevel::INFO) << "Mod: " << sockfd << " events: "
                            << Event2String(events) << " to epoller success";
    }

    int Wait(struct epoll_event revs[], int num, int timeout)
    {
        int n = epoll_wait(_epfd, revs, num, timeout);
        if(n < 0)
        {
            LOG(LogLevel::WARNING) << "wait error!";
            return -1;
        }
        return n;
    }

    ~Epoller()
    {
        if(_epfd >= 0)
        {
            close(_epfd);
        }
    }
private:
    int _epfd;
};

