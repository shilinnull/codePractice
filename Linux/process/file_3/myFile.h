#ifndef __MYSTDIO_H__
#define __MYSTDIO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 1024
#define MODE 0666

// 缓冲区模式
enum FLUSH
{
    FLUSH_NONE,
    FLUSH_LINE,
    FLUSH_FULL,

    IS_FLUSH_FORCE,
    IS_FLUSH_NORMAL
};

typedef struct My_FILE
{
    int fileno;             // 文件描述符
    unsigned int flags;      // 缓冲区模式 
    char cache[SIZE];
    int cap;               // 容量
    int curr;              // 当前位置
} myFILE;


myFILE* my_fopen(const char* filename, const char* mode);

void my_fflush(myFILE* fp);

ssize_t my_write(const char* s, int size, myFILE* fp);

void my_close(myFILE* fp);


#endif
