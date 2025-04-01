#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


//    QLabel* lable = new QLabel(this);
//    lable->setText("hello world");


//    // 输入框
//    QLineEdit* edit = new QLineEdit(this);
//    edit->setText("hello world");

    // 点击按钮后的反应
     connect(ui->myButton,&QPushButton::clicked,this,&Widget::handleClick);
    myButton1 = new QPushButton(this);
    myButton1->setText("hello world");
    connect(myButton1,&QPushButton::clicked,this,&Widget::MyhandleClick);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    if(ui->myButton->text() == QString("hello world")){
        ui->myButton->setText("hello Qt");
    }else{
        ui->myButton->setText("hello world");
    }
}


void Widget::MyhandleClick()
{
    if(myButton1->text() == QString("hello world")){
        myButton1->setText("hello Qt");
    }else{
        myButton1->setText("hello world");
    }
}

