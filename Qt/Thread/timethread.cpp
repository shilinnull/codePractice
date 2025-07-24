#include "timethread.h"

#include <QTime>
#include <QDebug>
#include <qapplication.h>


TimeThread::TimeThread()
{

}

void TimeThread::run()
{
    for(;;)
    {
        QString time = QTime::currentTime().toString("hh:mm:ss");
        qDebug() << time;
        emit sendTime(time);

        sleep(1);
    }

}
