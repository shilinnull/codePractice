#ifndef __SEM_HPP__
#define __SEM_HPP__

#include <semaphore.h>

class Sem 
{
public:
    Sem(int value) 
        : _init_value(value) {
        sem_init(&_sem, 0, _init_value);
    }
    
    void P() {
        sem_wait(&_sem);
    }
    
    void V() {
        sem_post(&_sem);
    }
    
    ~Sem() {
        sem_destroy(&_sem);
    }
private:
    sem_t _sem;
    int _init_value;
};

#endif // __SEM_HPP__