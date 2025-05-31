#include "NamedPipe.hpp"

int main()
{
    // server端创建管道
    NamedPipe named_pipe(filename, Creater);
    bool ret = named_pipe.OpenForRead(); // 打开管道文件，进行读
    if (!ret)
        exit(2);

    // 读
    std::string message;
    while (true)
    {
        bool ret = named_pipe.Read(&message);
        if (!ret)
            break;
        std::cout << "client say@" << message << "\n";
    }

    return 0;
}