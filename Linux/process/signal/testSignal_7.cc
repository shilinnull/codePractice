#include <iostream>
#include <unistd.h>
#include <signal.h>

long long count = 0;
void handler(int signumber)
{
    std::cout << "count : " << count << std::endl;
    exit(0);
}
int main()
{
    signal(SIGALRM, handler);
    alarm(1);
    while (true)
    {
        count++;
    }
    return 0;
}

// int main()
// {
//     int count = 0;
//     alarm(1);
//     while (true)
//     {
//         std::cout << "count : " << count << std::endl;
//         count++;
//     }
//     return 0;
// }