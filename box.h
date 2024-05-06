#ifndef BOX_H
#define BOX_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QRandomGenerator>
#include <QString>
#include <QMouseEvent>
#include <QPoint>
#include <QDebug>
#include <QPropertyAnimation>
#include <Qvector>
#include "figure.h"

namespace Ui {
class Box;
}

class Box : public QWidget
{
    Q_OBJECT

public:
    explicit Box(QWidget *parent = nullptr);
    ~Box();
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void onTimeout();
    int rnumber;
    int getNumber();
private:
    Ui::Box *ui;
    QGraphicsOpacityEffect *oeffect=new QGraphicsOpacityEffect;
    int status=0;
    QPoint dragStartPosition; // 用于保存拖动起始位置
    bool dragging;            // 标志是否正在拖动
    QTimer *timer;
    bool isEntered;
};

#endif // BOX_H
