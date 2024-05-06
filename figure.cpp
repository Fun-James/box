#include "figure.h"
#include "ui_figure.h"

Figure::Figure(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Figure)
{
    ui->setupUi(this);
    ui->bubble->hide();
    ui->numberLabel->hide();
}

Figure::~Figure()
{
    delete ui;
}

void Figure::enterEvent(QEnterEvent *event)
{
    ui->bubble->show();
    ui->numberLabel->show();
}

void Figure::leaveEvent(QEvent *event)
{
    ui->bubble->hide();
    ui->numberLabel->hide();

}

void Figure::setFigureNumber(int n)
{
    fignumber=n;
    ui->numberLabel->setText(QString::number(fignumber));
}
