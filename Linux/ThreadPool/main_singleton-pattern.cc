#include "ThreadPool_singleton-pattern.hpp"
#include "Task.hpp"

#include <memory>

int main()
{
    srand(time(nullptr) ^ getpid());

    int cnt = 10;
    while (cnt--)
    {
        int data1 = rand() % 10 + 1;
        int data2 = rand() % 10 + 1;
        usleep(10);
        char op = opers[rand() % opers.size()];
        Task t(data1, data2, op);
        ThreadPool<Task>::getInstance()->Push(t);
        std::cout << "生产了一个任务: " << t.GetTask() << std::endl;
        sleep(1);
    }

    ThreadPool<Task>::getInstance()->Stop();
    ThreadPool<Task>::getInstance()->Wait();

    return 0;
}
