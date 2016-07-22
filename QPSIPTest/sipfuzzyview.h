#ifndef SIPFUZZYVIEW_H
#define SIPFUZZYVIEW_H
#include "qpsiptest_global.h"
#include <QWidget>

namespace Ui {
class SIPFuzzyView;
}

class QPSIPTESTSHARED_EXPORT SIPFuzzyView : public QWidget
{
    Q_OBJECT

public:
    explicit SIPFuzzyView(QWidget *parent = 0);
    ~SIPFuzzyView();

private:
    Ui::SIPFuzzyView *ui;
};

#endif // SIPFUZZYVIEW_H
