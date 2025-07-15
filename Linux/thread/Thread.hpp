#ifndef __THREAD_HPP__
#define __THREAD_HPP__

#include <iostream>
#include <functional>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

#define get_lwp_id() syscall(SYS_gettid);

using func_t = std::function<void()>;
const std::string threadNameFault = "None-Name";

class Thread
{
private:
    static void *startRun(void *args) // 这里要使用statis否则会有隐含的this指针
    {
        Thread *self = static_cast<Thread *>(args);
        self->_isRuning = true;
        self->_lwpid = get_lwp_id();
        self->_func(); // 执行用户提供的函数
        pthread_exit((void *)0);
    }

public:
    Thread(func_t func, const std::string &name = threadNameFault)
        : _func(func), _name(name), _isRuning(false)
    {
    }

    void Start()
    {
        int n = pthread_create(&_tid, nullptr, startRun, this); // 把对象传递过去
        if (!n)
        {
            std::cout << "run thread success" << std::endl;
        }
    }

    void Join()
    {
        if (!_isRuning)
            return;
        int n = pthread_join(_tid, nullptr);
        if (!n)
        {
            std::cout << "pthread_join success" << std::endl;
        }
    }

    void Stop()
    {
        pthread_cancel(_tid);
    }

    ~Thread()
    {
    }

private:
    func_t _func;
    std::string _name;
    pthread_t _tid;
    pid_t _lwpid;
    bool _isRuning;
};

#endif
