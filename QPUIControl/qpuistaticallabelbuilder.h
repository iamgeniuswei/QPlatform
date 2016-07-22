#ifndef QPUISTATICALLABELBUILDER_H
#define QPUISTATICALLABELBUILDER_H

#include "qpuiviewbuilder.h"
#include "qpuicontrol_global.h"
class QPUICONTROLSHARED_EXPORT QPUIStaticalLabelBuilder : public QPUIViewBuilder
{
    Q_OBJECT
public:
    explicit QPUIStaticalLabelBuilder(QObject *parent = 0);
    void buildView();
    QPUIView *getUIView();

signals:

public slots:

private:
    QPUIView *staticalLabel;
};

#endif // QPUISTATICALLABELBUILDER_H
