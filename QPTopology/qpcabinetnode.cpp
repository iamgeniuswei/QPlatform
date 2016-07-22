#include "qpcabinetnode.h"

QPCabinetNode::QPCabinetNode()
{

}
QPointF QPCabinetNode::getDeployPoint() const
{
    return deployPoint;
}

void QPCabinetNode::setDeployPoint(const QPointF &value)
{
    deployPoint = value;
}

void QPCabinetNode::setDeployPoint(qreal x, qreal y)
{
    deployPoint = QPointF(x, y);
}


