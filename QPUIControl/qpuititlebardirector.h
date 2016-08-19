#ifndef QPUITITLEDIRECTOR_H
#define QPUITITLEDIRECTOR_H

#include <QObject>
#include "qpuicontrol_global.h"
class QPUITitleBarBuilder;
class QPUICONTROLSHARED_EXPORT QPUITitleBarDirector : public QObject
{
    Q_OBJECT
public:
    explicit QPUITitleBarDirector(QObject *parent = 0);
    virtual void buildTitle(QPUITitleBarBuilder *builder);

signals:

public slots:
};

#endif // QPUITITLEDIRECTOR_H
