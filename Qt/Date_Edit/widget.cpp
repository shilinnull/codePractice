#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QDateTime timeold = ui->dateTimeEdit_old->dateTime();
    QDateTime timenew= ui->dateTimeEdit_new->dateTime();

    // 计算日期差值

    int days = timeold.daysTo(timenew);
    int hours = timeold.secsTo(timenew);
    hours = (hours / 3600) % 24;
    QString text = QString("已经持续") + QString::number(days) + "天零" + QString::number(hours);
    ui->label->setText(text);

}
