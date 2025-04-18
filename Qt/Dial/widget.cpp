#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->dial->setWrapping(true);
    ui->dial->setNotchesVisible(true);
    ui->dial->setMaximum(100);
    ui->dial->setMinimum(0);
    ui->dial->setValue(100);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_dial_valueChanged(int value)
{
    ui->label->setText(QString("当前窗口不透明度：") + QString::number(value));
    this->setWindowOpacity((double)value / 100);
}
