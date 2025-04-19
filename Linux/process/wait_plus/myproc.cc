#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <assert.h>
#include "Task.hpp"
#include "Tool.hpp"


int main()
{
    Tool tool;
    tool.pushFunc(DownLoad);
    tool.pushFunc(PrintLog);
    tool.pushFunc(FlushData);

    pid_t id = fork();
    assert(id!=-1);
    if(id==0)
    {
        // child process
        int cnt=5;
        while(cnt)
        {
            printf("child process running，pid:%d，ppid:%d，cnt:%d\n",getpid(),getppid(),cnt--);
            sleep(1);
        }
        exit(10);
    }
    int status = 0;
    while(1)
    {
        // WNOHANG是非阻塞等待，子进程没有退出，父进程检测一次之后，立即返回
        pid_t ret=waitpid(id,&status,WNOHANG);
        if(ret == 0)
        {
            // waitpid调用成功，子进程没有退出
            printf("Wait for success，but the child process is still running\n");

            // 父进程做其他事情
            tool.Execute();
            sleep(1);
        }
        else if(ret == id)
        {
            // waitpid调用成功，子进程退出
            printf("wait success，exit code:%d，signal number:%d\n",(status >> 8) & 0xFF, status & 0x7F);
            break;
        }
        else
        {
            // waitpid调用失败，例如等待了一个不属于该父进程的子进程
            printf("The waitpid call failed\n");
            break;
        }
        sleep(1);
    }
    return 0;
}

