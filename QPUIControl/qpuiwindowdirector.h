#ifndef QPUIWINDOWDIRECTOR_H
#define QPUIWINDOWDIRECTOR_H

#include <QObject>
#include "qpuicontrol_global.h"
class QPUIWindowBuilder;
class QPUICONTROLSHARED_EXPORT QPUIWindowDirector : public QObject
{
    Q_OBJECT
public:
    explicit QPUIWindowDirector(QObject *parent = 0);
    virtual void buildWindow(QPUIWindowBuilder *_builder);

signals:

public slots:
};

#endif // QPUIWINDOWDIRECTOR_H
