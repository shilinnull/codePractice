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
    // 连接      				readyRead 收到数据后触发
    connect(socket, &QUdpSocket::readyRead, this, &Widget::processRequest);
    // 绑定ip和端口
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
    // 1. 读取请求
    const QNetworkDatagram& requestDatagram = socket->receiveDatagram();
    QString request = requestDatagram.data();
    // 2. 根据请求准备回复
    const QString& response = process(request);
    // 3. 发回去
    QNetworkDatagram responseDatagram(response.toUtf8(),
                        requestDatagram.senderAddress(), requestDatagram.senderPort());
    socket->writeDatagram(responseDatagram);

    // ============================================================
    QString log = "[" + requestDatagram.senderAddress().toString() + ":"
            + QString::number(requestDatagram.senderPort()) + "] req: "
            + request + ", resp: " + response;
    ui->listWidget->addItem(log);
}

QString Widget::process(const QString &request)
{
    // 这里就直接返回了
    return request;
}
