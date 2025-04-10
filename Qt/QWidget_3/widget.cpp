#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include <QRect>
#include <QIcon>
#include <QDir>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
   QPushButton *button = new QPushButton(this);
   button->setText("按钮");
   button->move(100,100);
   connect(button,&QPushButton::clicked,this,&Widget::handle);

//    QIcon icon("F:/code-exercise/Qt/QWidget_3/rose.png");
//    this->setWindowIcon(icon);
//    QString currentDir = QDir::currentPath();
//   button->setText(currentDir);
    QIcon icon(":/image/rose.png");
    this->setWindowIcon(icon);


    QRect rect1 = geometry();
    QRect rect2 = frameGeometry();
    qDebug() << rect1;
    qDebug() << rect2;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    QRect rect1 = geometry();
    QRect rect2 = frameGeometry();
    qDebug() << rect1;
    qDebug() << rect2;
}

