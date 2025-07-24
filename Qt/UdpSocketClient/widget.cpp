#include "widget.h"
#include "ui_widget.h"

#include <QNetworkDatagram>

const QString& SERVER_IP = "113.44.240.190";
//const QString& SERVER_IP = "127.0.0.1";
//const quint16 SERVER_PORT = 9090;
const quint16 SERVER_PORT = 8080;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("客户端");

    socket = new QUdpSocket(this);

    connect(socket, &QUdpSocket::readyRead, this, [=]{
        const QNetworkDatagram respnseDatagram = socket->receiveDatagram();
        QString response = respnseDatagram.data();
//        ui->listWidget->addItem(QString("服务器说：") + response);
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    const QString& text = ui->lineEdit->text();

    QNetworkDatagram requestDatagram(text.toUtf8(), QHostAddress(SERVER_IP), SERVER_PORT);

    socket->writeDatagram(requestDatagram);
    ui->listWidget->addItem("你说：" + text);
    ui->lineEdit->clear();
}
