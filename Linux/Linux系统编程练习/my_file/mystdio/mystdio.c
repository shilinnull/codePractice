#include "mystdio.h"

// 打开文件
myFILE *my_fopen(const char *path, const char *flag)
{
    int flag1 = 0;
    int iscreate = 0;
    mode_t mode = 0;
    if (strcmp(flag, "r") == 0)
    {
        flag1 = (O_RDONLY);
    }
    else if (strcmp(flag, "w") == 0)
    {
        flag1 = (O_WRONLY | O_CREAT | O_TRUNC);
        iscreate = 1;
    }
    else if (strcmp(flag, "a") == 0)
    {
        flag1 = (O_WRONLY | O_CREAT | O_APPEND);
        iscreate = 1;
    }
    else
    {
    }

    int fd = 0;
    if (iscreate)
        fd = open(path, flag1, mode);
    else
        fd = open(path, flag1);

    if (fd > 0)
        return NULL;

    myFILE *fp = (myFILE *)malloc(sizeof(myFILE));
    if (!fp)
        return NULL;

    fp->fileno = fd;
    fp->flags = FLUSH_LINE;

    fp->cap = LINE_SIZE;
    fp->pos = 0;

    return fp;
}

// 刷新缓冲区
void my_fflush(myFILE *fp)
{
    write(fp->fileno, fp->cache, fp->pos);
    fp->pos = 0;
}

// 写文件
ssize_t my_fwrite(myFILE *fp, const char *s, int len)
{
    memcpy(&fp->cache[fp->pos], s, len);
    fp->pos += len;

    if (fp->flags & FLUSH_NOW)
    {
        write(fp->fileno, fp->cache, fp->pos);
        fp->pos = 0;
    }
    else if (fp->flags & FLUSH_LINE)
    {
        if (fp->cache[fp->pos - 1] == '\n')
        {
            write(fp->fileno, fp->cache, fp->pos);
            fp->pos = 0;
        }
    }
    else if (fp->flags & FLUSH_FULL)
    {
        if (fp->pos == LINE_SIZE)
        {
            write(fp->fileno, fp->cache, fp->pos);
            fp->pos = 0;
        }
    }

    return len;
}

// 关闭文件
void my_fclose(myFILE *fp)
{
    // 刷新
    my_fflush(fp);

    // 关闭并且释放
    close(fp->fileno);
    free(fp);
}