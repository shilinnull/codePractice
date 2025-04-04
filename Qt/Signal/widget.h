#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void HandleClicked();
signals:
    void mySignal();
private slots:

    void on_pushButton_clicked();
    void HandleMySignal();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
