#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel* lable1 = new QLabel(ui->tab_3);
    lable1->setText("标签页1");
    lable1->resize(100, 50);

    QLabel* lable2 = new QLabel(ui->tab_4);
    lable2->setText("标签页2");
    lable2->resize(100, 50);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_add_clicked()
{
    int count = ui->tabWidget->count();
    QWidget* w = new QWidget();

    ui->tabWidget->addTab(w, QString("Tab ") + QString::number(count + 1));

    QLabel* lable = new QLabel(w);
    lable->setText(QString("标签页") + QString::number(count + 1));
    lable->resize(100, 50);

    ui->tabWidget->setCurrentIndex(count);
}

void Widget::on_pushButton_delete_clicked()
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->removeTab(index);
}

void Widget::on_tabWidget_currentChanged(int index)
{
    qDebug() << "当前选中为: " << index << endl;
}
