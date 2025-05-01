#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget* parent);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // LABEL_H
