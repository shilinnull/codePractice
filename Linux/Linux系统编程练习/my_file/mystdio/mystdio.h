#pragma once
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LINE_SIZE 1024
#define FLUSH_NOW 1
#define FLUSH_LINE 2
#define FLUSH_FULL 4

typedef struct _myFile
{
    size_t flags;
    int fileno;
    // 缓冲区
    char cache[LINE_SIZE];
    int cap;
    int pos; // 下次写入的位置
} myFILE;

// 打开文件
myFILE *my_fopen(const char *path, const char *flag);

// 刷新缓冲区
void my_fflush(myFILE *fp);

// 写文件
ssize_t my_fwrite(myFILE *fp, const char *data, int len);

// 关闭文件
void my_fclose(myFILE *fp);
