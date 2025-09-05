#pragma once

#include <fcntl.h>
#include <string>
#include <sys/epoll.h>

void SetNonBlock(int fd)
{
    int fl = fcntl(fd, F_GETFL);
    if (fl < 0)
    {
        LOG(LogLevel::WARNING) << "设置非阻塞失败, fd: " << fd;
        return;
    }
    LOG(LogLevel::INFO) << "设置非阻塞成功, fd: " << fd;
    fcntl(fd, F_SETFL, fl | O_NONBLOCK);
}

std::string Event2String(uint32_t events)
{
    std::string s;
    if (events & EPOLLIN)
    {
        s = "EPOLLIN";
    }
    if (events & EPOLLOUT)
    {
        s += "|EPOLLOUT";
    }
    if (events & EPOLLET)
    {
        s += "|EPOLLET";
    }
    if (events & EPOLLHUP)
    {
        s += "|EPOLLHUP";
    }
    if (events & EPOLLERR)
    {
        s += "|EPOLLERR";
    }
    return s;
}
