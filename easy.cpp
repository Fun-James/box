#include "easy.h"
#include "ui_easy.h"

Easy::Easy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Easy)
{
    ui->setupUi(this);
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
}
