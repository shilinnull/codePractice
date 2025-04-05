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


    // connect(this,&Widget::mySignal,this,&Widget::HandleMySignal);
    // connect(this,&Widget::mySignal,this,&Widget::HandleClicked);
    connect(this,&Widget::mySignal,this,[=](const QString& text){
        qDebug() << "lambda 执行了!";
        setWindowTitle(text);
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::HandleClicked(const QString& text)
{
   // 按下按钮修改窗口标题
    this->setWindowTitle(text);
}

void Widget::on_pushButton_clicked()
{
    // 发送自定义信号
    emit mySignal("标题一");
    // this->setWindowTitle("按钮按下了！");
}

void Widget::HandleMySignal()
{
    this->setWindowTitle("处理自定义信号");
}

void Widget::on_pushButton_2_clicked()
{
    emit mySignal("标题二");
}
