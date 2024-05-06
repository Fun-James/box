#include "easy.h"
#include "ui_easy.h"

Easy::Easy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Easy)
    ,timeElapsed(0, 0)
{
    //计时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Easy::onTimerTimeout);

    timeLabel = new QLabel("00:00", this);
    timeLabel->move(800, 620);  // 临时设置到右上角，你可能需要根据你的布局调整位置
    // 设置字体和加粗
    QFont font("Arial", 30, QFont::Bold);
    timeLabel->setFont(font);

    // 设置字号和颜色
    timeLabel->setStyleSheet("font-size: 20px; color: blue;");

    timeLabel->show();

    timer->start(1000);


    ui->setupUi(this);
    setFixedSize(900,670);
    QVector<int> boxNumbers;
    for (int i = 1; i <= 9; i++) {
        QString boxName = QString("box%1").arg(i);
        Box* box = findChild<Box*>(boxName);
        if (box) {
            boxNumbers.append(box->getNumber());
        }
    }
    // 使用随机数生成器对boxNumbers进行随机化排序
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(boxNumbers.begin(), boxNumbers.end(), rng);

    // 将乱序后的number赋值给Figure
    for (int i = 1; i <= 9; i++) {
        QString figName = QString("bird%1").arg(i);
        Figure *figure = findChild<Figure*>(figName);
        if (figure && i <= boxNumbers.size()) {
            figure->setFigureNumber(boxNumbers[i - 1]);
        }
    }
}

Easy::~Easy()
{
    delete ui;
    delete timer;
    delete timeLabel;
}

void Easy::onTimerTimeout() {
    timeElapsed = timeElapsed.addSecs(1);
    updateTimer();
}

void Easy::updateTimer() {
    timeLabel->setText(timeElapsed.toString("mm:ss"));
}
