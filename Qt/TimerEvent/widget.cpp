#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMoveEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timerId = this->startTimer(1000);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() != this->timerId)
        return;
    // yes
    int value = ui->lcdNumber->value();
    if(value <= 0)
    {
        this->killTimer(this->timerId);
        return;
    }
    value -= 1;
    ui->lcdNumber->display(value);
}

void Widget::moveEvent(QMoveEvent *event)
{
    qDebug() << event->pos();
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
}

