#include "testform.h"
#include "ui_testform.h"

TestForm::TestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestForm)
{
    ui->setupUi(this);
    setFixedSize(200,48);
    setWindowFlags(Qt::FramelessWindowHint);
}

TestForm::~TestForm()
{
    delete ui;
}
