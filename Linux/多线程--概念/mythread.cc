#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

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
