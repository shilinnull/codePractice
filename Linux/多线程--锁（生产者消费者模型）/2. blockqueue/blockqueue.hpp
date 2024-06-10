#include <iostream>
#include <queue>

template <class T>
class BlockQueue
{
    static const int defaultnum = 5;

public:
    BlockQueue(int maxcap = defaultnum)
        : maxcap_(maxcap)
    {
        // 初始化锁
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&c_cond_, nullptr);
        pthread_cond_init(&p_cond_, nullptr);
    }
    T Pop()
    {
        // 加锁
        pthread_mutex_lock(&mutex_);

        while (q_.size() == 0) // 因为判断临界资源调试是否满足，也是在访问临界资源！判断资源是否就绪，是通过再临界资源内部判断的。
        {
            // 进行等待，调用的时候，自动释放锁，因为唤醒而返回的时候，重新持有锁
            pthread_cond_wait(&c_cond_, &mutex_);
        }
        // 取出队头数据，进行处理
        T out = q_.front();
        q_.pop();

        // 唤醒生产
        pthread_cond_signal(&p_cond_);

        // 如果线程wait时，被误唤醒了呢？？ -->
        // pthread_cond_broadcast(&c_cond_, &mutex_); // 唤醒所有线程

        // 解锁
        pthread_mutex_unlock(&mutex_);
        return out;
    }
    void Push(const T &in)
    {
        // 加锁
        pthread_mutex_lock(&mutex_);
        while (q_.size() == maxcap_) // 因为判断临界资源调试是否满足，也是在访问临界资源！判断资源是否就绪，是通过再临界资源内部判断的。
        {
            pthread_cond_wait(&p_cond_, &mutex_);
        }
        // 入队
        q_.push(in);

        // 唤醒消费
        pthread_cond_signal(&c_cond_);
        // 解锁
        pthread_mutex_unlock(&mutex_);
    }

    // 析构
    ~BlockQueue()
    {
        pthread_cond_destroy(&c_cond_);
        pthread_cond_destroy(&p_cond_);
        pthread_mutex_destroy(&mutex_);
    }

private:
    // 一个队列
    std::queue<T> q_;
    // 一个极值，队列到达极值就不可入队
    int maxcap_;
    // 一个消费者，一个生产者
    pthread_cond_t c_cond_;
    pthread_cond_t p_cond_;
    // 锁
    pthread_mutex_t mutex_;
};