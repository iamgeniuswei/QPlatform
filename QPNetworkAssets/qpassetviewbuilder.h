#ifndef QPASSETVIEWBUILDER_H
#define QPASSETVIEWBUILDER_H

#include "qpuiviewbuilder.h"
#include "qpnetworkassets_global.h"

class QPNETWORKASSETSSHARED_EXPORT QPAssetViewBuilder : public QPUIViewBuilder
{
    Q_OBJECT
public:
    explicit QPAssetViewBuilder(QObject *parent = 0);
    void buildView();
    QPUIView *getUIView();

signals:

public slots:

private:
    QPUIView *assetView;
};

#endif // QPASSETVIEWBUILDER_H
