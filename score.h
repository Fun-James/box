#ifndef SCORE_H
#define SCORE_H

#include <QDialog>
#include <QTime>

namespace Ui {
class Score;
}

class Score : public QDialog
{
    Q_OBJECT

public:
    explicit Score(QWidget *parent = nullptr);
    ~Score();
    void setTime(QTime time);

private:
    Ui::Score *ui;
    QTime t;
};

#endif // SCORE_H
