#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget* parent)
    :QPushButton(parent)
{

    this->setStyleSheet("QPushButton{ color: red; }");

}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{

    this->setStyleSheet("QPushButton{ color: blue; }");
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    this->setStyleSheet("QPushButton{ color: green; }");

}

void MyPushButton::enterEvent(QEvent *e)
{
    this->setStyleSheet("QPushButton{ color: green; }");
}

void MyPushButton::leaveEvent(QEvent *e)
{

    this->setStyleSheet("QPushButton{ color: red; }");
}
