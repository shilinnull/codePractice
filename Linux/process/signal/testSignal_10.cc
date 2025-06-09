#include <iostream>
#include <signal.h>
#include <unistd.h>
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
    signal(SIGCHLD /*17*/, SIG_IGN); // SIG_DFL -> action -> IGN
    // signal(SIGCHLD /*17*/, handler);
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