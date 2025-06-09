#include <iostream>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void PrintPending()
{
    sigset_t pending;
    sigpending(&pending);

    for (int signo = 31; signo >= 1; signo--)
    {
        if (sigismember(&pending, signo))
            std::cout << "1";
        else
            std::cout << "0";
    }
    std::cout << std::endl;
}

void handler(int signo)
{
    std::cout << "catch a signal, signal number" << signal << std::endl;
    while (true)
    {
        PrintPending();
        sleep(1);
    }
}

int main()
{
    struct sigaction act, oact;
    memset(&act, 0, sizeof(act));
    memset(&oact, 0, sizeof(oact));

    act.sa_handler = handler;
    act.sa_flags = 0;
    sigemptyset(&(act.sa_mask));

    
    sigaction(2, &act, &oact); // 将2号信号的捕捉方法，设置到内核中！

    while (true)
    {
        std::cout << "I am a process " << getpid() << std::endl;
        sleep(1);
    }

    return 0;
}