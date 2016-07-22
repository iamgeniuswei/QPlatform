#include "qprouternode.h"

QPRouterNode::QPRouterNode(const QString &name, const QString &sn) : QPNode(name, sn)
{
    setNodeType(ROUTER);
}

