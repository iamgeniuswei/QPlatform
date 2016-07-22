#ifndef QPMESSAGEBOXTITLEBUILDER_H
#define QPMESSAGEBOXTITLEBUILDER_H

#include "qpuititlebuilder.h"
class QPUITitle;
class QPMessageBoxTitleBuilderPrivate;
class QPMessageBoxTitleBuilder : public QPUITitleBuilder
{
    Q_OBJECT
public:
    explicit QPMessageBoxTitleBuilder(QObject *parent = 0);
    void buildLogo();
    void buildText();
    void buildSysBtn();
    QPUITitle *getTitleInstance();


signals:

public slots:

private:
    QPMessageBoxTitleBuilderPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPMessageBoxTitleBuilder)
};

#endif // QPMESSAGEBOXTITLEBUILDER_H
