#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>

using namespace std;

// 信号为什么会一直被触发？？
void handler(int signo)
{
    cout << "...get a sig, pid: "<< getpid() << " number: " << signo << endl; // 只是打印了消息
    sleep(1);
}

int main()
{
    signal(SIGFPE /*8*/, handler);
    signal(SIGSEGV /*11*/, handler);
    cout << "point error before" << endl;

    int *p = nullptr;
    *p = 100; // 野指针

    // int a = 10;
    // a /= 0; // 异常

    cout << "point error before" << endl;
    sleep(1);

    return 0;
}