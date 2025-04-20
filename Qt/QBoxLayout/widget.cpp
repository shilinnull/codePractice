#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVBoxLayout* layoutparent = new QVBoxLayout();
    this->setLayout(layoutparent);

    // 添加两个按钮进去
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");

    layoutparent->addWidget(btn1);
    layoutparent->addWidget(btn2);

    QHBoxLayout* layoutChild = new QHBoxLayout();
    QPushButton* btn3 = new QPushButton("按钮3");
    QPushButton* btn4 = new QPushButton("按钮4");
    layoutChild->addWidget(btn3);
    layoutChild->addWidget(btn4);

    layoutparent->addLayout(layoutChild);
}

Widget::~Widget()
{
    delete ui;
}

