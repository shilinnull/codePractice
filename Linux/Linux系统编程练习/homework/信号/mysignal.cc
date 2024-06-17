#include <iostream>
#include <signal.h>
#include <string.h>
#include <unistd.h>
using namespace std;

/*
1.考察对信号阻塞的理解， 考察对可靠信号和非可靠信号的理解，考察sigprocmask函数的使用
2.要求：阻塞2号信号和40号信号， 分别给进程发送5次2号信号和5次40号信号，观察结果
*/

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
    cout << endl;
}

int main()
{
    // 1. 对2,40号信号进行捕捉
    signal(2, handler);
    signal(40, handler);

    // 2. 对信号进行屏蔽
    sigset_t bset, oset;
    sigemptyset(&bset);
    sigemptyset(&oset);
    sigaddset(&bset, 2);  // 将2号信号添加
    sigaddset(&bset, 40); // 将40号信号添加

    // 3. 使用系统调用，将数据设置进内核
    sigprocmask(SIG_SETMASK, &bset, &oset);

    // 4. 重复打印当前进程的pending
    sigset_t pending;
    while (true)
    {
        int n = sigpending(&pending);
        // 4.1 打印
        PrintPending(pending);
        sleep(1);
    }

    return 0;
}

/*
1.考察对于信号处理方式的理解， 考察sigaction函数的使用
2.要求：自定义处理函数名称为“sigcb”, 在sigcb当中完成打印信号值
*/

// void sigcb(int signa)
// {
//     std::cout << "process get a signal : " << signa << std::endl;
// }

// int main()
// {
//     struct sigaction act;
//     memset(&act, 0, sizeof(act));

//     act.sa_handler = sigcb; // 设置处理方法
//     sigaction(2, &act, nullptr); // 捕捉19号信号

//     while (1)
//         ;
//     return 0;
// }

/*
1.考察对于信号处理方式的理解， 考察signal函数的使用
2.要求：自定义处理函数名称为“sigcb”, 在sigcb当中完成打印触发本次事件的信号值
*/

// void sigcb(int signa)
// {
//     std::cout << "process get a signal : " << signa << std::endl;
// }

// int main()
// {
//     signal(SIGINT, sigcb);
//     while (1)
//         ;

//     return 0;
// }