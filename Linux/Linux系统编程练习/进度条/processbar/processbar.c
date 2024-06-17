#include "processbar.h"
#include <string.h>
#include <unistd.h>

const char *lable="|/-\\";
char bar[NUM];

#define GREEN "\033[0;32;32m"
#define NONE "\033[m"

// v2: 是如何被调用的
void processbar(int rate)
{
    if(rate < 0 || rate > 100) return;

    int len = strlen(lable);
    printf(GREEN"[%-100s]"NONE"[%d%%][%c]\r", bar, rate, lable[rate%len]); // 没有\n,就没有立即刷新，因为显示器模式是行刷新
    fflush(stdout);
    bar[rate++] = BODY;
    if(rate < 100) bar[rate] = RIGHT;
}

void initbar()
{
    memset(bar, '\0', sizeof(bar));
}
