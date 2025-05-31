#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <signal.h>
#include <unistd.h>

using namespace std;

void handler(int signumber)
{
    std::cout << "获取了一个信号: " << signumber << std::endl;
}

int main()
{
    signal(2, handler); // 先对2号信号进行捕捉
    // 每隔1S，自己给自己发送2号信号
    while (true)
    {
        sleep(1);
        raise(2);
    }
}