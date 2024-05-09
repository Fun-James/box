#include "hard.h"
#include "ui_hard.h"

Hard::Hard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hard)
     ,timeElapsed(0, 0)
{

    //计时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Hard::onTimerTimeout);

    timeLabel = new QLabel("00:00", this);
    timeLabel->move(900, 750);  // 临时设置到右上角，你可能需要根据你的布局调整位置
    // 设置字体和加粗
    QFont font("Arial", 30, QFont::Bold);
    timeLabel->setFont(font);

    // 设置字号和颜色
    timeLabel->setStyleSheet("font-size: 20px; color: blue;");

    timeLabel->show();

    //设置背景
    backgroundPixmap.load(":/box/img/light_colorful.png");
    this->setAutoFillBackground(true);

    timer->start(1000);

    ui->setupUi(this);
    setFixedSize(1000,820);
    // 随机生成前两位数字
    int prefix = QRandomGenerator::global()->bounded(10, 100);

    QVector<int> boxNumbers;
    for (int i = 1; i <= 14; i++) {
        QString boxName = QString("box%1").arg(i);
        Box* box = findChild<Box*>(boxName);
        if (box) {
            box->hardModeReset(prefix);
            boxNumbers.append(box->getNumber());
        }
    }
    // 使用随机数生成器对boxNumbers进行随机化排序
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(boxNumbers.begin(), boxNumbers.end(), rng);

    // 将乱序后的number赋值给Figure
    for (int i = 1; i <= 14; i++) {
        QString figName = QString("bird%1").arg(i);
        Figure *figure = findChild<Figure*>(figName);
        if (figure && i <= boxNumbers.size()) {
            figure->setFigureNumber(boxNumbers[i - 1]);
        }
    }
}

Hard::~Hard()
{
    delete ui;
    delete timer;
    delete timeLabel;
}


void Hard::onTimerTimeout() {
    timeElapsed = timeElapsed.addSecs(1);
    updateTimer();
    if (checkAllMatched())
    {
        timer->stop(); // 停止计时器
        QTimer::singleShot(700, this, &Hard::showScore); // 延迟500毫秒调用showScore函数
    }
}

void Hard::updateTimer() {
    timeLabel->setText(timeElapsed.toString("mm:ss"));
}

bool Hard::checkAllMatched() {
    for (int i = 1; i <= 14; i++) {
        QString figName = QString("bird%1").arg(i);
        Figure *figure = findChild<Figure*>(figName);
        if (figure->isMatched()==false) {
            return false; // 如果有任何未匹配的Figure，返回false
        }
    }
    return true; // 所有Figure都已匹配
}


void Hard::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);  // 调用基类的paintEvent以处理默认绘制行为

    QPainter painter(this);
    QRect rect = this->rect();  // 获取当前窗口的矩形区域
    QPixmap scaledPixmap = backgroundPixmap.scaled(rect.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(rect, scaledPixmap);

}

void Hard::showScore()
{
    Score *s=new Score;
    s->setTime(getTime());
    this->close(); // 关闭当前窗口
    s->show(); // 显示Score窗口
}

