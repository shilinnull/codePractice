#ifndef __NAMED_PIPE_HPP__
#define __NAMED_PIPE_HPP__

#include <iostream>
#include <string>
#include <cstdio>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

const std::string filename = "fifo";
mode_t mode = 0666;
#define SIZE 128
#define DefaultFd -1

#define Creater 1
#define USER 2

class NamedPipe
{
public:
    NamedPipe(const std::string &name, int who)
        : _name(name), _fd(DefaultFd), _who(who)
    {
        // 如果是server端就创建
        if (_who == Creater)
        {
            int n = mkfifo(filename.c_str(), mode);
            if (n < 0)
                perror("mkfifo");
            std::cout << "mkfifo success" << std::endl;
        }
    }

    bool OpenForRead()
    {
        return OpenNamedPipe(O_RDONLY);
    }

    bool OpenForWrite()
    {
        return OpenNamedPipe(O_WRONLY);
    }

    // const &: const std::string &XXX 输入
    // *      : std::string *  输出
    // &      : std::string &  输入输出
    bool Read(std::string *out)
    {
        char buffer[SIZE] = {0};
        ssize_t n = read(_fd, buffer, sizeof(buffer) - 1);
        if (n > 0)
        {
            buffer[n] = 0;
            *out = buffer;
        }
        else if (n == 0)
            return false;
        else
            return false;
        return true;
    }

    void Write(const std::string &in)
    {
        write(_fd, in.c_str(), in.size());
    }

    ~NamedPipe()
    {
        // 由server端来管理
        if (_who == Creater)
        {
            if (_fd != DefaultFd)
                close(_fd);

            int m = unlink(filename.c_str());
            if (m < 0)
                std::cerr << "unlink fail!" << std::endl;
            std::cout << "creater free named pipe" << std::endl;
        }
    }

private:
    bool OpenNamedPipe(mode_t mode)
    {
        _fd = open(filename.c_str(), mode);
        if (_fd < 0)
        {
            perror("open");
            return false;
        }
        std::cout << "open file success" << std::endl;
        return true;
    }

private:
    std::string _name; // 文件名字
    int _fd;           // 文件fd
    int _who;          // 标识是谁
};

#endif