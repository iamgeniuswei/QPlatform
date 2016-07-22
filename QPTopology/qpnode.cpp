#include "qpnode.h"

void QPNode::setNodeName(const QString &name)
{
    nodeName = name;
}

QString QPNode::getNodeName() const
{
    return nodeName;
}

void QPNode::setNodeSN(const QString &sn)
{
    nodeSerialN = sn;
}

QString QPNode::getNodeSN() const
{
    return nodeSerialN;
}

void QPNode::Add(QPNode *)
{

}

void QPNode::Remove(QPNode *)
{

}

QPNode *QPNode::getChild(int i)
{
    return nullptr;
}

QPNode::QPNode(const QString &name, const QString &sn):
    nodeName(name), nodeSerialN(sn)
{

}
NODETYPE QPNode::getNodeType() const
{
    return nodeType;
}

void QPNode::setNodeType(const NODETYPE &value)
{
    nodeType = value;
}






QPNode::QPNode()
{

}
