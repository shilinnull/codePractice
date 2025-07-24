#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QNetworkDatagram>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("服务器");
    socket = new QUdpSocket(this);
    connect(socket, &QUdpSocket::readyRead, this, &Widget::processRequest);

    bool ret = socket->bind(QHostAddress::Any, 9090);
    if(!ret)
    {
        QMessageBox::critical(nullptr, "服务器启动错误", socket->errorString());
        return;
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processRequest()
{
    const QNetworkDatagram& requestDatagram = socket->receiveDatagram();
    QString request = requestDatagram.data();
    const QString& response = process(request);
    QNetworkDatagram responseDatagram(response.toUtf8(), requestDatagram.senderAddress(), requestDatagram.senderPort());
    socket->writeDatagram(responseDatagram);

    QString log = "[" + requestDatagram.senderAddress().toString() + ":"
            + QString::number(requestDatagram.senderPort()) + "] req: "
            + request + ", resp: " + response;
    ui->listWidget->addItem(log);
}

QString Widget::process(const QString &request)
{
    return request;
}
