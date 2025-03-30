#include "ProcessBar.h"

#define LIGHT_CYAN   "\033[1;36m" // 亮青色
#define NONE "\033[m" 	//截断

// 显示进度
const char* lable = "|/-\\";

void ProcBar(double total, double current)
{
    char bar[Length];
    // 初始化进度条
    memset(bar, '\0', sizeof(bar));
    int len = strlen(lable);

    int cnt = 0;
    double rate = (current * 100.0) / total;
    // 循环次数
    int loop_count = (int)rate;
    while (cnt < loop_count)
    {
        bar[cnt++] = Style;
        if (rate < 100)
            bar[loop_count] = TAIL;
    }
    // 打印显示
    printf(LIGHT_CYAN"[%-100s]"NONE"[%.2lf%%][%c]\r", bar, rate, lable[cnt % len]);
    // 刷新缓冲区
    fflush(stdout);
}
