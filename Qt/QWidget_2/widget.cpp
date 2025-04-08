#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand(time(0));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("ok!!!");
}

void Widget::on_pushButton_reject_clicked()
{

}


void Widget::on_pushButton_reject_pressed()
{
    int width = this->geometry().width();
    int height = this->geometry().height();

    int x = rand() % width - 30;
    int y = rand() % height - 30;
//    ui->pushButton_reject->move(x,y);

    QRect rect = ui->pushButton_reject->geometry();
    ui->pushButton_reject->setGeometry(x,y,rect.width(),rect.height());
}







