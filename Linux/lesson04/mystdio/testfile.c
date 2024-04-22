#include "mystdio.h"

#define FILE_NAME "log.txt"

int main()
{
    myFILE *fp = my_fopen(FILE_NAME, "w");
    if (fp == NULL)
        return 1;

    const char *str = "hello bit";
    int cnt = 10;
    char buffer[128];
    while (cnt)
    {
        sprintf(buffer, "%s - %d", str, cnt);
        my_fwrite(fp, buffer, strlen(buffer));
        cnt--;
        sleep(1);
        my_fflush(fp);
    }

    my_fclose(fp);
    return 0;
}
