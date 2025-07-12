#include "BlockQueue.hpp"
#include "Task.hpp"
#include <unistd.h>
#include <ctime>

std::string TOHEX(pthread_t x)
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "0x%lx", x);
    return buffer;
}

void *Consumer(void *args)
{
    BlockQueue<Task> *bq = static_cast<BlockQueue<Task> *>(args);

    while (true)
    {
        sleep(1);
        // 消费
        Task t(0, 0, '+'); // 创建一个空任务
        bq->Pop(&t);
        // t.Run(); // 之间调用
        t(); // 仿函数

        std::cout << "处理任务: " << t.GetTask() << " 运算结果是： " << t.GetResult() << " thread id: " << TOHEX(pthread_self()) << std::endl;
    }
}

void *Productor(void *args)
{
    int len = opers.size();
    BlockQueue<Task> *bq = static_cast<BlockQueue<Task> *>(args);
    while (true)
    {
        // 生产
        int data1 = rand() % 10 + 1;
        int data2 = rand() % 10 + 1;
        usleep(10);
        char op = opers[rand() % len];
        Task t(data1, data2, op);
        bq->Push(t); // 入队
        std::cout << "生产了一个任务: " << t.GetTask() << " thread id: " << TOHEX(pthread_self()) << std::endl;
    }
}

int main()
{
    srand(time(nullptr));

    BlockQueue<Task> *bq = new BlockQueue<Task>();
    pthread_t c[3], p[5];
    for (int i = 0; i < 3; i++)
    {
        pthread_create(c + i, nullptr, Consumer, bq);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_create(p + i, nullptr, Productor, bq);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(c[i], nullptr);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(p[i], nullptr);
    }

    delete bq;
    return 0;
}