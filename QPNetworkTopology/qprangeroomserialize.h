#ifndef QPRANGEROOMSERIALIZE_H
#define QPRANGEROOMSERIALIZE_H

#include "qpxmlserialize.h"
class QPCabinetNode;

class QPRangeRoomSerialize : public QPXMLSerialize
{
public:
    QPRangeRoomSerialize();
    ~QPRangeRoomSerialize();
    void serialize();
    void serializeCabinet(QPCabinetNode *node);
    QVector<QPCabinetNode *> *getVector() const;
    void setVector(QVector<QPCabinetNode *> *value);

private:
    QVector<QPCabinetNode*> *vector;
};

#endif // QPRANGEROOMSERIALIZE_H
