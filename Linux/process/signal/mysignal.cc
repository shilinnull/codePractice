#include <iostream>
#include <signal.h>
#include <unistd.h>


int main()
{
    // signal(SIGINT, SIG_DFL);
    // signal(SIGINT, SIG_IGN);

    while (true)
    {
        std::cout << "I am a process, " << getpid() << std::endl;
        sleep(1);
    }

    return 0;
}