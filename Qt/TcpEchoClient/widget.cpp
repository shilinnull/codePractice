#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("客户端");
    socket = new QTcpSocket(this);

    socket->connectToHost("127.0.0.1", 9090);

    connect(socket, &QTcpSocket::readyRead, this, [=]{
       QString response = socket->readAll();
        ui->listWidget->addItem(QString("服务器说：") + response);
    });

    if(!socket->waitForConnected())
    {
        QMessageBox::critical(nullptr, "连接服务器出错!", socket->errorString());
        exit(1);
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    const QString& text = ui->lineEdit->text();

    ui->listWidget->addItem(QString("客户端说: ") + text);
    socket->write(text.toUtf8());

    ui->lineEdit->clear();
}
