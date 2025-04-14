#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setGeometry(0,0,800,600);

    ui->label->setPixmap(QPixmap(":/huaji.png"));

    ui->label->setScaledContents(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    ui->label->setGeometry(0,0,this->size().width(),this->size().height());
    qDebug() << this->size();
}






