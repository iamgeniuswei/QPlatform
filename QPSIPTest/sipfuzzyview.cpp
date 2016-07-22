#include "sipfuzzyview.h"
#include "ui_sipfuzzyview.h"

SIPFuzzyView::SIPFuzzyView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SIPFuzzyView)
{
    ui->setupUi(this);
}

SIPFuzzyView::~SIPFuzzyView()
{
    delete ui;
}
