#ifndef QPUIASSETSUMMARYLABEL_H
#define QPUIASSETSUMMARYLABEL_H

#include "qpuiview.h"
#include "qpuicontrol_global.h"
class QPUIAssetSummaryLabelPrivate;
class QPUICONTROLSHARED_EXPORT QPUIAssetSummaryLabel : public QPUIView
{
    Q_OBJECT
public:
    explicit QPUIAssetSummaryLabel(QWidget *parent = 0);
    void initilizeUI();
    void setAssetName(const QString &name);
    void setAssetType(const QString &type);
    void setAssetAttr1(const QString &value);
    void setAssetAttr2(const QString &value);
    void setAssetAttr3(const QString &value);
    void setAssetAttr4(const QString &value);

signals:

public slots:

private:
    Q_DECLARE_PRIVATE(QPUIAssetSummaryLabel)
};

#endif // QPUIASSETSUMMARYLABEL_H
