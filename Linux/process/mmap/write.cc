#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SIZE 4096

int main(int args, char *argv[])
{
    if (args != 2)
    {
        std::cerr << "Usage: " << argv[0] << "filename" << std::endl;
        return 1;
    }

    // 1. 打开文件
    int fd = open(argv[1], O_TRUNC | O_CREAT | O_RDWR, 0666); // 要进行写
    if (fd < 0)
    {
        std::cerr << "open error" << std::endl;
        return 2;
    }

    // 2. 默认文件大小是0，无法和mmap进行正确映射，这里需要调整文件大小，用0值填充
    ftruncate(fd, SIZE);

    // 3. 建立映射
    char *mmapAddr = (char *)mmap(nullptr, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mmapAddr == MAP_FAILED)
    {
        perror("mmap");
        return 3;
    }

    // 4. 操作文件
    for (int i = 0; i < 10; i++)
    {
        mmapAddr[i] = 'A';
    }

    // 5. 取消映射关闭文件
    int n = munmap(mmapAddr, SIZE);
    if(n < 0)
    {
        std::cerr << "munmap failed!" << std::endl;
        return 5;
    }
    close(fd);

    return  0;
}