#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <unistd.h>

void myhandler(int sig)
{
    std::cout << "process get a signal " << sig << std::endl;
}

int main()
{
    signal(SIGABRT/*6*/, myhandler);
    int cnt = 0;
    while (true)
    {
        std::cout << "I am a process, pid: " << getpid() << std::endl;
        cnt++;
        if (cnt % 2 == 0)
        {
            // kill(getpid(), 2);
            // raise(2); // 给自己发信号
            abort();
        }
        sleep(1);
    }

    return 0;
}