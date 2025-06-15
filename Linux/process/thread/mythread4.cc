#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <unistd.h>
using namespace std;

#define NUM 10

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

    // 每个线程的test_i都是独立的，互不干扰的
    int test_i = 0;
    threadData *td = static_cast<threadData *>(args);

    int i = 0;
    while (i < 10)
    {
        printf("pid: %d, tid:%s, threadname: %s, test_i: %d, &test_i: %p\n", getpid(), toHex(pthread_self()).c_str(), td->threadname.c_str(), test_i, &test_i);
        test_i++;
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
    return 0;
}