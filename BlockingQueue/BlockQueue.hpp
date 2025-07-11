#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <pthread.h>

template <typename T>
class BlockQueue
{
    const static uint32_t defaultnum = 5;

public:
    BlockQueue(int cap = defaultnum) : _cap(cap), _c_wait_num(0), _p_wait_num(0)
    {
        pthread_mutex_init(&_lock, nullptr);
        pthread_cond_init(&_c_cond, nullptr);
        pthread_cond_init(&_p_cond, nullptr);
    }

    void Push(const T &in)
    {
        pthread_mutex_lock(&_lock); 
        while (_q.size() == _cap) // 判断队列是否已满
        {
            _p_wait_num++;
            pthread_cond_wait(&_p_cond, &_lock);
            _p_wait_num--;
        }
        _q.push(in);
        if (_c_wait_num > 0)
            pthread_cond_signal(&_c_cond); // 唤醒消费者
        pthread_mutex_unlock(&_lock);
    }

    T Pop()
    {
        pthread_mutex_lock(&_lock);
        while (_q.empty()) // 判断队列是否为空
        {
            _c_wait_num++;
            pthread_cond_wait(&_c_cond, &_lock);
            _c_wait_num--;
        }
        T out = _q.front();
        _q.pop();
        if (_p_wait_num > 0)
            pthread_cond_signal(&_p_cond); // 唤醒生产者
        pthread_mutex_unlock(&_lock);
        return out;
    }

    ~BlockQueue()
    {
        pthread_mutex_destroy(&_lock);
        pthread_cond_destroy(&_c_cond);
        pthread_cond_destroy(&_p_cond);
    }

private:
    std::queue<T> _q; // 阻塞队列
    uint32_t _cap;    // 队列容量

    pthread_mutex_t _lock;  // 锁
    pthread_cond_t _c_cond; // 消费者条件变量
    pthread_cond_t _p_cond; // 生产者条件变量

    int _c_wait_num; // 当前消费者等待的个数
    int _p_wait_num; // 当前生产者等待的个数
};
