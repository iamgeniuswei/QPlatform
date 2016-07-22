#ifndef QPCABINETNODE_H
#define QPCABINETNODE_H
#include "qptopology_global.h"
#include "qptopologynode.h"
#include "qpnode.h"
class QPTOPOLOGY_EXPORT QPCabinetNode : public QPNode
{
public:
    QPCabinetNode();

    QPointF getDeployPoint() const;
    void setDeployPoint(const QPointF &value);
    void setDeployPoint(qreal x, qreal y);

private:
    QPointF deployPoint;

};

#endif // QPCABINETNODE_H
