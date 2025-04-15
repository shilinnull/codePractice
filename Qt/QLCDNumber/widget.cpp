#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer,&QTimer::timeout,this,&Widget::updateTime);
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTime()
{
    int value = ui->lcdNumber->intValue();
    if(value <= 0)
    {
        timer->stop();
        return;
    }
    ui->lcdNumber->display(value - 1);

}

