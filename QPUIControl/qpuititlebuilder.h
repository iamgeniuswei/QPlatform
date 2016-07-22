#ifndef QPUITITLEBUILDER_H
#define QPUITITLEBUILDER_H

#include <QObject>
#include "qpuicontrol_global.h"
class QPUITitle;

class QPUICONTROLSHARED_EXPORT QPUITitleBuilder : public QObject
{
    Q_OBJECT
public:
    explicit QPUITitleBuilder(QObject *parent = 0);
    virtual void buildLogo(){}
    virtual void buildText(){}
    virtual void buildUserBtn(){}
    virtual void buildSysBtn(){}
    virtual QPUITitle* getTitleInstance()
    {
        return nullptr;
    }

signals:

public slots:
};

#endif // QPUITITLEBUILDER_H
