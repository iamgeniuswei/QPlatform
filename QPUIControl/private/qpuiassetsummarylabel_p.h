#ifndef QPUIASSETSUMMARYLABEL_P
#define QPUIASSETSUMMARYLABEL_P
#include "qpuiview_p.h"
class QPUIAssetSummaryLabel;
class QLabel;
class QPUIAssetSummaryLabelPrivate : public QPUIViewPrivate
{
public:
    QPUIAssetSummaryLabelPrivate(QPUIAssetSummaryLabel *parent = 0)
        : q_ptr(parent), QPUIViewPrivate(parent),assetName(nullptr), \
          assetAttr1(nullptr), assetAttr2(nullptr),assetAttr3(nullptr),assetAttr4(nullptr)
    {

    }
    void init();
public:
    QLabel *assetName;
    QLabel *assetType;
    QLabel *assetAttr1;
    QLabel *assetAttr2;
    QLabel *assetAttr3;
    QLabel *assetAttr4;
    QLabel *separator;
    QString strName;
    QString strType;
    QString strAttr1;
    QString strAttr2;
    QString strAttr3;
    QString strAttr4;

private:
    QPUIAssetSummaryLabel *const q_ptr;
};
#endif // QPUIASSETSUMMARYLABEL_P

