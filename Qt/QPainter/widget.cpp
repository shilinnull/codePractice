#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawLine(QPoint(20, 20), QPoint(200, 20));
    painter.drawLine(100, 100, 200, 200);

    painter.drawRect(20, 20, 100, 50);

    painter.drawEllipse(QPoint(200, 200), 50, 50);
    painter.drawEllipse(QPoint(300, 300), 50, 100);

    QFont font("华文行楷", 24);
    painter.setFont(font);

//    painter.setStyle(Qt::DashLine);


    painter.setPen(Qt::red);

    painter.drawText(QRect(100, 200, 600, 150), "天行健，君子以自强不息");


    painter.translate(400, 400);
    painter.drawPixmap(0,0,QPixmap(":/cat.png"));
    painter.drawPixmap(600, 600, 50, 50, QPixmap(":/cat.png"));

    painter.rotate(180);
    painter.translate(-400, -400);
    painter.drawPixmap(0,0,QPixmap(":/cat.png"));

    QImage img;
    img.load(":/cat.png");
    for(int i = 500; i < 600; i++)
    {
        for(int j = 500; j < 600;j++)
        {
            QRgb rgb = qRgb(i + j, j, j);
            img.setPixel(i, j, rgb);
        }
    }
    painter.drawImage(0, 0, img);
}











