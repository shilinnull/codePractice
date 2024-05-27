#include <iostream>
#include <cstdio>
#include <cerrno>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 写
int main()
{
    int _fd = open("./myfifo", 0666);
    std::cout << "Please Enter> ";
    std::string message;

    std::getline(std::cin, message);

    write(_fd, message.c_str(), message.size());

    return 0;
}