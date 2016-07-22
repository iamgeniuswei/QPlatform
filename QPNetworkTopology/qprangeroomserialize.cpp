#include "qprangeroomserialize.h"
#include <QXmlStreamWriter>
#include <QVector>
#include "qpcabinetnode.h"
QPRangeRoomSerialize::QPRangeRoomSerialize():QPXMLSerialize(),vector(nullptr)
{
    saveXMLFile("D:\\icon\\room.xml");
}

QPRangeRoomSerialize::~QPRangeRoomSerialize()
{
    closeXMLFile();
}

void QPRangeRoomSerialize::serialize()
{
    xmlWriter->writeStartDocument();
    xmlWriter->writeStartElement("RangeRoom");

    if(vector)
    {
        QVectorIterator<QPCabinetNode*> iterator(*vector);
        while (iterator.hasNext()) {
            QPCabinetNode *node = iterator.next();
            if(node)
            {
                serializeCabinet(node);
            }
        }
    }


    xmlWriter->writeEndDocument();
    closeXMLFile();
}

void QPRangeRoomSerialize::serializeCabinet(QPCabinetNode *node)
{
    xmlWriter->writeStartElement("Node");
    xmlWriter->writeTextElement("type", "Cabinet");
    xmlWriter->writeTextElement("name", node->getNodeName());
    xmlWriter->writeTextElement("sn", node->getNodeSN());
    xmlWriter->writeEmptyElement("pos");
    xmlWriter->writeAttribute("x", QString::number(node->getDeployPoint().x()));
    xmlWriter->writeAttribute("y", QString::number(node->getDeployPoint().y()));
    xmlWriter->writeEndElement();
}
QVector<QPCabinetNode *> *QPRangeRoomSerialize::getVector() const
{
    return vector;
}

void QPRangeRoomSerialize::setVector(QVector<QPCabinetNode *> *value)
{
    vector = value;
}


