#include "shm.hpp"
#include "namedPipe.hpp"

int main()
{
    Shm shm("/root/111/code-exercise/Linux/homework/共享内存/shm.hpp", 0x666, gCreater);
    char *shmaddr = (char *)shm.Addr();

    // 创建管道
    NamePiped fifo("./fifo", Creater);
    fifo.OpenForRead();

    std::string temp;
    fifo.ReadNamedPipe(&temp);
    std::cout << temp << std::endl;

    return 0;
}