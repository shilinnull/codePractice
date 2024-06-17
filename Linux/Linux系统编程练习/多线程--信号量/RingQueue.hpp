#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <semaphore.h>

// 默认队列容量
const static int defaultcap = 5;

template <class T>
class RingQueue
{
private:
    void Lock(pthread_mutex_t &mutex)
    {
        pthread_mutex_lock(&mutex);
    }

    void UnLock(pthread_mutex_t &mutex)
    {
        pthread_mutex_unlock(&mutex);
    }

    // -
    void P(sem_t &sem)
    {
        sem_wait(&sem);
    }

    // +
    void V(sem_t &sem)
    {
        sem_post(&sem);
    }

public:
    RingQueue(int cap = defaultcap)
        : ringqueue_(cap), cap_(cap), c_step_(0), p_step_(0)
    {
        sem_init(&cdata_sem_, 0, 0);    // 消费者初始值为0
        sem_init(&pspace_sem_, 0, cap); // 生产者初始值为容量

        pthread_mutex_init(&c_mutex_, nullptr);
        pthread_mutex_init(&p_mutex_, nullptr);
    }

    // 生产
    void Push(const T &in)
    {
        // 先申请空间--
        P(pspace_sem_); // P-  V+

        // 加锁
        Lock(p_mutex_);

        // 将数据存放
        ringqueue_[p_step_] = in;
        p_step_++;
        p_step_ %= cap_;

        // 解锁
        UnLock(p_mutex_);

        // data资源++
        V(cdata_sem_);
    }

    // 消费
    void Pop(T *out)
    {
        // 申请资源--
        P(cdata_sem_);

        // 加锁
        Lock(c_mutex_);

        *out = ringqueue_[c_step_];
        c_step_++;
        c_step_ %= cap_;

        // 解锁
        UnLock(c_mutex_);

        // 释放空间++
        V(pspace_sem_);
    }

    ~RingQueue()
    {
        sem_destroy(&cdata_sem_);
        sem_destroy(&pspace_sem_);

        pthread_mutex_destroy(&c_mutex_);
        pthread_mutex_destroy(&p_mutex_);
    }

private:
    std::vector<T> ringqueue_; // 队列
    int cap_;                  // 队列的容量

    int c_step_; // 消费者下标
    int p_step_; // 生产者下标

    sem_t cdata_sem_;  // 消费者关注的数据资源
    sem_t pspace_sem_; // 生产者关注的空间资源

    pthread_mutex_t c_mutex_; // 消费者锁
    pthread_mutex_t p_mutex_; // 生产者锁
};