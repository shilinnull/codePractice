#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QUrl url(ui->lineEdit->text());

    QNetworkRequest request(url);

    QNetworkReply* response = manager->get(request);

    connect(response, &QNetworkReply::finished, this, [=]{
       if (response->error() == QNetworkReply::NoError) {
           QString html(response->readAll());
           ui->plainTextEdit->setPlainText(html);
           ui->textEdit->setPlainText(html);
       }
       else
       {
           ui->plainTextEdit->setPlainText(response->errorString());
           ui->textEdit->setPlainText(response->errorString());
       }
       response->deleteLater();
    });
}
