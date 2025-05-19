#ifndef __TASK_HPP__
#define __TASK_HPP__

#include <iostream>
#include <functional>
#include <vector>

using task_t = std::function<void()>;

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

void Log()
{
    std::cout << "I am Log task" << std::endl;
}

// 保存任务
std::vector<task_t> tasks;

class TaskInit
{
public:
    TaskInit()
    {
        tasks.push_back(Print);
        tasks.push_back(DownLoad);
        tasks.push_back(Flush);
        tasks.push_back(Log);
    }
};

// 任务初始化
TaskInit tasks_init;

#endif