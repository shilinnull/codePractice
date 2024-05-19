#include <iostream>
#include <cstring>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void handler(int signo)
{
    sleep(5);
    pid_t rid;
    while ((rid = waitpid(-1, nullptr, WNOHANG)) > 0) // 等待任意子进程
    {
        cout << "I am proccess: " << getpid() << " catch a signo: " << signo << "child process quit: " << rid << endl;
    }
}

int main()
{
    signal(17, SIG_IGN); // SIG_DFL -> action -> IGN

    //srand(time(nullptr));
    //signal(17, handler);
    for (int i = 0; i < 10; i++)
    {
        pid_t id = fork();
        if (id == 0)
        {
            while (true)
            {
                cout << "I am child process: " << getpid() << ", ppid: " << getppid() << endl;
                sleep(5);
                break;
            }
            cout << "child quit!!!" << endl;
            exit(2);
        }
        //sleep(rand()%5+3);
        sleep(1);
    }
    // father
    while (true)
    {
        cout << "I am father process: " << getpid() << endl;
        sleep(1);
    }

    return 0;
}

// volatile int flag = 0;

// void handler(int signo)
// {
//     std::cout << "catch a signal: " << signo << std::endl;
//     flag = 1;
// }

// int main()
// {

//     signal(2, handler);

//     while (!flag)
//         ; // 真
//     std::cout << "process quit normal" << std::endl;

//     return 0;
// }

// void PrintPending()
// {
//     sigset_t set;
//     sigpending(&set);

//     for (int signo = 31; signo >= 1; signo--)
//     {
//         if (sigismember(&set, signo))
//             std::cout << "1";
//         else
//             std::cout << "0";
//     }
//     std::cout << std::endl;
// }

// void handler(int signo)
// {
//     std::cout << "catch a signal, signal number" << signal << std::endl;
//     while (true)
//     {
//         PrintPending();
//         sleep(1);
//     }
// }

// int main()
// {
//     struct sigaction act, oact;
//     memset(&act, 0, sizeof(act));
//     memset(&oact, 0, sizeof(act));

//     sigemptyset(&act.sa_mask);
//     // 将1 3 4 信号也同时屏蔽
//     sigaddset(&act.sa_mask, 1);
//     sigaddset(&act.sa_mask, 3);
//     sigaddset(&act.sa_mask, 4);

//     act.sa_handler = handler;
//     sigaction(2, &act, &oact); // 捕捉2号

//     while (true)
//     {
//         std::cout << "I am a process " << getpid() << std::endl;
//         sleep(1);
//     }

//     return 0;
// }