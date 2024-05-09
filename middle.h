#ifndef MIDDLE_H
#define MIDDLE_H

#include <QMainWindow>
#include <QWidget>
#include <QVector>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include "box.h"
#include "figure.h"
#include <QPaintevent>
#include <QRect>
#include <QPixmap>
#include <QPainter>

namespace Ui {
class Middle;
}

class Middle : public QMainWindow
{
    Q_OBJECT

public:
    explicit Middle(QWidget *parent = nullptr);
    ~Middle();
    void paintEvent(QPaintEvent *event);


private:
    Ui::Middle *ui;
    QTimer *timer;
    QTime timeElapsed;
    QLabel *timeLabel;
    void updateTimer();
    void onPairMatched();
    void stopTimer() ;
    bool checkAllMatched();
    QPixmap backgroundPixmap;


private slots:
    void onTimerTimeout();
};

#endif // MIDDLE_H
