#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void *ThreadRun(void *args)
{
    const char *name = (char *)args;
    while (true)
    {
        printf("%s,  pid: %d\n", name, getpid());
        sleep(1);
    }
    return (void *)name;
}

int main()
{
    pthread_t tids[5];
    for (int i = 1; i <= 5; i++)
    {
        std::string name = "thread-";
        name += std::to_string(i);
        pthread_create(&tids[i], nullptr, ThreadRun, (void *)name.c_str());
        printf("Thread main, pid: %d\n", getpid());
        sleep(1);
    }
    sleep(5);
    std::cout << "Main thread exiting.\n";
    return 0;
}