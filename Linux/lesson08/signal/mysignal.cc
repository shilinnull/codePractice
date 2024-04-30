#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

void Usage(std::string proc)
{
    std::cout << "Usage:\n\t" << proc << "signum pid\n"
              << std::endl;
}

void myhandler(int sig)
{
    std::cout << "process get a signal " << sig << std::endl;
}

int main()
{
    // signal(2, myhandler);

    signal(SIGABRT, myhandler);
    int cnt = 0;
    while (true)
    {
        std::cout << "I am a process, pid: " << getpid() << std::endl;
        sleep(1);
        cnt++;
        if (cnt % 2 == 0)
        {
            // kill(getpid(), 2);
            // raise(2); // 给自己发信号
            // abort();  // 6号信号,自己会退出 = kill(getpid(), 6); // 但是在外面发kill -6 pid 就不会退出
        }
    }

    return 0;
}

// void Usage(std::string proc)
// {
//     std::cout << "Usage:\n\t" << proc << "signum pid\n"
//          << std::endl;
// }

// // mykill signal pid
// int main(int argc, char*argv[])
// {
//     if(argc != 3)
//     {
//         Usage(argv[0]);
//         exit(-1);
//     }

//     int signum = atoi(argv[1]);
//     pid_t pid = atoi(argv[2]);

//     int n = kill(pid,signum);
//     if(n < 0)
//     {
//         perror("kill");
//         exit(-2);
//     }

//     return 0;
// }

// void myhandler(int sig)
// {
//     std::cout << "process get a signal " << sig << std::endl;
// }

// int main()
// {
//     // 只要设置了一次，后面都有效
//     signal(SIGINT, myhandler); // 2号信号  -> ctrl + '\'
//     // 信号的产生，和我们自己的代码运行是异步的
//     signal(SIGQUIT, myhandler); // 3号信号 -> ctrl + '\'
//     signal(SIGSTOP, myhandler); // 19号信号 -> ctrl + 'z' 不会被捕捉

//     // 看看哪个信号可以被捕捉
//     for (int i = 0; i < 31; i++)
//     {
//         signal(i, myhandler);
//     }

//     while (true)
//     {
//         std::cout << "I am a crazy process : " << getpid() << std::endl;
//         sleep(1);
//     }
//     return 0;
// }
