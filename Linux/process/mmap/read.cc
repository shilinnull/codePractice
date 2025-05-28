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
    int fd = open(argv[1], O_RDONLY); // 要进行读
    if (fd < 0)
    {
        std::cerr << "open error" << std::endl;
        return 2;
    }

    // 2. 获取文件真实大小
    struct stat st;
    fstat(fd, &st);

    // 3. 建立映射
    char *mmapAddr = (char *)mmap(nullptr, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (mmapAddr == MAP_FAILED)
    {
        perror("mmap");
        return 3;
    }

    // 4. 操作文件
    std::cout << mmapAddr << std::endl;

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