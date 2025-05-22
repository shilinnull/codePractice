#include "shm.hpp"


int main()
{
    // 创建共享内存
    SharedMemory shm(User);

    // server--->write  通信
    for(char ch = 'A'; ch <= 'Z'; ch++)
    {
        shm.PushChar(ch);
        sleep(1);
    }

    return 0;
}