#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QSize>
#include <QKeySequence>
#include <QRect>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QIcon icon(":image/doge.png");
    ui->pushButton->setIcon(icon);
    ui->pushButton->setIconSize(QSize(50,50));


    // 设置上下左右的图标
    ui->pushButton_up->setIcon(QIcon(":/image/up.png"));
    ui->pushButton_down->setIcon(QIcon(":/image/down.png"));
    ui->pushButton_left->setIcon(QIcon(":/image/left.png"));
    ui->pushButton_right->setIcon(QIcon(":/image/right.png"));

    // 设置快捷键
    ui->pushButton_up->setShortcut(QKeySequence("w"));
    ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));
    ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));
    ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));

    // 开启重复触发
    ui->pushButton_up->setAutoRepeat(true);
    ui->pushButton_down->setAutoRepeat(true);
    ui->pushButton_left->setAutoRepeat(true);
    ui->pushButton_right->setAutoRepeat(true);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_dark_clicked()
{
    this->setStyleSheet("background-color:#333");
    ui->textEdit->setStyleSheet("background-color: #333;color: #fff;");
    ui->pushButton_dark->setStyleSheet("color: #fff");
    ui->pushButton_light->setStyleSheet("color: #fff");

}

void Widget::on_pushButton_light_clicked()
{
    this->setStyleSheet("background-color: #f3f3f3");
    ui->textEdit->setStyleSheet("background-color: #fff;color: #000;");
    ui->pushButton_dark->setStyleSheet("color: #000");
    ui->pushButton_light->setStyleSheet("color: 000");

}

void Widget::on_pushButton_up_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x(),rect.y() - 5,rect.width(),rect.height());
    qDebug() << "up";
}


void Widget::on_pushButton_down_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x(),rect.y() + 5,rect.width(),rect.height());
    qDebug() << "down";
}
void Widget::on_pushButton_left_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x() - 5,rect.y(),rect.width(),rect.height());
    qDebug() << "left";
}
void Widget::on_pushButton_right_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x() + 5,rect.y(),rect.width(),rect.height());
    qDebug() << "right";
}


