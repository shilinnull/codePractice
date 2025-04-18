#include "widget.h"
#include "ui_widget.h"
#include <QRect>
#include <QShortcut>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMinimum(500);
    ui->horizontalSlider->setMaximum(2000);
    ui->horizontalSlider->setSingleStep(100);
    ui->horizontalSlider->setValue(800);

    ui->verticalSlider->setMinimum(500);
    ui->verticalSlider->setMaximum(2000);
    ui->verticalSlider->setSingleStep(100);
    ui->verticalSlider->setValue(800);

    QShortcut* shortcut1 = new QShortcut(this);
    shortcut1->setKey(QKeySequence("-"));
    connect(shortcut1,&QShortcut::activated,this,&Widget::subValue);


    QShortcut* shortcut2 = new QShortcut(this);
    shortcut2->setKey(QKeySequence("="));
    connect(shortcut2,&QShortcut::activated,this,&Widget::addValue);



}

Widget::~Widget()
{
    delete ui;
}


//void Widget::on_verticalSlider_valueChanged(int value)
//{
//    ui->label->setText(QString::number(value));
//    QRect rect = this->geometry();
//    this->setGeometry(rect.x(),rect.y(),value,rect.height());
//}

//void Widget::on_horizontalSlider_valueChanged(int value)
//{
//    ui->label->setText(QString::number(value));
//    QRect rect = this->geometry();
//    this->setGeometry(rect.x(),rect.y(),rect.width(),value);

void Widget::on_verticalSlider_valueChanged(int value)
{
    ui->label->setText(QString::number(value));
    QRect rect = this->geometry();
    this->setGeometry(rect.x(),rect.y(),value,rect.height());
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText(QString::number(value));
    QRect rect = this->geometry();
    this->setGeometry(rect.x(),rect.y(),rect.width(),value);
}


void Widget::subValue()
{
    int value = ui->verticalSlider->value();
    ui->verticalSlider->setValue(value - 20);
}

void Widget::addValue()
{
    int value = ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value + 20);
}
