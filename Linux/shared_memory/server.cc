#include "shm.hpp"


int main()
{
    // 创建共享内存
    SharedMemory shm(Creater);

    // server--->read  通信
    char c;
    while (true)
    {
        shm.PopChar(&c);
        putchar(c);
        fflush(stdout);
        if(c == 'Z')  break;
        sleep(1);
    }

    sleep(2);
    return 0;
}
