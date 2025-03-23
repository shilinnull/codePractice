#include <iostream>
#include <ctime>
#include "Task.hpp"
#include "ThreadPool.hpp"

int main()
{
    // 创建线程
    ThreadPool<Task> *tp = new ThreadPool<Task>(5);

    // 启动线程
    ThreadPool<Task>::GetInstance()->Start();
    srand(time(nullptr) ^ getpid());

    while (true)
    {
        // 1. 构建任务
        int x = rand() % 10 + 1;
        usleep(10);
        int y = rand() % 10 + 1;
        char op = opers[rand() % opers.size()];
        Task t(x, y, op);

        // 2. 交给线程池进行处理
        ThreadPool<Task>::GetInstance()->Push(t);
        std::cout << "main thread make task: " << t.GetTask() << std::endl;
        sleep(1);
    }

    return 0;
}