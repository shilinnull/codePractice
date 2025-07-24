#ifndef __THREAD_POOL__
#define __THREAD_POOL__

#include <queue>

#include "lockGuard.hpp"
#include "Thread.hpp"
#include "Cond.hpp"
#include "Logger.hpp"

const static int defaultThreadNum = 3;

template <typename T>
class ThreadPool
{
private:
    bool isEmpty()
    {
        return _q.empty();
    }

    void Routine(const std::string &name)
    {
        for (;;)
        {
            T t; // 获取任务
            {
                LockGuard lockGuard(&_lock);   // 线程过来进行加锁
                while (isEmpty() && _isRuning) // 任务队列为空且线程池正在运行就正在等待
                {
                    _wait_thread_num++;
                    _cond.Wait(_lock);
                    _wait_thread_num--;
                }
                if (isEmpty() && !_isRuning)
                {
                    LOG(LogLevel::INFO) << " 线程池退出 && 任务队列为空, " << name << " 退出";
                    break;
                }
                // 走到这里说明一定有任务了
                t = _q.front();
                _q.pop();
            }
            t(); // 执行任务
        }
    }
    std::unique_ptr<ThreadPool<T>> &operator=(const std::unique_ptr<ThreadPool<T>> &) = delete; // 赋值重载禁用掉
    ThreadPool(const std::unique_ptr<ThreadPool<T>> &) = delete;                                // 拷贝构造禁用掉

public:
    ThreadPool(int threadNum = defaultThreadNum)
        : _threadNum(threadNum),
          _wait_thread_num(0),
          _isRuning(false)
    {
        for (int i = 0; i < _threadNum; i++)
        {
            std::string name = "thread-" + std::to_string(i + 1);
            _threads.emplace_back([this](const std::string &name)
                                  { this->Routine(name); }, name);
            LOG(LogLevel::INFO) << "thread pool obj create success";
        }
    }
    static std::string ToHex(ThreadPool<T>* addr)
    {
        char buffer[64];
        snprintf(buffer, sizeof(buffer), "%p", addr);
        return buffer;
    }

    static ThreadPool<T>* getInstance()
    {
        if (!_instance)
        {
            LockGuard lockGuard(&_singleton_lock);
            if (!_instance)
            {
                _instance = std::make_unique<ThreadPool<T>>();
                LOG(LogLevel::DEBUG) << "线程池单例首次被使用，创建并初始化, addr: " << ToHex(_instance.get());
                _instance->Start();
            }
        }
        else
            LOG(LogLevel::DEBUG) << "线程池单例已经存在,直接获取, addr: " << ToHex(_instance.get());

        return _instance.get();
    }

    void Start()
    {
        if (_isRuning) // 线程池已经在运行了
            return;
        _isRuning = true;
        for (auto &t : _threads)
        {
            t.Start();
        }
        LOG(LogLevel::INFO) << "thread pool running success";
    }

    void Stop()
    {
        if (!_isRuning) // 已经停止了
            return;
        _isRuning = false;
        if (_wait_thread_num > 0)
            _cond.NotifyAll(); // 唤醒所有线程

        LOG(LogLevel::INFO) << "thread pool stop success";
        // 不推荐直接停止线程，因为可能有些线程还在执行任务
    }

    void Wait()
    {
        for (auto &t : _threads)
        {
            t.Join();
        }
        LOG(LogLevel::INFO) << "thread pool wait success";
    }

    void Push(const T &in)
    {
        if (!_isRuning)
            return;
        {
            LockGuard lockGuard(&_lock);
            _q.push(in);
            if (_wait_thread_num > 0)
                _cond.Notify();
        }
    }

    ~ThreadPool() {}

private:
    std::queue<T> _q;             // 任务队列
    std::vector<Thread> _threads; // 多个线程

    int _threadNum;       // 线程个数
    int _wait_thread_num; // 线程等待个数

    Mutex _lock; // 锁
    Cond _cond;  // 条件变量

    bool _isRuning; // 是否在运行

    static Mutex _singleton_lock;                    // 单例模式锁
    static std::unique_ptr<ThreadPool<T>> _instance; // 单例模式指针
};

template <typename T>
std::unique_ptr<ThreadPool<T>> ThreadPool<T>::_instance = nullptr;

template <typename T>
Mutex ThreadPool<T>::_singleton_lock; // 初始化锁
#endif