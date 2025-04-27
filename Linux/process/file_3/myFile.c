#include "myFile.h"

myFILE* my_fopen(const char* filename, const char* mode)
{
    int flag = 0;
    int iscreate = 0;
    if(strcmp(mode, "r") == 0)
    {
        flag = (O_RDONLY);
    }
    else if(strcmp(mode, "w") == 0)
    {
        flag = (O_WRONLY | O_CREAT | O_TRUNC);
        iscreate = 1;
    }
    else if(strcmp(mode, "a") == 0)
    {
        flag = (O_WRONLY | O_CREAT | O_APPEND);
        iscreate = 1;
    }
    else
    {}

    int fd = 0;
    if(iscreate)
        fd = open(filename, flag, MODE);
    else
        fd = open(filename, flag);

    if(fd < 0)
        return NULL;
    // 创建FILE
    myFILE* fp = (myFILE*)malloc(sizeof(myFILE)); 
    if(!fp) return NULL; 

    fp->fileno = fd;
    fp->flags = FLUSH_LINE;
    fp->curr = 0;
    fp->cap = SIZE;
    
    return fp;
}

static void my_fflush_core(myFILE* fp, int is_flush)
{
    if(fp->curr < 0)
        return;
    // 强制刷新
    if(is_flush == IS_FLUSH_FORCE)
    {
        write(fp->fileno, fp->cache, fp->curr);
        fp->curr = 0;
    }
    else 
    {
        if(fp->flags == FLUSH_LINE && fp->cache[fp->curr - 1] == '\n')
        {
            write(fp->fileno, fp->cache, fp->curr);
            fp->curr = 0;
        }
        else if(fp->flags == FLUSH_FULL && fp->curr == fp->cap)
        {
            write(fp->fileno, fp->cache, fp->curr);
            fp->curr = 0;
        }
        else 
        {}
    }
}

void my_fflush(myFILE* fp)
{
    my_fflush_core(fp, IS_FLUSH_FORCE);
}

ssize_t my_write(const char* s, int size, myFILE* fp)
{
    memcpy(fp->cache + fp->curr, s, size);
    fp->curr += size;
    my_fflush_core(fp, IS_FLUSH_NORMAL);
    return size;
}

void my_close(myFILE* fp)
{
    if(fp->fileno >= 0)
    {
        my_fflush(fp);
        fsync(fp->fileno);
        close(fp->fileno);
        free(fp);
    }
}

