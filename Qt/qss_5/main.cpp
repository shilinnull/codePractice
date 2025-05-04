#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet("QLabel { font-size:30px; border:10px solid red; padding-left: 20px; }");


    Widget w;
    w.show();
    return a.exec();
}
