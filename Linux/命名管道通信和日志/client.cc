#include "Shm.hpp"
#include "Log.hpp"
#include "namedPipe.hpp"

int main()
{
    // 1. 创建共享内存
    Shm shm(gpathname, gproj_id, gUser);
    shm.Zero(); // 清空共享内存
    char *shmaddr = (char *)shm.Addr();

    // 打印信息
    shm.DebugShm();

    // 2. 打开管道
    NamePiped fifo(comm_path, User);
    fifo.OpenForWrite();

    // 当成string
    char ch = 'A';
    while (ch <= 'Z')
    {
        shmaddr[ch - 'A'] = ch;

        std::string temp = "wakeup";
        std::cout << "add " << ch << " into Shm, "
                  << "wakeup reader" << std::endl;
        fifo.WriteNamedPipe(temp);
        sleep(2);
        ch++;
    }

    return 0;
}

