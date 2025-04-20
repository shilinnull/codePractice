#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabel("动物");
    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    item1->setText(0,"猫");
    ui->treeWidget->addTopLevelItem(item1);


    QTreeWidgetItem* item2 = new QTreeWidgetItem();
    item2->setText(0,"狗");
    ui->treeWidget->addTopLevelItem(item2);

    QTreeWidgetItem* item3 = new QTreeWidgetItem();
    item3->setText(0,"鸟");
    ui->treeWidget->addTopLevelItem(item3);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
        return;

    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, text);
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_pushButton_2_clicked()
{
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
        return;

    QTreeWidgetItem* cur = ui->treeWidget->currentItem();
    if(cur == NULL)
        return;

    QTreeWidgetItem* newItem = new QTreeWidgetItem();
    newItem->setText(0, text);
    cur->addChild(newItem);

    cur->setExpanded(true);
}

void Widget::on_pushButton_3_clicked()
{
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if(currentItem == NULL)
        return;
    QTreeWidgetItem* parent = currentItem->parent();
    if(parent == NULL)
    {
        int index = ui->treeWidget->indexOfTopLevelItem(currentItem);
        ui->treeWidget->takeTopLevelItem(index);
    }
    else
    {
        parent->removeChild(currentItem);
    }
}
