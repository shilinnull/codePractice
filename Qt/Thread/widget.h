#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "timethread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_pushButton_clicked();

private:

    void showTime(QString time);
private:
    Ui::Widget *ui;
    TimeThread t;
};
#endif // WIDGET_H
