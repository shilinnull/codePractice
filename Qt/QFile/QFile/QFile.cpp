#include "QFile.h"

myQFile::myQFile(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->setWindowTitle("简单的记事本");
    
    QMenuBar* menubar = this->menuBar();
    // 添加菜单
    QMenu* menu = new QMenu("文件");
    menubar->addMenu(menu);

    QAction* action1 = new QAction("打开");
    QAction* action2 = new QAction("保存");
    menu->addAction(action1);
    menu->addAction(action2);

    // 输入框
    edit = new QPlainTextEdit();
    QFont font;
    font.setPixelSize(20);
    edit->setFont(font);
    
    this->setCentralWidget(edit);

    // 连接信号
    connect(action1, &QAction::triggered, this, &myQFile::handleAction1);
    connect(action2, &QAction::triggered, this, &myQFile::handleAction2);
}

myQFile::~myQFile()
{}

void myQFile::handleAction1()
{
    QString path = QFileDialog::getOpenFileName(this);
    QStatusBar* statusBar = this->statusBar();
    statusBar->showMessage(path);

    QFile file(path);
    bool ret = file.open(QIODevice::ReadOnly);
    if (!ret)
    {
        statusBar->showMessage(path + "打开失败！");
        return;
    }
    // 读取文件
    QString text = file.readAll();
    edit->setPlainText(text); // 设置文本

    file.close();
}

void myQFile::handleAction2()
{
    QString path = QFileDialog::getSaveFileName(this);

    QStatusBar* statusBar = this->statusBar();

    QFile file(path);
    bool ret = file.open(QFile::WriteOnly);
    if (!ret)
    {
        statusBar->showMessage(path + "打开失败！");
        return;
    }

    // 写文件
    const QString& text = edit->toPlainText();
    file.write(text.toUtf8());

    file.close();
}

