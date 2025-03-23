#include "LockGroud.hpp"
using namespace std;
#define NUM 4

// 直接初始化锁
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

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

int tickets = 1000;

// 买票操作
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

        usleep(13); // 执行得到票之后的后续动作，如果不加usleep会导致 饥饿问题
    }
    printf("%s ... quit\n", name);
    return nullptr;
}

int main()
{
    vector<pthread_t> tids;
    vector<ThreadData *> thread_datas;

    // 初始化锁
    pthread_mutex_init(&lock, nullptr);

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

// #define NUM 4

// // 直接初始化锁
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// // 线程名字
// class ThreadData
// {
// public:
//     ThreadData(int num)
//     {
//         threadname = "thread-" + to_string(num);
//     }

// public:
//     string threadname;
// };

// int tickets = 1000;

// // 买票操作
// void *getTicket(void *args)
// {
//     ThreadData *td = static_cast<ThreadData *>(args);
//     const char *name = td->threadname.c_str();
//     while (true)
//     {
//         pthread_mutex_lock(&lock);

//         if (tickets > 0)
//         {
//             usleep(1000);
//             printf("who=%s, get a ticket: %d\n", name, tickets);
//             tickets--;

//             // 解锁 -->
//             pthread_mutex_unlock(&lock);
//         }
//         else
//         {
//             // 解锁 -->
//             pthread_mutex_unlock(&lock);
//             break;
//         }
//         usleep(13); // 执行得到票之后的后续动作，如果不加usleep会导致 饥饿问题
//     }
//     printf("%s ... quit\n", name);
//     return nullptr;
// }

// int main()
// {
//     vector<pthread_t> tids;
//     vector<ThreadData *> thread_datas;

//     // 初始化锁
//     pthread_mutex_init(&lock, nullptr);

//     for (int i = 1; i <= NUM; i++)
//     {
//         pthread_t tid;
//         ThreadData *td = new ThreadData(i);
//         thread_datas.push_back(td);
//         pthread_create(&tid, nullptr, getTicket, thread_datas[i - 1]);
//         tids.push_back(tid);
//     }

//     // 等待
//     for (auto e : tids)
//     {
//         pthread_join(e, nullptr);
//     }
//     // 释放
//     for (auto e : thread_datas)
//     {
//         delete e;
//     }

//     return 0;
// }

// #define NUM 4
// pthread_mutex_t lock;

// // 线程名字
// class ThreadData
// {
// public:
//     ThreadData(int num, pthread_mutex_t *mutex)
//     {
//         lock = mutex; // 初始化锁
//         threadname = "thread-" + to_string(num);
//     }

// public:
//     string threadname;
//     pthread_mutex_t *lock; // 定义一个锁指针
// };

// int tickets = 1000;

// // 买票操作
// void *getTicket(void *args)
// {
//     ThreadData *td = static_cast<ThreadData *>(args);
//     const char *name = td->threadname.c_str();
//     while (true)
//     {
//         // 加锁 -->
//         pthread_mutex_lock(td->lock); // 申请锁成功，才能往后执行，不成功，阻塞等待。

//         if (tickets > 0)
//         {
//             usleep(1000);
//             printf("who=%s, get a ticket: %d\n", name, tickets);
//             tickets--;

//             // 解锁 -->
//             pthread_mutex_unlock(td->lock);
//         }
//         else
//         {
//             // 解锁 --> 在else执行流要注意break，之前要解锁
//             pthread_mutex_unlock(td->lock);
//             break;
//         }
//         usleep(13); // 执行得到票之后的后续动作，如果不加usleep会导致 饥饿问题
//     }
//     printf("%s ... quit\n", name);
//     return nullptr;
// }

// int main()
// {
//     vector<pthread_t> tids;
//     vector<ThreadData *> thread_datas;

//     // 初始化锁
//     pthread_mutex_init(&lock, nullptr);

//     for (int i = 1; i <= NUM; i++)
//     {
//         pthread_t tid;
//         ThreadData *td = new ThreadData(i, &lock);
//         thread_datas.push_back(td);
//         pthread_create(&tid, nullptr, getTicket, thread_datas[i - 1]);
//         tids.push_back(tid);
//     }

//     // 等待
//     for (auto e : tids)
//     {
//         pthread_join(e, nullptr);
//     }
//     // 释放
//     for (auto e : thread_datas)
//     {
//         delete e;
//     }

//     return 0;
// }
