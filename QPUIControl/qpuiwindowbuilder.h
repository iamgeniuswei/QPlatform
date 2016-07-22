#ifndef QPUIWINDOWBUILDER_H
#define QPUIWINDOWBUILDER_H

#include <QObject>
#include "qpuicontrol_global.h"
class QPUIWindow;
class QPUICONTROLSHARED_EXPORT QPUIWindowBuilder : public QObject
{
    Q_OBJECT
public:
    explicit QPUIWindowBuilder(QObject *parent = 0);
    virtual void buildTitle(){}
    virtual void buildNavigationBar(){}
    virtual void buildContentArea(){}
    virtual void buildStatusBar(){}
    virtual QPUIWindow* getWindowInstance()
    {
        return nullptr;
    }

signals:

public slots:
};

#endif // QPUIWINDOWBUILDER_H
