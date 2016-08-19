#ifndef QPUITITLEBUILDER_H
#define QPUITITLEBUILDER_H

#include <QObject>
#include "qpuicontrol_global.h"
class QPUITitleBar;

class QPUICONTROLSHARED_EXPORT QPUITitleBarBuilder : public QObject
{
    Q_OBJECT
public:
    explicit QPUITitleBarBuilder(QObject *parent = 0);
    virtual void buildLogo(){}
    virtual void buildText(){}
    virtual void buildUserBtn(){}
    virtual void buildSysBtn(){}
    virtual QPUITitleBar* getTitleInstance()
    {
        return nullptr;
    }

signals:

public slots:
};

#endif // QPUITITLEBUILDER_H
