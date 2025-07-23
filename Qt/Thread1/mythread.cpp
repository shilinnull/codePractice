#include "mythread.h"

QMutex myThread::mutex;
int myThread::num = 0;


myThread::myThread(QObject *parent) : QThread(parent)
{

}

void myThread::run()
{
    int i = 0;
    while(i < 10000)
    {
        QMutexLocker lock(&mutex);
//        this->mutex.lock();
        num++;
//        this->mutex.unlock();
        i++;
    }
}
