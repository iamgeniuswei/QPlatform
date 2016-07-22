#ifndef QPSWITCHNODE_H
#define QPSWITCHNODE_H
#include "qpnode.h"

class QPTOPOLOGY_EXPORT QPSwitchNode : public QPNode
{
public:
    QPSwitchNode(const QString& name, const QString &sn);
};

#endif // QPSWITCHNODE_H
