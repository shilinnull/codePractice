#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>
#include <QThread>
#include <QMutex>

class myThread : public QThread
{
    Q_OBJECT
public:
    myThread(QObject* parent);
    void run() override;
    static QMutex mutex;
    static int num;
};

#endif // MYTHREAD_H
