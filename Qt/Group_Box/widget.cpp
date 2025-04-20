#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("巨无霸");
    ui->comboBox->addItem("麦辣鸡腿堡");
    ui->comboBox_2->addItem("薯条");
    ui->comboBox_2->addItem("麦辣鸡翅");
    ui->comboBox_3->addItem("可乐");
    ui->comboBox_3->addItem("雪碧");
}

Widget::~Widget()
{
    delete ui;
}

