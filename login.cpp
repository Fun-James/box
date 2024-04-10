#include "login.h"
#include "./ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setFixedSize(650,400);
    ui->labelWelcome->hide();
    ui->labelName->hide();
    ui->widget_5->hide();
    QPushButton *btngo=ui->pushGo;
    connect(btngo,&QPushButton::clicked,this,&Login::Push_on_Go);
    QPushButton *btneasy=ui->pushEasy;
    connect(btneasy,&QPushButton::clicked,this,&Login::Push_on_Easy);

}

Login::~Login()
{
    delete ui;
}

void Login::Push_on_Go()
{
    QString name;
    name=ui->lineEditName->text();
    ui->labelName->setText(name);

    ui->labelWelcome->show();

    QTimer::singleShot(700,this,[=](){
        ui->labelName->show();
    });

    QTimer::singleShot(1600,this,[=](){
        ui->widget_5->show();
    });

}

void Login::Push_on_Easy()
{
    Easy *e=new Easy();
    this->close();
    e->show();
}
