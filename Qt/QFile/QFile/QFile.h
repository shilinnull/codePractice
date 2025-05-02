#pragma execution_character_set("utf-8")
#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QFile.h"

#include <QPlainTextEdit>
#include <QFont>
#include <QFileDialog>
#include <QWheelEvent>


class myQFile : public QMainWindow
{
    Q_OBJECT

public:
    myQFile(QWidget *parent = nullptr);
    ~myQFile();

    void handleAction1();
    void handleAction2();


private:
    QPlainTextEdit* edit;
    Ui::QFileClass ui;
};
