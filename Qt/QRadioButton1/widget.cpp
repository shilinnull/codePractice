#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->radioButton_male->setChecked(true);
    ui->label->setText("您选择的是：男");

    ui->radioButton_other->setCheckable(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_radioButton_male_clicked()
{
    ui->label->setText("您选择的是：男");
}
void Widget::on_radioButton_female_clicked()
{
    ui->label->setText("您选择的是：女");
}
void Widget::on_radioButton_other_clicked()
{
    ui->label->setText("您选择的是：其他");
}

void Widget::on_radioButton_clicked()
{
    qDebug() << "clicked";
}

void Widget::on_radioButton_2_pressed()
{
    
    qDebug() << "pressed";
}

void Widget::on_radioButton_3_released()
{
    qDebug() << "released";
}

void Widget::on_radioButton_4_toggled(bool checked)
{
    if(checked)
    {
        qDebug() << "toggled： " << checked ;
    }
    else
    {
        qDebug() << "toggled： " << checked ;
    }
}
