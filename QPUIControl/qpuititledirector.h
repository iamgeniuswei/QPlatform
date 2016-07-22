#ifndef QPUITITLEDIRECTOR_H
#define QPUITITLEDIRECTOR_H

#include <QObject>
#include "qpuicontrol_global.h"
class QPUITitleBuilder;
class QPUICONTROLSHARED_EXPORT QPUITitleDirector : public QObject
{
    Q_OBJECT
public:
    explicit QPUITitleDirector(QObject *parent = 0);
    virtual void buildTitle(QPUITitleBuilder *builder);

signals:

public slots:
};

#endif // QPUITITLEDIRECTOR_H
