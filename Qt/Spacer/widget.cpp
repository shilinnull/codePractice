#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);

    QSpacerItem* spacer = new QSpacerItem(200,20);

    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    layout->addWidget(btn1);
    layout->addSpacerItem(spacer);
    layout->addWidget(btn2);
}

Widget::~Widget()
{
    delete ui;
}

