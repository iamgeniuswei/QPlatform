#include "qpswitchnode.h"

QPSwitchNode::QPSwitchNode(const QString &name, const QString &sn):QPNode(name,sn)
{
    setNodeType(SWITCH);
}

