#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("点击关闭/启用状态");
    button->move(100,100);
    // 此按钮被禁用
    connect(button,&QPushButton::clicked,this,&Widget::HandleClicked);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(ui->pushButton->text() == QString("切换状态1"))
        ui->pushButton->setText("切换状态2");
    else
        ui->pushButton->setText("切换状态1");
}

void Widget::HandleClicked()
{
    if(ui->pushButton->isEnabled())
        ui->pushButton->setEnabled(false);
    else
        ui->pushButton->setEnabled(true);
}

