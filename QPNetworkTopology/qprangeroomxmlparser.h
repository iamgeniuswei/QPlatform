#ifndef QPRANGEROOMXMLPARSER_H
#define QPRANGEROOMXMLPARSER_H
#include "qpnetworktopology_global.h"
#include "qpxmlhelper.h"
#include "tinyxml2.h"
using namespace tinyxml2;
class QPCabinetNode;
class QPNode;
class QPNETWORKTOPOLOGYSHARED_EXPORT QPRangeRoomDeserialize : public QPXMLDeserialize
{
public:
    QPRangeRoomDeserialize();
    ~QPRangeRoomDeserialize();
    void deSerialize();
    void deSerializeRangeRoom();
    void deSerializeCabinetNode(QPCabinetNode *node);
    void deSerializeDevice(QPNode *node);

    QVector<QPCabinetNode *> *getVector();
    void setVector(QVector<QPCabinetNode *> *value);

private:
    QVector<QPCabinetNode*> *vector;
};

#endif // QPRANGEROOMXMLPARSER_H
