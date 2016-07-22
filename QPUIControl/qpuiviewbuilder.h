#ifndef QPUIVIEWBUILDER_H
#define QPUIVIEWBUILDER_H

#include <QObject>
#include "qpuicontrol_global.h"

class QPUIView;
class QPUICONTROLSHARED_EXPORT QPUIViewBuilder : public QObject
{
    Q_OBJECT
public:
    explicit QPUIViewBuilder(QObject *parent = 0);
    virtual void buildView() = 0;
    virtual QPUIView *getUIView()
    {
        return nullptr;
    }

signals:

public slots:
};

#endif // QPUIVIEWBUILDER_H
