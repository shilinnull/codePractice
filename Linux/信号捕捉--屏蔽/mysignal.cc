#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

void handler(int signo)
{
    cout << "catch a signo: " << signo << endl;
}

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
    cout << endl
         << endl;
}

int main()
{
    // 尝试将所有信号进行屏蔽
    sigset_t bset, oset;
    sigemptyset(&bset);
    sigemptyset(&oset);
    for (size_t i = 1; i < 31; i++)
    {
        sigaddset(&bset, i);
    }
    sigprocmask(SIG_SETMASK, &bset, &oset);

    // 打印
    sigset_t pending;
    while (true)
    {
        int n = sigpending(&pending);
        if (n < 0)
            continue;
        PrintPending(pending);
        sleep(1);
    }

    return 0;
}

// int main()
// {
//     // 1. 对2号信号进行捕捉
//     signal(2, handler);

//     // 2. 对信号进行屏蔽
//     sigset_t bset, oset;
//     sigemptyset(&bset);
//     sigemptyset(&oset);
//     sigaddset(&bset, 2); // 将2号信号添加

//     // 3. 使用系统调用，将数据设置进内核
//     sigprocmask(SIG_SETMASK, &bset, &oset);

//     // 4. 重复打印当前进程的pending
//     sigset_t pending;
//     int cnt = 0;
//     while (true)
//     {
//         int n = sigpending(&pending);
//         if (n < 0)
//             continue;
//         // 4.1 打印
//         PrintPending(pending);
//         sleep(1);
//         cnt++;

//         // 4.2 解除阻塞
//         if (cnt == 20)
//         {
//             cout << "unblock 2 signo" << endl;
//             sigprocmask(SIG_SETMASK, &oset, nullptr);
//         }
//     }

//     return 0;
// }

// int main()
// {
//     // signal(2, SIG_IGN);// 对2号信号屏蔽
//     signal(2, SIG_ERR); // 对2号信号默认

//     while (true)
//     {
//         std::cout << "hello" << std::endl;
//         sleep(1);
//     }

//     return 0;
// }