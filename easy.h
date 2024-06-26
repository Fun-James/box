#ifndef EASY_H
#define EASY_H

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
#include "score.h"

namespace Ui {
class Easy;
}

class Easy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Easy(QWidget *parent = nullptr);
    ~Easy();
    void paintEvent(QPaintEvent *event);
    QTime getTime()
    {
        return timeElapsed;
    }

private:
    Ui::Easy *ui;
    QTimer *timer;
    QTime timeElapsed;
    QLabel *timeLabel;
    void updateTimer();
    void onPairMatched();
    void stopTimer() ;
    bool checkAllMatched();
    QPixmap backgroundPixmap;
    void showScore();

private slots:
    void onTimerTimeout();
};

#endif // EASY_H
