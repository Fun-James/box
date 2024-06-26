#include "figure.h"
#include "ui_figure.h"

Figure::Figure(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Figure)
    ,disappear(false)
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

bool Figure::isOverlap(const QRect& boxRect)
{
    QRect figureRect = geometry();
    QRect intersectRect = figureRect.intersected(boxRect);
    int overlapArea = intersectRect.width() * intersectRect.height();
    int boxArea = boxRect.width() * boxRect.height();
    double overlapRatio = static_cast<double>(overlapArea) / boxArea;
    if(overlapRatio >= 0.6)
    {
        disappear=true;
        return true; // 重合面积占Box面积的60%以上视为大部分重合
    }
    else
    {
        return false;
    }
}
