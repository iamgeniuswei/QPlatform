#ifndef QPMAINTITLEBUILDER_H
#define QPMAINTITLEBUILDER_H

#include "qpuititlebuilder.h"
#include "qpmainframe_global.h"
class QPUITitle;
class QPMainTitleBuilderPrivate;
class QPMAINFRAMESHARED_EXPORT QPMainTitleBuilder : public QPUITitleBuilder
{
    Q_OBJECT
public:
    explicit QPMainTitleBuilder(QObject *parent = 0);
    void buildLogo();
    void buildText();
    void buildUserBtn();
    void buildSysBtn();
    QPUITitle *getTitleInstance();

signals:

public slots:
private:
    QPMainTitleBuilderPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPMainTitleBuilder)
};

#endif // QPMAINTITLEBUILDER_H
