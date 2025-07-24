#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("服务器");

    tcpserver = new QTcpServer(this);

    connect(tcpserver, &QTcpServer::newConnection, this, &Widget::processConnection);

    bool ret = tcpserver->listen(QHostAddress::Any, 9090);
    if(!ret)
    {
        QMessageBox::critical(nullptr, "服务器启动失败！", tcpserver->errorString());
        return;
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::processConnection()
{
    QTcpSocket *clientSocket = tcpserver->nextPendingConnection();
    QString log = QString("[") + clientSocket->peerAddress().toString()
            + ":" + QString::number(clientSocket->peerPort()) + "] 客⼾端上线!"; ui->listWidget->addItem(log);

    connect(clientSocket, &QTcpSocket::readyRead, this, [=](){
       QString request = clientSocket->readAll();
       const QString& response = process(request);
       clientSocket->write(response.toUtf8());
       QString log = QString("[") + clientSocket->peerAddress().toString() + ":" + QString::number(clientSocket->peerPort()) + "] req: " + request + ", resp: " + response;
       ui->listWidget->addItem(log);
    });

    connect(clientSocket, &QTcpSocket::disconnected, this, [=]() {
        QString log = QString("[") + clientSocket->peerAddress().toString()
                + ":" + QString::number(clientSocket->peerPort()) + "] 客⼾端下线!";
        ui->listWidget->addItem(log);
        clientSocket->deleteLater();
    });

}

QString Widget::process(const QString& request)
{
    return "服务器收到，回复该条消息";
}










