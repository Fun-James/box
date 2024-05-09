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
#include "score.h"

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
    QTime getTime()
    {
        return timeElapsed;
    }

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
    void showScore();


private slots:
    void onTimerTimeout();
};

#endif // MIDDLE_H
