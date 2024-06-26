#include "box.h"
#include "ui_box.h"

Box::Box(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Box)
    , dragging(false)
    ,isEntered(false)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Box::onTimeout);
    ui->setupUi(this);
    ui->boxMid->hide();
    ui->boxOpen->hide();
    ui->bubble->setGraphicsEffect(oeffect);
    oeffect->setOpacity(0);
    ui->numberLabel->hide();


    rnumber=QRandomGenerator::global()->bounded(90000000) + 10000000;

    // 将int转换为QString并设置到label上
    ui->numberLabel->setText(QString::number(rnumber));

}

Box::~Box()
{
    delete ui;
}

void Box::enterEvent(QEnterEvent *event)
{
    if (!isEntered) {
        isEntered = true;
        ui->boxClose->hide();
        ui->boxMid->show();
        oeffect->setOpacity(0.5);
        timer->start(200);
    }
}

void Box::leaveEvent(QEvent *event)
{
    if (isEntered) {
        isEntered = false;
        timer->stop();
        ui->boxOpen->hide();
        ui->boxMid->show();
        oeffect->setOpacity(0.4);
        ui->numberLabel->hide();
        QTimer::singleShot(200, this, [=](){
            if (!isEntered) {
                ui->boxMid->hide();
                oeffect->setOpacity(0);
                ui->boxClose->show();
            }
        });
    }
}

void Box::onTimeout()
{
    if (isEntered) {
        ui->boxMid->hide();
        ui->boxOpen->show();
        ui->numberLabel->show();
        oeffect->setOpacity(1);
    }
}

void Box::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragStartPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
    }
}

void Box::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dragging) {
        QPoint newPos = event->globalPosition().toPoint() - dragStartPosition;
        move(newPos);

        QPoint bubblePos = ui->bubble->pos();
        ui->bubble->move(bubblePos);
    }
}

void Box::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    dragging = false;

    QRect boxRect = geometry();
    QList<Figure*> figures = parentWidget()->findChildren<Figure*>();
    for (Figure* figure : figures) {
        if (figure->isOverlap(boxRect)) {
            int figureNumber = figure->getNumber();
            if (figureNumber == rnumber) {
                hide();
                figure->hide();
                // 或者使用 deleteLater() 函数延迟删除对象
                // deleteLater();
                // figure->deleteLater();
                break;
            }
        }
    }
}

int Box::getNumber()
{
    return rnumber;
}

void Box::hardModeReset(int pre)
{
    // 随机生成后面 6 位数字
    int remainingSixDigits = QRandomGenerator::global()->bounded(100000, 1000000);

    // 拼接成完整的 8 位数q
    rnumber = pre * 1000000 + remainingSixDigits;
    ui->numberLabel->setText(QString::number(rnumber));
}
