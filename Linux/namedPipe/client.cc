#include "NamedPipe.hpp"

int main()
{
    // client端只进行写
    NamedPipe named_pipe(filename, USER);
    bool ret = named_pipe.OpenForWrite(); // 打开管道文件，进行写
    if (!ret)
        exit(2);

    // 写
    while (true)
    {
        std::cout << "Please Enter# ";
        std::string line;
        std::getline(std::cin, line);
        named_pipe.Write(line);
    }

    return 0;
}