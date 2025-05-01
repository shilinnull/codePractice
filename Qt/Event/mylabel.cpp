#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::enterEvent(QEvent *event)
{
    qDebug() << "enter";


}

void MyLabel::leaveEvent(QEvent *event)
{
    qDebug() << "leave";

}
