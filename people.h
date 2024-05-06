#ifndef PEOPLE_H
#define PEOPLE_H

#include <QWidget>

namespace Ui {
class People;
}

class People : public QWidget
{
    Q_OBJECT

public:
    explicit People(QWidget *parent = nullptr);
    ~People();

private:
    Ui::People *ui;
};

#endif // PEOPLE_H
