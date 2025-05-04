#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ui->pushButton->setStyleSheet("QPushButton{ color: red; }");

//    this->setStyleSheet("QPushButton{ color: red;}");
    ui->pushButton_3->setStyleSheet("QPushButton{ color: red;}");
    ui->pushButton->setStyleSheet("QPushButton{ font-size: 50px;}");
}

Widget::~Widget()
{
    delete ui;
}

