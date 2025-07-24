#ifndef DAEMON_HPP
#define DAEMON_HPP

#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/stat.h>
#include <fcntl.h>

void myDaemon()
{
    // 1.让调用进程忽略掉异常的信号
    signal(SIGPIPE, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);

    // 2.如何让自己不是组长, setsid
    if (fork() > 0)
        exit(0);

    setsid(); // 守护进程也叫精灵进程，本质就是孤儿进程的一种

    // 3.守护进程是脱离终端的,关闭或者重定向以前进程默认打开的文件
    int fd = open("/dev/null", O_RDWR);
    if (fd > 0)
    {
        dup2(fd, 0);
        dup2(fd, 1);
        dup2(fd, 2);
    }
    else
    {
        close(0);
        close(1);
        close(2);
    }

    // 4.进程执行路径发送更改
    chdir("/");
}
#endif