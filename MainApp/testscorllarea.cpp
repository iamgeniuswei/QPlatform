#include "testscorllarea.h"
#include "ui_testscorllarea.h"

TestScorllArea::TestScorllArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestScorllArea)
{
    ui->setupUi(this);
}

TestScorllArea::~TestScorllArea()
{
    delete ui;
}
