#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void *PthreadRun(void *args)
{
    int cnt = 0;
    while (true)
    {
        cout << "new Thread, cnt = " << cnt << endl;
        cnt++;
        sleep(1);
    }
    return nullptr;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, PthreadRun, nullptr);

    sleep(5);
    pthread_exit(nullptr);
    return 0;
}

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
//     pthread_cancel(pthread_self()); // 取消线程
//     printf("Thread new quit!\n");
// }

// int main()
// {
//     pthread_t tid;
//     pthread_create(&tid, nullptr, ThreadRun, (void *)"Thread new");

//     sleep(1);            // 保证新线程已经启动

//     void *retval;
//     pthread_join(tid, &retval);
//     printf("Joined with \"%d\"\n", (int*)retval);

//     std::cout << "Main thread exiting.\n";
//     return 0;
// }