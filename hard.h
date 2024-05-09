#ifndef HARD_H
#define HARD_H

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
class Hard;
}

class Hard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hard(QWidget *parent = nullptr);
    ~Hard();
    void paintEvent(QPaintEvent *event);
    QTime getTime()
    {
        return timeElapsed;
    }

private:
    Ui::Hard *ui;
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

#endif // HARD_H
