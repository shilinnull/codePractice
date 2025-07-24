#include "widget.h"
#include "ui_widget.h"

#include <QNetworkDatagram>
#include <QDebug>

//const QString& SERVER_IP = "113.44.240.190";
const QString& SERVER_IP = "127.0.0.1";
const quint16 SERVER_PORT = 9090;
//const quint16 SERVER_PORT = 8080;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("客户端");

    socket = new QUdpSocket(this);
    // 连接
    connect(socket, &QUdpSocket::readyRead, this, [=]{
        // 接收数据
        const QNetworkDatagram& respnseDatagram = socket->receiveDatagram();
        QString response = respnseDatagram.data();

        // QString response = socket->receiveDatagram().data();
        ui->listWidget->addItem(QString("服务器说：") + response);
    });


    connect(ui->lineEdit, &QLineEdit::returnPressed, this, [this]()
    {
        on_pushButton_clicked();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 1. 读取数据
    const QString& text = ui->lineEdit->text();
    // 2. 构建数据
    QNetworkDatagram requestDatagram(text.toUtf8(), QHostAddress(SERVER_IP), SERVER_PORT);
    // 3. 发送请求
    socket->writeDatagram(requestDatagram);
    ui->listWidget->addItem("你说：" + text);
    ui->lineEdit->clear();
}
