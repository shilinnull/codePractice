#pragma once

#include <iostream>
#include <time.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 1024

#define Info 0
#define Debug 1
#define Warning 2
#define Error 3
#define Fatal 4

#define Screen 1
#define Onefile 2
#define Classfile 3

#define LogFile "log.txt"

class Log
{
public:
    Log()
    {
        _printMethod = Screen;
        _path = "./log/";
    }

    // 选择将日志打印到哪
    void Enable(int method)
    {
        _printMethod = method;
    }

    // 头信息
    std::string levelToString(int level)
    {
        switch (level)
        {
        case Info:
            return "Info";
        case Debug:
            return "Debug";
        case Warning:
            return "Warning";
        case Error:
            return "Error";
        case Fatal:
            return "Fatal";
        default:
            return "None";
        }
    }

    // 打印日志
    void printLog(int level, const std::string &logtxt)
    {
        switch (_printMethod)
        {
        case Screen:
            std::cout << logtxt << std::endl;
            break;
        case Onefile:
            printOneFile(LogFile, logtxt);
            break;
        case Classfile:
            printClassFile(level, logtxt);
            break;
        default:
            break;
        }
    }

    // 单文件打印
    void printOneFile(const std::string &logname, const std::string &logtxt)
    {
        std::string _logname = _path + logname;
        int fd = open(_logname.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0666);
        if (fd < 0)
            return;
        write(fd, logtxt.c_str(), logtxt.size());
        close(fd);
    }

    // 多文件打印
    void printClassFile(int level, const std::string &logtxt)
    {
        std::string filename = LogFile;
        filename += '.';
        filename += levelToString(level);
        printOneFile(filename, logtxt);
    }

    ~Log()
    {
    }

    // 日志格式控制
    // 该函数为重载的函数调用运算符，用于打印格式化的日志信息
    void operator()(int level, const char *format, ...)
    {
        // 获取当前时间
        time_t t = time(nullptr);
        // 将时间转换为本地时间的结构体
        struct tm *ctime = localtime(&t);
        // 声明一个左侧缓冲区，用于存储日志的时间信息
        char leftbuffer[SIZE];

        // 格式化日志的时间信息，并写入左侧缓冲区
        snprintf(leftbuffer, sizeof(leftbuffer), "[%s][%d-%d-%d %d:%d:%d]", levelToString(level).c_str(), ctime->tm_year + 1900, ctime->tm_mon + 1, ctime->tm_mday, ctime->tm_hour, ctime->tm_min, ctime->tm_sec);

        // 声明一个参数列表
        va_list s;
        // 初始化参数列表
        va_start(s, format);
        // 声明一个右侧缓冲区，用于存储格式化后的日志消息
        char rightbuffer[SIZE];
        // 格式化日志消息，并写入右侧缓冲区
        vsnprintf(rightbuffer, sizeof(rightbuffer), format, s);
        // 结束对参数列表的处理
        va_end(s);
        // 声明一个日志文本缓冲区，用于存储完整的日志信息
        char logtxt[SIZE * 2];
        // 合并左侧缓冲区和右侧缓冲区中的信息，存储到日志文本缓冲区
        snprintf(logtxt, sizeof(logtxt), "%s %s", leftbuffer, rightbuffer);

        // 调用打印日志的函数，将日志信息打印出来
        printLog(level, logtxt);
    }

private:
    int _printMethod;
    std::string _path;
};
