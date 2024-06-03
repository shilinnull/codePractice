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
        // printf("%s,  pid: %d\n", name, getpid());
        g_val++;
        sleep(1);
        // g_val /= 0;
    }

    return (void *)name; // 返回线程名称作为退出值
}

int main()
{
    pthread_t tids[5];

    pthread_t tid;
    pthread_create(&tid, nullptr, ThreadRun, (void *)"Thread new");
    while (true)
    {
        printf("Thread main,  pid: %d, g_val: %d, &g_val: 0x%p\n", getpid(), g_val, &g_val);
        sleep(1);
    }

    // for (size_t i = 0; i < 5; i++)
    // {
    //     std::string name = "Thread ";
    //     name += std::to_string(i);
    //     pthread_create(&tids[i], nullptr, ThreadRun, (void *)name.c_str());
    //     // printf("Thread main, pid: %d\n", getpid());

    //     sleep(1);
    // }

    // for (size_t i = 0; i < 5; i++)
    // {
    //     void *retval;
    //     pthread_join(tids[i], &retval);
    //     std::cout << "Joined with " << (char *)retval << std::endl;
    // }
    sleep(5);
    std::cout << "Main thread exiting.\n";
    return 0;
}
