#ifndef EASY_H
#define EASY_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class Easy;
}

class Easy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Easy(QWidget *parent = nullptr);
    ~Easy();

private:
    Ui::Easy *ui;
};

#endif // EASY_H
