#include "label.h"
#include <QDebug>
#include <QMouseEvent>
Label::Label(QWidget*parent)
    :QLabel(parent)
{

}

void Label::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        qDebug() << "按下左键";
    }
    if(ev->button() == Qt::RightButton)
    {
        qDebug() << "按下右键";
    }

    qDebug() << ev->x();
    qDebug() << ev->y();
    qDebug() << ev->globalX() << "," << ev->globalY() << endl;

}

void Label::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
        qDebug() << "按下左键释放";
    else if(ev->button() == Qt::RightButton)
        qDebug() << "按下右键释放";
}

void Label::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        qDebug() << "双击左键";
    else if(event->button() == Qt::RightButton)
        qDebug() << "双击右键";

}
