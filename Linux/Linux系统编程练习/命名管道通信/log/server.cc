#include "namedPipe.hpp"
#include "log.hpp"

// read -->管理管道文件
int main()
{
    NamePiped fifo(comm_path, Creater);
    Log log;
    // log.Enable(Onefile); // 写到一个文件里
    log.Enable(Classfile); // 写到多个文件里
    if (fifo.OpenForRead())
    {
        std::cout << "server open named pipe done" << std::endl;

        while (true)
        {
            std::string message;
            int n = fifo.ReadNamedPipe(&message);
            if (n > 0)
            {
                log(Info, "Client Input, error string: %s, error code: %d", strerror(errno), errno);
                std::cout << "Client Say> " << message << std::endl;
            }
            else if (n == 0)
            {
                log(Debug, "client quit, me too!, error string: %s, error code: %d", strerror(errno), errno);
                std::cout << "Client quit, Server Too!" << std::endl;
                break;
            }
            else
            {
                log(Fatal, "error string: %s, error code: %d", strerror(errno), errno);
                std::cout << "fifo.ReadNamedPipe Error" << std::endl;
                break;
            }
        }
    }
    return 0;
}