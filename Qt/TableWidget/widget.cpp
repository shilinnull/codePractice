#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);


    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("年龄"));

    // 设置初始数据
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("20"));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("1002"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("21"));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("1003"));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2, 2, new QTableWidgetItem("19"));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
}

void Widget::on_pushButton_2_clicked()
{
    int rowCount = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(rowCount);
}

void Widget::on_pushButton_3_clicked()
{
    int colCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(colCount);

    // 获取lineEdit的text
    const QString& name = ui->lineEdit->text();
    ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(name));
}

void Widget::on_pushButton_4_clicked()
{
    int curCol = ui->tableWidget->currentColumn();
    ui->tableWidget->removeColumn(curCol);
}


