#ifndef QPASSETDETAILBUILDER_H
#define QPASSETDETAILBUILDER_H

#include "qpuiviewbuilder.h"

class QPAssetDetailBuilder : public QPUIViewBuilder
{
    Q_OBJECT
public:
    explicit QPAssetDetailBuilder(QObject *parent = 0);
    void buildView();
    QPUIView *getUIView();

signals:

public slots:

private:
    QPUIView *detailView;
};

#endif // QPASSETDETAILBUILDER_H
