#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QButtonGroup *group1 = new QButtonGroup(this);
    QButtonGroup *group2 = new QButtonGroup(this);
    QButtonGroup *group3 = new QButtonGroup(this);

    group1->addButton(ui->radioButton_1);
    group1->addButton(ui->radioButton_2);

    group2->addButton(ui->radioButton_3);
    group2->addButton(ui->radioButton_4);


    group3->addButton(ui->radioButton_5);
    group3->addButton(ui->radioButton_6);


    ///////////////////////////////////////////////////////////////
    ui->label_2->setTextFormat(Qt::PlainText);
    ui->label_2->setText("这是纯文本");
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setText("<b>这是纯富文本</b>");
    ui->label_4->setTextFormat(Qt::MarkdownText);
    ui->label_4->setText("# 这是Markdown");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
//    QString result = ui->label->text();
    QString result = "今天的安排是：";

    if(ui->checkBox->isChecked())
        result += ui->checkBox->text() + " ";
    if(ui->checkBox_2->isChecked())
        result += ui->checkBox_2->text() + " ";
    if(ui->checkBox_3->isChecked())
        result += ui->checkBox_3->text();

    ui->label->setText(result);
}
















