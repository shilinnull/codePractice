#ifndef __BLOCKQUEUE_HPP__
#define __BLOCKQUEUE_HPP__

#include <iostream>
#include <string>
#include <queue>
#include <pthread.h>
#include "Cond.hpp"
#include "lockGuard.hpp"

template <typename T>
class BlockQueue
{
    const static uint32_t defaultnum = 5;

public:
    BlockQueue(int cap = defaultnum) : _cap(cap), _c_wait_num(0), _p_wait_num(0)
    {
    }

    void Push(const T &in)
    {
        {
            LockGuard lockguard(&_lock);
            while (_q.size() == _cap) // 判断队列是否已满
            {

                _p_wait_num++;
                _p_cond.Wait(_lock); // 阻塞等待
                _p_wait_num--;
            }
            _q.push(in);
            if (_c_wait_num > 0)
                _c_cond.Notify(); // 唤醒消费者
        }
    }

    void Pop(T *out)
    {
        {
            LockGuard lockguard(&_lock);
            while (_q.empty()) // 判断队列是否为空
            {
                _c_wait_num++;
                _c_cond.Wait(_lock);
                _c_wait_num--;
            }
            *out = _q.front();
            _q.pop();
            if (_p_wait_num > 0)
                _p_cond.Notify(); // 唤醒生产者
        }
    }

    ~BlockQueue()
    {
    }

private:
    std::queue<T> _q; // 阻塞队列
    uint32_t _cap;    // 队列容量

    Mutex _lock;  // 锁
    Cond _c_cond; // 消费者条件变量
    Cond _p_cond; // 生产者条件变量

    int _c_wait_num; // 当前消费者等待的个数
    int _p_wait_num; // 当前生产者等待的个数
};

#endif // __BLOCKQUEUE_HPP__