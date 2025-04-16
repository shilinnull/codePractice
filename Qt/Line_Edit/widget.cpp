#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QString>
#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit_name->setPlaceholderText("请输入姓名：");
    ui->lineEdit_name->setClearButtonEnabled(true);

    ui->lineEdit_password->setPlaceholderText("请输入密码：");
    ui->lineEdit_password->setClearButtonEnabled(true);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    ui->lineEdit_phone->setPlaceholderText("请输入电话号码：");
    ui->lineEdit_phone->setClearButtonEnabled(true);
    ui->lineEdit_phone->setInputMask("000-0000-0000");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug() << "姓名: " << ui->lineEdit_name->text() << '\n'
             << "密码" << ui->lineEdit_password->text() << '\n'
             << "性别" << (ui->radioButton_male->isChecked() ? "男" : "女") << '\n'
             << "手机" << ui->lineEdit_phone->text() << '\n';
}
