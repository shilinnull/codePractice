#include <iostream>
#include <vector>
#include <functional>
#include <csignal>
#include <unistd.h>

using namespace std;

// 定义回调函数类型
using func_t = std::function<void()>;
vector<func_t> cb; // 回调函数列表
unsigned int interval = 3; // 闹钟间隔时间（秒），默认3秒

// 信号处理函数（实现重复闹钟）
void handler(int signo) {
    // 执行所有注册的回调函数
    for (auto& f : cb) {
        f();
    }

    // 重新设置闹钟（实现重复触发）
    unsigned int remaining = alarm(interval); // 返回上一次闹钟剩余时间（若无则为0）
    cout << "===== 信号捕捉函数被调用 =====" << endl
         << "剩余时间：" << remaining << " 秒" << endl
         << "下次触发时间：" << interval << " 秒后" << endl << endl;

    (void)signo; // 避免未使用参数警告
}

// 刷盘操作
void FlushDisk() {
    cout << "【刷盘操作】数据已写入磁盘" << endl;
}

// 进程调度操作
void sched() {
    cout << "【进程调度】正在进行任务调度..." << endl;
}

// 自定义回调函数示例（可扩展）
void customTask() {
    cout << "【自定义任务】这是一个额外的回调函数" << endl;
}

int main() {
    // 注册回调函数
    cb.push_back(FlushDisk);
    cb.push_back(sched);
    // 可添加更多任务：cb.push_back(customTask);

    // 设置信号处理函数
    if (signal(SIGALRM, handler) == SIG_ERR) {
        cerr << "信号注册失败" << endl;
        return 1;
    }

    // 首次设置闹钟
    alarm(interval); // 从现在开始，每`interval`秒触发一次

    cout << "===== 重复闹钟调度程序启动 =====" << endl
         << "当前间隔时间：" << interval << " 秒" << endl
         << "已注册任务数量：" << cb.size() << " 个" << endl << endl;

    // 保持程序运行（等待信号）
    while (true) {
        pause(); // 阻塞进程，直到收到信号
        // 每次信号触发后，`handler`会重新设置闹钟，因此无需手动处理
    }

    return 0;
}

// void handler(int signo)
// {
//     cout << "...get a sig, number: " << signo << endl;
//     sleep(1);
// }

// int main()
// {
//     signal(SIGALRM /*14*/, handler);
//     int n = alarm(5); // 设置闹钟，5秒之后会响

//     while (true)
//     {
//         cout << "proc is running..., pid: " << getpid() << endl;
//         sleep(1);
//     }
// }