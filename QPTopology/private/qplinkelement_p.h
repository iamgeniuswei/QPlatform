#ifndef QPLINKELEMENT_P_H
#define QPLINKELEMENT_P_H
#include "qptopologynode_p.h"
#include <QObject>
#include <QPen>
class QPLinkElement;
class QPTopologyNode;
class TestItem;
class QPLinkElementPrivate
{
    Q_DECLARE_PUBLIC(QPLinkElement)
public:
    QPLinkElementPrivate (QPLinkElement *parent = 0)
        : q_ptr(parent),
          from(nullptr), to(nullptr)
        {}
public:
    QLineF line;
    QPen pen;
    QPTopologyNode *from;
    QPTopologyNode *to;
    TestItem *f1;
    TestItem *t1;
private:

    QPLinkElement *const q_ptr;
};


#endif // QPLINKELEMENT_P_H
