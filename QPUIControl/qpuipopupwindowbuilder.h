#ifndef QPUIPOPUPWINDOWBUILDER_H
#define QPUIPOPUPWINDOWBUILDER_H

#include <QObject>
#include "qpuicontrol_global.h"
class QPUIPopupWindow;
class QPUICONTROLSHARED_EXPORT QPUIPopupWindowBuilder : public QObject
{
    Q_OBJECT
public:
    explicit QPUIPopupWindowBuilder(QObject *parent = 0);
    virtual void buildTitle(){}
    virtual void buildContentArea(){}
    virtual QPUIPopupWindow *getPopupWindow()
    {
        return nullptr;
    }

signals:

public slots:
};

#endif // QPUIPOPUPWINDOWBUILDER_H
