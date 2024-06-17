#include <iostream>
#include <cstdio>
#include <cerrno>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 读
int main()
{
    mkfifo("./myfifo", 0666);
    char buffer[1024];
    int _fd = open("./myfifo", 0666);
    int n = read(_fd, buffer, sizeof(buffer));
    if (n > 0)
    {
        buffer[n] = 0;
        std::cout << buffer << std::endl;
    }

    unlink("./myfifo");
    return 0;
}