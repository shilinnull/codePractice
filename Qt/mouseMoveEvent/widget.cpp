#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMouseEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMouseTracking(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << event->x() << event->y();
}

void Widget::wheelEvent(QWheelEvent *event)
{
    int localDelta = event->delta();
    qDebug() << localDelta;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << event->key();
    if(event->key() == Qt::Key_A){
        qDebug() << "按下了A";
    }
    if(event->key() == Qt::Key_Q && event->modifiers() == Qt::ControlModifier){
        qDebug() << "按下了ctrl + Q";
    }
}

