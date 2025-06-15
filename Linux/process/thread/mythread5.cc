#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
using namespace std;

#define get_lwp_id() syscall(SYS_gettid)

__thread int lwpid;

void *PthreadRun(void *args)
{
    lwpid = get_lwp_id();
    int cnt = 0;
    while (true)
    {
        cout << "new Thread, cnt = " << cnt << " lwpid: " << lwpid << endl;
        cnt++;
        sleep(1);
    }
    return nullptr;
}

int main()
{
    lwpid = get_lwp_id();

    pthread_t tid;
    pthread_create(&tid, nullptr, PthreadRun, nullptr);
    sleep(1);
    cout << "main Thread, lwpid: " << lwpid << endl;

    pthread_join(tid, nullptr); // 等待线程
    return 0;
}