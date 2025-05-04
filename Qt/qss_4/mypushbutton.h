#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MyPushButton : public QPushButton
{
public:
    MyPushButton(QWidget* parent);

    void mousePressEvent(QMouseEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e)override;
    void enterEvent(QEvent* e)override;
    void leaveEvent(QEvent* e)override;


};

#endif // MYPUSHBUTTON_H
