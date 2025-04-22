#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
    umask(0);
    // O_WRONLY 代表只写，如果没有该文件就创建，O_CREAT代表创建文件
    // 如果不指定创建文件的权限就会乱码
    int fd = open("log.txt", O_WRONLY | O_CREAT |  O_APPEND, 0666);
    // int fd = open("log.txt", O_RDONLY);
    if(fd < 0)
    {
        printf("fopen fail!\n");
        exit(1);
    }
    const char* s = "heheehhello world";
    write(fd, s, strlen(s));

    // char a[128] = {0};
    // read(fd, a, sizeof(a) - 1);
    // printf("%s",a);;
    close(fd);
    return 0;
}
