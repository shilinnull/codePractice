#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

void *my_malloc(size_t size)
{
    void *ptr = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
    {
        return nullptr;
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr, size_t size)
{
    int n = munmap(ptr, size);
    if (n == -1)
    {
        perror("munmap");
        exit(2);
    }
}

int main()
{
    // 创建
    char *ptr = (char *)my_malloc(1024);
    if (ptr == nullptr)
    {
        perror("ptr");
        return 1;
    }

    // 使用
    for (int i = 0; i < 1024; i++)
    {
        ptr[i] = 'A';
    }
    printf(ptr);

    my_free(ptr, 1024);
    return 0;
}