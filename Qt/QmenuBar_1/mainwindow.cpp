#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <istream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("我的记事本");

    // 菜单
    QMenuBar* menubar = new QMenuBar(this);
    this->setMenuBar(menubar);

    QMenu* menu = new QMenu("文件");
    menubar->addMenu(menu);

    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("加载");
    menu->addAction(action1);
    menu->addAction(action2);

    // 创建中央控件
//    QTextEdit* edit = new QTextEdit(this);
//    this->setCentralWidget(edit);
//    edit->setPlaceholderText("此处写文本");

    // 连接信号槽
    connect(action1, &QAction::triggered, this, &MainWindow::save);
    connect(action2, &QAction::triggered, this, &MainWindow::load);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    QFileDialog* dialog = new QFileDialog(this);
    QString filename = dialog->getSaveFileName(this, "保存文件", "F:/code-exercise/Qt/QmenuBar_1/");
    qDebug() << "filename: " << filename;

    // 写入文件
    std::ofstream file(filename.toStdString().c_str());

    const QString& text = ui->textEdit->toPlainText();
    file << text.toStdString();
    file.close();
}

void MainWindow::load()
{
    QFileDialog* dialog = new QFileDialog(this);
    QString filename = dialog->getOpenFileName(this, "加载文件", "F:/code-exercise/Qt/QmenuBar_1/");
    qDebug() << "filename: " << filename;

    // 加载文件
    std::ifstream file(filename.toStdString().c_str());

    std::string content, line;
    while (std::getline(file, line)) {
        content += line;
        content += "\n";
    }
    ui->textEdit->setText(content.c_str());
    file.close();
}

