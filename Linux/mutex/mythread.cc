#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <vector>
#include "lockGuard.hpp"
using namespace std;

#define NUM 4
int tickets = 1000;

Mutex lock;

// 线程名字
class ThreadData
{
public:
    ThreadData(int num)
    {
        threadname = "thread-" + to_string(num);
    }

public:
    string threadname;
};

void *getTicket(void *args)
{
    ThreadData *td = static_cast<ThreadData *>(args);
    const char *name = td->threadname.c_str();
    while (true)
    {
        { // 对锁进行临时对象控制

            // 定义了一个临时的锁对象
            LockGuard lockGuard(&lock); // RAII风格的锁
            if (tickets > 0)
            {
                usleep(1000);
                printf("who=%s, get a ticket: %d\n", name, tickets);
                tickets--;
            }
            else
                break;
        }
        // 继续执行非临界区代码
        usleep(13); // 执行得到票之后的后续动作，如果不加usleep会导致 饥饿问题
    }
    printf("%s ... quit\n", name);
    return nullptr;
}


int main()
{
    vector<pthread_t> tids;
    vector<ThreadData *> thread_datas;
    for (int i = 1; i <= NUM; i++)
    {
        pthread_t tid;
        ThreadData *td = new ThreadData(i);
        thread_datas.push_back(td);
        pthread_create(&tid, nullptr, getTicket, thread_datas[i - 1]);
        tids.push_back(tid);
    }

    // 等待
    for (auto e : tids)
    {
        pthread_join(e, nullptr);
    }
    // 释放
    for (auto e : thread_datas)
    {
        delete e;
    }
    return 0;
}