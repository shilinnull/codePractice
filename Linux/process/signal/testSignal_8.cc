#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void handler(int signo)
{
    cout << "catch a signo: " << signo << endl;
}


void printPending(sigset_t& pending)
{
    for(int i = 31;i > 0;i--)
    {
        if(sigismember(&pending, i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main()
{
    signal(2, handler);
    sigset_t block, oblock;
    sigemptyset(&block);
    sigemptyset(&oblock);
    
    // 添加信号
    sigaddset(&block, SIGINT);
    // 使用系统调用，将数据设置进内核
    sigprocmask(SIG_SETMASK, &block, &oblock);
    
    sigset_t pending;
    sigemptyset(&pending);

    while(true)
    {
        sigpending(&pending);
        printPending(pending);
        sleep(1);
    }


    return 0;
}