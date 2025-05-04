#include "widget.h"

#include <QApplication>
#include <QFile>


QString loadQss()
{
    QFile file(":/new/prefix1/style.qss");
    file.open(QFile::ReadOnly);
    QString style = file.readAll();
    file.close();
    return style;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    a.setStyleSheet("QPushButton{ color: green; }");
    a.setStyleSheet(loadQss());

    Widget w;
    w.show();
    return a.exec();
}
