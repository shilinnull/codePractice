#include "shm.hpp"
#include "namedPipe.hpp"

int main()
{
    // 创建
    Shm shm("/root/111/code-exercise/Linux/homework/共享内存/shm.hpp", 0x666, gUser);
    shm.Zero();

    char *shmaddr = (char *)shm.Addr();

    NamePiped fifo("./fifo", User);
    fifo.OpenForWrite();

    string buffer;
    while (getline(cin, buffer))
    {
        fifo.WriteNamedPipe(buffer);
        buffer.clear();
    }

    return 0;
}