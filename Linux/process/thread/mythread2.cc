#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void *ThreadRun(void *args)
{
    const char *name = static_cast<const char *>(args);
    while (true)
    {
        printf("%s,  pid: %d\n", name, getpid());
        sleep(1);
    }

    return (void *)name; // 返回线程名称作为退出值
}

int main()
{
    std::vector<pthread_t> tids;
    for (size_t i = 0; i < 5; i++)
    {
        pthread_t tid;
        // char idbuffer[64];
        char *name = new char[64];
        snprintf(name, 64, "thread-%ld", i + 1); // 更新名字
        pthread_create(&tid, nullptr, ThreadRun, name);
        tids.push_back(tid);
        // sleep(1);
        printf("Thread main, pid: %d\n", getpid());
    }
    for (auto &tid : tids)
        printf("main create a new thread, new thread id is : 0x%lx\n", tid);

    sleep(5);
    std::cout << "Main thread exiting.\n";
    return 0;
}