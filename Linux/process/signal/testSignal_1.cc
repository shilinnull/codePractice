#include <iostream>
#include <signal.h>
#include <unistd.h>

void myhandler(int sig)
{
    std::cout << "process get a signal " << sig << std::endl;
}

int main()
{
    // 看看哪个信号可以被捕捉
    for (int i = 0; i < 31; i++)
    {
        signal(i, myhandler);
    }

    while (true)
    {
        std::cout << "I am a crazy process : " << getpid() << std::endl;
        sleep(1);
    }
    return 0;
}