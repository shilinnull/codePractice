#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <pthread.h>
#include <unistd.h>

static const int defaultnum = 5;

struct ThreadInfo
{
    pthread_t tid;
    std::string name;
};

template <class T>
class ThreadPool
{
private:
    void Lock()
    {
        pthread_mutex_lock(&mutex_);
    }

    void Unlock()
    {
        pthread_mutex_unlock(&mutex_);
    }
    void WakeUp()
    {
        pthread_cond_signal(&cond_);
    }

    std::string GetThreadName(pthread_t tid)
    {
        for (const auto &ti : thread_)
        {
            if (ti.tid == tid)
                return ti.name;
        }
        return "None";
    }

    bool IsQueueEmpty()
    {
        return task_.empty();
    }

    void ThreadSleep()
    {
        pthread_cond_wait(&cond_, &mutex_);
    }

public:
    static void *HandlerTask(void *args)
    {
        ThreadPool<T> *tp = static_cast<ThreadPool<T> *>(args);
        std::string name = tp->GetThreadName(pthread_self()); // 获取名字

        while (true)
        {
            // 加锁
            tp->Lock();

            // 如果队列为空就将线程放到条件变量下等待
            while (tp->IsQueueEmpty())
            {
                tp->ThreadSleep();
            }

            // 取出节点
            T t = tp->Pop();

            // 解锁
            tp->Unlock();
            // 执行任务
            t();
            std::cout << name << " run, " << "result: " << t.GetResult() << std::endl;
        }
    }
    void Start()
    {
        for (int i = 0; i < thread_.size(); i++)
        {
            thread_[i].name = "Thread-" + std::to_string(i);
            pthread_create(&(thread_[i].tid), nullptr, HandlerTask, this);
        }
    }
    void Push(T &t)
    {
        Lock(); // 先加锁
        task_.push(t);
        WakeUp(); // 唤醒
        Unlock(); // 解锁
    }

    T Pop()
    {
        T t = task_.front();
        task_.pop();
        return t;
    }

    // 单例模式创建对象
    static ThreadPool<T> *GetInstance()
    {
        // 其他线程就不会每次执行加锁和解锁了~
        if (nullptr == tp_)
        {
            // 加锁
            pthread_mutex_lock(&lock_);
            if (nullptr == tp_)
            {
                std::cout << "log: singleton create done first!" << std::endl;
                tp_ = new ThreadPool<T>();
            }
            // 解锁
            pthread_mutex_unlock(&lock_);
        }
        return tp_;
    }

public:
    ThreadPool(int num = defaultnum)
        : thread_(num)
    {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }
    ~ThreadPool()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }

private:
    std::vector<ThreadInfo> thread_; // 任务线程
    std::queue<T> task_;             // 任务队列

    pthread_mutex_t mutex_; // 锁
    pthread_cond_t cond_;   // 条件变量

    // 单例模式，只能创建一个对象
    static ThreadPool<T> *tp_;
    static pthread_mutex_t lock_;
};

// 类外进行初始化
template <class T>
ThreadPool<T> *ThreadPool<T>::tp_ = nullptr;

template <class T>
pthread_mutex_t ThreadPool<T>::lock_ = PTHREAD_MUTEX_INITIALIZER;
