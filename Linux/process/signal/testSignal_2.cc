#include <iostream>
#include <cstdio>
#include <signal.h>
#include <unistd.h>

// mykill signal pid
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << "signum pid\n" << std::endl;
        exit(-1);
    }

    int signum = atoi(argv[1]);
    pid_t pid = atoi(argv[2]);

    int n = kill(pid, signum);
    if (n < 0)
    {
        perror("kill");
        exit(-2);
    }

    return 0;
}