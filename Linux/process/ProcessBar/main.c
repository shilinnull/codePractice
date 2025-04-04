#include "ProcessBar.h"

// 网络带宽【1mb】
double bandwidth = 1024 * 1024 * 1.0;

void download(double filesize, callback_t cb)
{
    //  累计下载的数据量
    double current = 0.0;
    printf("download begin, current: %lf\n", current);
    while (current <= filesize)
    {
        // 使用函数指针更新界面
        cb(filesize, current);
        //从网络中获取数据
    //......
    
    // 睡眠
        usleep(100000);

        // 累计下载
        current += bandwidth;
    }
    printf("\ndownload done, filesize: %lf\n", filesize);
}

int main()
{
    // 测试调用
    //download(100 * 1024 * 1024, ProcBar);
    download(2 * 1024 * 1024, ProcBar);
    //download(200*1024*1024,ProcBar);
    //download(400*1024*1024,ProcBar);
    download(50*1024*1024,ProcBar);
    download(10*1024*1024,ProcBar);

    // 测试
    //ProcBar(100.0, 56.9);
    //ProcBar(100.0, 1.0);
    //ProcBar(100.0, 99.9);
    //ProcBar(100.0, 100);
    return 0;
}
