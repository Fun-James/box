#include "people.h"
#include "ui_people.h"

People::People(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::People)
{
    ui->setupUi(this);
}

People::~People()
{
    delete ui;
}
