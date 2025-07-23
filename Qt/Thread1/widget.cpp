#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    myThread *t1 = new myThread(this);
    myThread *t2 = new myThread(this);

    t1->start();
    t2->start();

    t1->wait();
    t2->wait();

    qDebug() << myThread::num;
}

Widget::~Widget()
{
    delete ui;
}

