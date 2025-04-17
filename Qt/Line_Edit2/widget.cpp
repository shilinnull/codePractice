#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    (void)arg1;
    const QString s1 = ui->lineEdit->text();
    const QString s2 = ui->lineEdit_2->text();
    if(s1.isEmpty() && s2.isEmpty())
    {
        ui->label->setText("密码为空");
    }
    else if(s1 == s2)
    {
        ui->label->setText("密码相同");
    }
    else
    {
        ui->label->setText("密码不一样");
    }
}

void Widget::on_lineEdit_2_textEdited(const QString &arg1)
{
    (void)arg1;
    const QString s1 = ui->lineEdit->text();
    const QString s2 = ui->lineEdit_2->text();
    if(s1.isEmpty() && s2.isEmpty())
    {
        ui->label->setText("密码为空");
    }
    else if(s1 == s2)
    {
        ui->label->setText("密码相同");
    }
    else
    {
        ui->label->setText("密码不一样");
    }
}

void Widget::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}

void Widget::on_checkBox_2_toggled(bool checked)
{
    if(checked)
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}
