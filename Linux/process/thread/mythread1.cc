#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int g_val = 100;

void *ThreadRun(void *args)
{
    const char *name = (const char *)args;
    while (true)
    {
        printf("%s,  pid: %d, g_val: %d, &g_val: 0x%p\n", name, getpid(), g_val, &g_val);
        g_val++;
        sleep(1);
    }

    return (void *)name; // 返回线程名称作为退出值
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, ThreadRun, (void *)"Thread new");
    while (true)
    {
        printf("Thread main,  pid: %d, g_val: %d, &g_val: 0x%p\n", getpid(), g_val, &g_val);
        sleep(1);
    }
    sleep(5);
    std::cout << "Main thread exiting.\n";
    return 0;
}