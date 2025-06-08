#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void PrintPending(sigset_t &pending)
{
    for (int signo = 31; signo >= 1; signo--)
    {
        if (sigismember(&pending, signo))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << " I am pid: " << getpid();
    cout << endl;
}

void handler(int signo)
{
    cout << "catch a signo: " << signo << endl;
    // 在这里再打印pending
    sigset_t pending;
    sigemptyset(&pending);
    // 2.1 获取当前进程的pending信号集
    sigpending(&pending);

    // 2.2 不断打印所有的pending信号集中的信号
    std::cout << "###########################" << std::endl;
    PrintPending(pending);
    std::cout << "###########################" << std::endl;
}

int main()
{
    // 1. 对2号信号进行捕捉
    signal(2, handler);

    // 2. 对信号进行屏蔽
    sigset_t bset, oset;
    sigemptyset(&bset);
    sigemptyset(&oset);
    sigaddset(&bset, 2); // 将2号信号添加

    // 3. 使用系统调用，将数据设置进内核
    sigprocmask(SIG_SETMASK, &bset, &oset);

    // 4. 重复打印当前进程的pending
    sigset_t pending;
    sigemptyset(&pending);
    int cnt = 0;
    while (true)
    {
        int n = sigpending(&pending);
        if (n < 0)
            continue;
        // 4.1 打印
        PrintPending(pending);
        sleep(1);
        cnt++;

        // 4.2 解除阻塞
        if (cnt == 10)
        {
            cout << "unblock 2 signo" << endl;
            sigprocmask(SIG_SETMASK, &oset, nullptr);
        }
    }

    return 0;
}