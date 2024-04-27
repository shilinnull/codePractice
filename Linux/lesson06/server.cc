#include "namedPipe.hpp"


// 读read
int main()
{
    // 对于读端而言,如果我们打开文件，但是写还没来，我会阻塞在open调用中，直到对方打开
    // 也就是相当于进程同步
    NamePiped fifo(comm_path, Creater);
    if (fifo.OpenForRead())
    {
        std::cout << "server open named pipe done" << std::endl;
        sleep(3);
        while (true)
        {
            std::string message;
            int n = fifo.ReadNamedPipe(&message);
            if (n > 0)
            {
                std::cout << "Client Say> " << message << std::endl;
            }
            else if (n == 0)
            {
                std::cout << "Client quit, Server Too!" << std::endl;
                break;
            }
            else
            {
                std::cout << "fifo.ReadNamedPipe Error" << std::endl;
                break;
            }
        }
    }

    return 0;
}