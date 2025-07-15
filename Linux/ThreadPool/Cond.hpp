#ifndef __COND_HPP__
#define __COND_HPP__

#include <pthread.h>
#include "lockGuard.hpp"

class Cond
{
public:
    Cond()
    {
        pthread_cond_init(&_cond, nullptr);
    }

    void Wait(Mutex &mutex)
    {
        pthread_cond_wait(&_cond, mutex.Get());
    }

    void Notify()
    {
        pthread_cond_signal(&_cond);
    }

    void NotifyAll()
    {
        pthread_cond_broadcast(&_cond);
    }

    ~Cond()
    {
        pthread_cond_destroy(&_cond);
    }

private:
    pthread_cond_t _cond;
};

#endif