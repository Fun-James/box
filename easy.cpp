#include "easy.h"
#include "ui_easy.h"

Easy::Easy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Easy)
{
    ui->setupUi(this);

}

Easy::~Easy()
{
    delete ui;
}
