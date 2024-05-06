#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include <QMouseEvent>
#include <QPoint>
#include <Qvector>

namespace Ui {
class Figure;
}

class Figure : public QWidget
{
    Q_OBJECT

public:
    explicit Figure(QWidget *parent = nullptr);
    ~Figure();

    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void setFigureNumber(int n);
private:
    Ui::Figure *ui;
    int fignumber;

};

#endif // FIGURE_H
