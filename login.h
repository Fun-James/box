#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<QWidget>
#include<QString>
#include<QTimer>
#include"easy.h"
#include <QPixmap>
#include <QPainter>
#include<QRect>
#include<QPaintEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void paintEvent(QPaintEvent *event);

public slots:
    void Push_on_Go();
    void Push_on_Easy();

private:
    Ui::Login *ui;
    QPixmap backgroundPixmap;
};
#endif // LOGIN_H
