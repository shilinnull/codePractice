#include "ThreadPool.hpp"
#include "Task.hpp"

#include <memory>

int main()
{
    srand(time(nullptr) ^ getpid());

    // 创建线程池
    std::unique_ptr<ThreadPool<Task>> tp = std::make_unique<ThreadPool<Task>>();
    tp->Start(); // 开始线程池

    int cnt = 10;
    while (cnt--)
    {
        int data1 = rand() % 10 + 1;
        int data2 = rand() % 10 + 1;
        usleep(10);
        char op = opers[rand() % opers.size()];
        Task t(data1, data2, op);
        tp->Push(t);
        std::cout << "生产了一个任务: " << t.GetTask() << std::endl;
        sleep(1);
    }

    tp->Stop();
    tp->Wait();

    return 0;
}
