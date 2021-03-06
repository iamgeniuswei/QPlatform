#ifndef QPNODE_H
#define QPNODE_H
#include "qptopology_global.h"
#include "misc_enum.h"
#include <QString>
class QPTOPOLOGY_EXPORT QPNode
{
public:
    virtual ~QPNode(){}
    void setNodeName(const QString& name);
    QString getNodeName() const;

    void setNodeSN(const QString &sn);
    QString getNodeSN() const;


    virtual void Add(QPNode *);
    virtual void Remove(QPNode *);
    virtual QPNode *getChild(int i);

public:
    QPNode(const QString &name, const QString &sn);
    QPNode();

    NODETYPE getNodeType() const;
    void setNodeType(const NODETYPE &value);

private:
    QString nodeName;
    QString nodeSerialN;
    NODETYPE nodeType;


};

#endif // QPNODE_H
