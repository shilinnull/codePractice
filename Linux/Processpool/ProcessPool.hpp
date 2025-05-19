#ifndef __PROCESS_POOL_HPP__
#define __PROCESS_POOL_HPP__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <limits.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "Task.hpp"

enum CTRLSUBPROCESS
{
    Polling, // 轮询
    Random   // 随机
};

// 定义回调函数
using callback_t = std::function<void(int fd)>;

// 信道
class Channel
{
public:
    Channel() = default;
    ~Channel() = default;
    Channel(int fd, pid_t id, std::string &name)
        : _wfd(fd), _sub_id(id), _name(name)
    {
    }

    int Fd() { return _wfd; }
    pid_t Id() { return _sub_id; }
    std::string Name() { return _name; }
    void Close() { close(_wfd); }
    void Wait()
    {
        pid_t rid = waitpid(_sub_id, nullptr, 0);
        if (rid < 0)
            std::cerr << "rid fial!" << std::endl;
    }

private:
    int _wfd;
    pid_t _sub_id;
    std::string _name;
};

class ProcessPool
{
public:
    ProcessPool(int sub_num)
        : _sub_num(sub_num)
    {
        srand(time(0) ^ getpid() ^ 17777);
    }
    ~ProcessPool()
    {
        // 等待子进程
        WaitSubProcesses();
    }

    // 初始化进程池
    bool InitProcessPool(callback_t cb)
    {
        for (int i = 0; i < _sub_num; i++)
        {
            // 创建管道
            int pipefd[2] = {0};
            int n = pipe(pipefd);
            if (n < 0)
                return false;

            // 创建子进程
            pid_t id = fork();
            if (id < 0)
                return false;
            if (id == 0)
            {
                ///////////////////// child----read
                // 关闭写
                close(pipefd[1]);

                // 子进程开始干活
                cb(pipefd[0]);

                exit(0); // 子进程退出
            }

            ///////////////////// parent----write
            // 关闭读
            close(pipefd[0]);

            std::string name = "channel:" + std::to_string(i);
            // 创建完后push进vector进行管理
            // _channels.push_back({pipefd[1], id, name});
            _channels.emplace_back(pipefd[1], id, name);
        }
        return true;
    }

    // 控制子进程
    void CtrlSubProcess(enum CTRLSUBPROCESS ctrl_sub_process_mode, int count = INT_MAX)
    {
        if (count < 0)
            return;

        int index = 0;
        // 轮询方式
        if (Polling == ctrl_sub_process_mode)
        {
            // 轮询选择一个信道
            while (count--)
            {
                index %= _channels.size(); // 防止越界
                CtrlSubProcessHelper(index);
                index++;
            }
        }
        else if (Random == ctrl_sub_process_mode) // 随机方式
        {
            while (count--)
            {
                index = (rand() ^ getpid() ^ 17777) % _channels.size();
                CtrlSubProcessHelper(index);
            }
        }
        else
        {
        }
    }

private:
    // 随机选择一个信道，然后让子进程执行任务
    void CtrlSubProcessHelper(int index)
    {
        // 随机选择一个任务
        int x = rand() % tasks.size();
        // 让子进程执行任务
        std::cout << "选择信道: " << _channels[index].Name() << ", sub_id : " << _channels[index].Id() << std::endl;

        // 进行唤醒子进程，给管道写入子进程要执行的tasks的下标-->一个整数，然后让子进程读取到下标后，执行任务！
        write(_channels[index].Fd(), &x, sizeof(x));
        sleep(1); // 一秒执行一个任务
    }

    // 需要注意！！！
    void WaitSubProcesses()
    {
        // 方法三：就顺序关闭，但是需要在创建子进程的时候关闭多余的写端
        // for(auto& c: _channels)
        // {
        //     c.Close();
        //     c.Wait();
        // }

        // 方法二：倒着关闭
        for (int i = _channels.size() - 1; i >= 0; i--)
        {
            _channels[i].Close();
            _channels[i].Wait();
        }

        // 方法一：先全部关闭管道写，然后进行等待子进程
        // for(auto& c : _channels)
        // {
        //     c.Close();
        // }
        // for(auto& c : _channels)
        // {
        //     c.Wait();
        // }
    }

private:
    std::vector<Channel> _channels; // 所有的信道
    int _sub_num;                   // 子进程的数量
};

#endif