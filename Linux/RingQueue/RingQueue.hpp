#ifndef __RINGQUEUE_HPP__
#define __RINGQUEUE_HPP__

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <semaphore.h>

#include "lockGuard.hpp"
#include "Sem.hpp"

static int default_size = 5; // for debug


template <typename T>
class RingQueue
{
public:
    RingQueue(int size = default_size)
        : _q(size), _size(size), _space_sem(size), _data_sem(0), _p_step(0), _c_step(0)
    {
    }

    void Pop(T *out)
    {
        _data_sem.P(); // 等待数据
        {
            LockGuard lock(&_c_lock); // 锁定消费者锁
            *out = _q[_c_step];
            _c_step = (_c_step + 1) % _size; // 更新消费者步进
        }
        _space_sem.V(); // 释放空间
    }

    void Push(const T &data)
    {
        _space_sem.P(); // 等待空间
        {
            LockGuard lock(&_p_lock); // 锁定生产者锁
            _q[_p_step] = data;
            _p_step = (_p_step + 1) % _size; // 更新生产者步进
        }
        _data_sem.V(); // 释放数据
    }

    ~RingQueue()
    {
    }

private:
    std::vector<T> _q;
    int _size;

    Sem _space_sem;
    Sem _data_sem;

    int _p_step;
    int _c_step;

    Mutex _c_lock;
    Mutex _p_lock;
};

#endif // __RINGQUEUE_HPP__