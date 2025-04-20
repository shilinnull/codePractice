#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建 6 个按钮
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    QPushButton* btn3 = new QPushButton("按钮3");
    QPushButton* btn4 = new QPushButton("按钮4");
    QPushButton* btn5 = new QPushButton("按钮5");
    QPushButton* btn6 = new QPushButton("按钮6");
    // 设置按钮的 sizePolicy, 此时按钮的水平方向和垂直方向都会尽量舒展开
    btn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 创建网格布局管理器, 并且添加元素
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(btn1, 0, 0);
    layout->addWidget(btn2, 0, 1);
    layout->addWidget(btn3, 1, 0);
    layout->addWidget(btn4, 1, 1);
    layout->addWidget(btn5, 2, 0);
    layout->addWidget(btn6, 2, 1);

    // 设置拉伸比例
    // 第 0 行拉伸比例设为 1;
    layout->setRowStretch(0, 1);
    // 第 1 行拉伸比例设为 0, 即为固定大小, 不参与拉伸
    layout->setRowStretch(1, 0);
    // 第 2 行拉伸比例设为 3, 即为第 2 行的宽度是第 0 行的 3 倍
    layout->setRowStretch(2, 3);

    // 设置 layout 到窗口中.
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

