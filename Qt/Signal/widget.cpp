#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // this->setWindowTitle("自定义窗口标题");
    // QPushButton* button = new QPushButton(this);
    // button->setText("关闭");
    // button->move(200,200);
    // 内置信号和槽
    // connect(button,&QPushButton::clicked,this,&Widget::close);
    // 自定义信号和自定义槽
    //connect(button,&QPushButton::clicked,this,&Widget::HandleClicked);


    connect(this,&Widget::mySignal,this,&Widget::HandleMySignal);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::HandleClicked()
{
   // 按下按钮修改窗口标题
    this->setWindowTitle("按钮按下了！");
}


void Widget::on_pushButton_clicked()
{
    // 发送自定义信号
    emit mySignal();
    // this->setWindowTitle("按钮按下了！");
}

void Widget::HandleMySignal()
{
    this->setWindowTitle("处理自定义信号");
}
