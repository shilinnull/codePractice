#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QWidget>
#include <QThread>
#include <QMutex>

class TimeThread : public QThread
{
    Q_OBJECT
public:
    TimeThread();
    void run() override;

signals:
    void sendTime(QString Time);
};

#endif // TIMETHREAD_H
