#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label->setText("垂直水平居中");

    ui->label_2->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    // 自动换行
    ui->label_2->setWordWrap(true);
    ui->label_2->setText("这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字");

    ui->label_3->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->label_3->setIndent(50);
    ui->label_3->setText("这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字");

    ui->label_4->setAlignment(Qt::AlignTop | Qt::AlignRight);
    ui->label_4->setMargin(20);
    ui->label_3->setText("这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字这是一段很长的文字");

    ///////////////////////////////////////////////////////////////////////////

    ui->label_5->setBuddy(ui->radioButton);
    ui->label_6->setBuddy(ui->radioButton_2);




}

Widget::~Widget()
{
    delete ui;
}

