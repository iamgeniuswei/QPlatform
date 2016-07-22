#include "form.h"
#include "ui_form.h"
#include "qprangeroomxmlparser.h"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QPRangeRoomDeserialize *parser = new QPRangeRoomDeserialize;
    parser->deSerialize();
}
