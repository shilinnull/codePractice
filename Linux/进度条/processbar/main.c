#include "processbar.h"
#include <unistd.h>

typedef void (*callback_t)(int); // 函数指针类型

// 模拟一种安装或者下载
void downLoad(callback_t cb)
{
    int total = 1000; // 1000MB
    int curr = 0;     // 0MB
    while(curr <= total)
    {
        // 进行着某种下载的任务, 我们没学
        usleep(50000);  // 模拟下载花费的时间
        int rate = curr*100/total; // 更新进度

        cb(rate); // 通过回调，展示进度

        curr += 10;     // 循环下载了一部分
    }
    printf("\n");
}

int main()
{
    printf("donwnload 1: \n");
    downLoad(processbar);
    initbar();
    printf("donwnload 2: \n");
    downLoad(processbar);
    initbar();
    printf("donwnload 3: \n");
    downLoad(processbar);
    initbar();
    printf("donwnload 4: \n");
    downLoad(processbar);
    initbar();
    return 0;
}
