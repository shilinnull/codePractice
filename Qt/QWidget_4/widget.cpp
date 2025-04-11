#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QCursor>
#include <QPixmap>
#include <QLabel>
#include <QFont>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->move(400,400);
    button->resize(200,100);
    button->setText("这是一个按钮");
    button->setCursor(QCursor(Qt::WaitCursor));

    /////////////////////////////////////////////////////////////

    QPixmap pixmax(":/basketball.png");
    pixmax = pixmax.scaled(64,64);
    QCursor cursor(pixmax,2,2);
    this->setCursor(cursor);

    QLabel* lable = new QLabel(this);
    lable->setText("这是一段文本");
    lable->move(400,50);
    QFont font;
    font.setFamily("仿宋");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    font.setUnderline(true);
    font.setStrikeOut(true);
    lable->setFont(font);

    ////////////////////////////////////////////////////////////////
    ui->pushButton_yes->setToolTip("这个是yes按钮");
    ui->pushButton_yes->setToolTipDuration(3000);
    ui->pushButton_no->setToolTip("这个是no按钮");
    ui->pushButton_no->setToolTipDuration(10000);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_add_clicked()
{
    float opacity = this->windowOpacity();
    if(opacity > 1.0)
        return;
    qDebug() << opacity;
    opacity += 0.05;
    this->setWindowOpacity(opacity);
}

void Widget::on_pushButton_sub_clicked()
{
    float opacity = this->windowOpacity();
    if(opacity > 1.0)
        return;
    qDebug() << opacity;
    opacity -= 0.05;
    this->setWindowOpacity(opacity);
}
