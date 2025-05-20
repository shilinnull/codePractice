#include "ProcessPool.hpp"


void sub_execute_task(int fd)
{
    while (true)
    {
        // 子进程执行任务
        int index = 0; // 执行任务的下标
        ssize_t n = read(fd, &index, sizeof(index)); // 从管道中读父进程给我要执行任务的下标
        if (n == sizeof(index)) // 如果读取成功了
        {
            std::cout << "子进程被唤醒: " << getpid() << std::endl;
            if (index >= 0 && index < tasks.size()) // 需要保持在tasks的范围内
                tasks[index](); // 执行任务
            else
                std::cerr << "父进程给我的任务码是不对的: " << index << std::endl;
        }
        else if (n == 0)
        {
            // 子进程读到0后就会自动退出
            std::cout << "子进程应该退出了: " << getpid() << std::endl;
            break;
        }
        else
        {
            std::cerr << "read fd: " << fd << ", error" << std::endl;
            break;
        }
    }
}

int main()
{
    // 创建子进程，5个子进程
    ProcessPool pp(5);

    // 初始化进程池
    pp.InitProcessPool([](int fd){ sub_execute_task(fd); });

    // 父进程控制子进程    第一个参数是控制方式，第二个参数是让子进程执行多少次
    // pp.CtrlSubProcess(Polling); // 轮询方式控制
    pp.CtrlSubProcess(Random, 10); // 随机方式控制

    std::cout << "父进程控制子进程完成，父进程结束" << std::endl;
    return 0;
}