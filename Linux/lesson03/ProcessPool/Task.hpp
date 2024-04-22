#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>

#define TaskNum 3

typedef void (*task_t)(); // 函数指针
task_t tasks[TaskNum];    // 4个任务

void Print()
{
    std::cout << "I am print task" << std::endl;
}

void DownLoad()
{
    std::cout << "I am DownLoad task" << std::endl;
}

void Flush()
{
    std::cout << "I am Flush task" << std::endl;
}

void LoadTask()
{
    srand(time(nullptr) ^ getpid() ^ 17777);
    tasks[0] = Print;
    tasks[1] = DownLoad;
    tasks[2] = Flush;
}

int SelectTask()
{
    return rand() % TaskNum;
}

void ExcuteTask(int number)
{
    if (number < 0 || number > 2)
        return;
    tasks[number]();
}

void work()
{
    while (true)
    {
        int command = 0;
        int n = read(0, &command, sizeof(command));
        if (n == sizeof(int))
        {
            std::cout << "pid is : " << getpid() << " handler task" << std::endl;
            ExcuteTask(command);
        }
        else if (n == 0)
        {
            std::cout << "sub process : " << getpid() << " quit" << std::endl;
            break;
        }
    }
}

void work1()
{
    while (true)
    {
        int command = 0;
        int n = read(0, &command, sizeof(command));
        if (n == sizeof(int))
        {
            std::cout << "pid is : " << getpid() << " handler task" << std::endl;
            ExcuteTask(command);
        }
        else if (n == 0)
        {
            std::cout << "sub process : " << getpid() << " quit" << std::endl;
            break;
        }
    }
}

void work2()
{
    while (true)
    {
        int command = 0;
        int n = read(0, &command, sizeof(command));
        if (n == sizeof(int))
        {
            std::cout << "pid is : " << getpid() << " handler task" << std::endl;
            ExcuteTask(command);
        }
        else if (n == 0)
        {
            std::cout << "sub process : " << getpid() << " quit" << std::endl;
            break;
        }
    }
}