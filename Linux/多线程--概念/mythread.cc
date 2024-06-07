#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

#define NUM 3

// int *p = NULL;

// 加上__thread就变成了每一个线程
// 线程的局部存储
// __thread int g_val = 100;
// int g_val = 100;
__thread unsigned int number = 0;
__thread int pid = 0;

struct threadData
{
    string threadname;
};

string toHex(pthread_t tid)
{
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "%#lx", tid);
    return buffer;
}

void InitThreadData(threadData *td, int number)
{
    td->threadname = "thread-" + to_string(number); // thread-0
}

// 所有的线程，执行的都是这个函数
void *threadRoutine(void *args)
{
    // 自己把自己分离
    pthread_detach(pthread_self());

    // 每个线程的test_i都是独立的，互不干扰的
    // int test_i = 0;
    threadData *td = static_cast<threadData *>(args);
    // if (td->threadname == "thread-2")
    //     p = &test_i;
    string tid = toHex(pthread_self());
    int pid = getpid();

    int i = 0;
    while (i < 10)
    {
        cout << "tid: " << tid << ", pid: " << pid << endl;

        // printf("pid: %d, tid:%s, threadname: %s, g_val: %d, &g_val: %p\n", getpid(), toHex(pthread_self()).c_str(), td->threadname.c_str(), g_val, &g_val);

        // printf("pid: %d, tid:%s, threadname: %s, test_i: %d, &test_i: %p\n", getpid(), toHex(pthread_self()).c_str(), td->threadname.c_str(), test_i, &test_i);
        // test_i++;
        // g_val++;
        sleep(1);
        i++;
    }

    delete td;
    return nullptr;
}
int main()
{
    // 创建多线程
    vector<pthread_t> tids;
    for (int i = 0; i < NUM; i++)
    {
        pthread_t tid;
        // 线程名字
        threadData *td = new threadData; // 这里使用new，在堆上开空间，每个线程独享
        // 初始化线程id
        InitThreadData(td, i);

        // 创建
        pthread_create(&tid, nullptr, threadRoutine, td);
        tids.push_back(tid); // 将每个线程使用vector管理起来
        sleep(1);
    }
    sleep(1); // 确保复制成功

    // 分离线程
    // for (auto i : tids)
    // {
    //     pthread_detach(i);
    // }
    // cout << "main thread get a thread local value, val: " << *p << ", &val: " << p << endl;

    // pthread_detach后再pthread_join会出错
    for (int i = 0; i < tids.size(); i++)
    {
        int n = pthread_join(tids[i], nullptr);
        printf("n = %d, who = 0x%lx, why: %s\n", n, tids[i], strerror(n));
    }

    return 0;
}

// // 转换成十六进制
// string toHex(pthread_t tid)
// {
//     char hex[64];
//     snprintf(hex, sizeof(hex), "%p", tid);
//     return hex;
// }

// void *threadRun(void *args)
// {
//     while (true)
//     {
//         cout << "Thread id: " << toHex(pthread_self()) << endl;
//         sleep(1);
//     }
// }

// int main()
// {
//     pthread_t tid;
//     pthread_create(&tid, nullptr, threadRun, (void *)"Thread 1");

//     cout << "main thread create thead done, new thread id : " << toHex(tid) << endl;
//     pthread_join(tid, nullptr);
//     return 0;
// }

// #include <thread>

// void threadrun()
// {
//     while (true)
//     {
//         cout << "I am a new thead for C++" << endl;
//         sleep(1);
//     }
// }

// int main()
// {
//     thread t1(threadrun);

//     t1.join();
//     return 0;
// }

// class Request
// {
// public:
//     Request(int start, int end, const string &threadname)
//         : start_(start), end_(end), threadname_(threadname)
//     {
//     }

// public:
//     int start_;
//     int end_;
//     string threadname_;
// };

// class Response
// {
// public:
//     Response(int result, int exitcode) : result_(result), exitcode_(exitcode)
//     {
//     }

// public:
//     int result_;   // 计算结果
//     int exitcode_; // 计算结果是否可靠
// };

// void *sumCount(void *args) // 线程的参数和返回值，不仅仅可以用来进行传递一般参数，也可以传递对象！！
// {
//     Request *rq = static_cast<Request *>(args); //  Request *rq = (Request*)args
//     Response *rsp = new Response(0, 0);
//     for (int i = rq->start_; i <= rq->end_; i++)
//     {
//         cout << rq->threadname_ << " is runing, caling..., " << i << endl;
//         rsp->result_ += i;
//         usleep(100000);
//     }
//     delete rq;
//     return rsp;
// }

// int main()
// {
//     pthread_t tid;
//     Request *rq = new Request(1, 100, "thread 1"); // 计算1到100的和
//     pthread_create(&tid, nullptr, sumCount, rq);   // 创建线程

//     void *ret;
//     pthread_join(tid, &ret);                                                             // 等待线程
//     Response *rsp = static_cast<Response *>(ret);                                        // 相当于类型转换
//     cout << "rsp->result: " << rsp->result_ << ", exitcode: " << rsp->exitcode_ << endl; // 查看结果

//     delete rsp;
//     return 0;
// }

// void *ThreadRun(void *args)
// {
//     const char *name = (const char *)args;
//     int cnt = 5;
//     while (cnt)
//     {
//         printf("%s, cnt: %d\n", name, cnt);
//         sleep(1);
//         cnt--;
//     }
// }

// int main()
// {
//     pthread_t tid;
//     pthread_create(&tid, nullptr, ThreadRun, (void *)"Thread new");

//     sleep(1);            // 保证新线程已经启动
//     pthread_cancel(tid); // 取消线程

//     void *retval;
//     pthread_join(tid, &retval);
//     printf("Joined with \"%d\"\n", (int *)retval);

//     std::cout << "Main thread exiting.\n";
//     return 0;
// }

// int g_val = 100;

// void *ThreadRun(void *args)
// {
//     const char *name = (const char *)args;
//     while (true)
//     {
//         printf("%s,  pid: %d, g_val: %d, &g_val: 0x%p\n", name, getpid(), g_val, &g_val);
//         // printf("%s,  pid: %d\n", name, getpid());
//         g_val++;
//         sleep(1);
//         // g_val /= 0;
//     }

//     return (void *)name; // 返回线程名称作为退出值
// }

// int main()
// {
//     pthread_t tids[5];

//     pthread_t tid;
//     pthread_create(&tid, nullptr, ThreadRun, (void *)"Thread new");
//     while (true)
//     {
//         printf("Thread main,  pid: %d, g_val: %d, &g_val: 0x%p\n", getpid(), g_val, &g_val);
//         sleep(1);
//     }

//     // for (size_t i = 0; i < 5; i++)
//     // {
//     //     std::string name = "Thread ";
//     //     name += std::to_string(i);
//     //     pthread_create(&tids[i], nullptr, ThreadRun, (void *)name.c_str());
//     //     // printf("Thread main, pid: %d\n", getpid());

//     //     sleep(1);
//     // }

//     // for (size_t i = 0; i < 5; i++)
//     // {
//     //     void *retval;
//     //     pthread_join(tids[i], &retval);
//     //     std::cout << "Joined with " << (char *)retval << std::endl;
//     // }
//     sleep(5);
//     std::cout << "Main thread exiting.\n";
//     return 0;
// }
