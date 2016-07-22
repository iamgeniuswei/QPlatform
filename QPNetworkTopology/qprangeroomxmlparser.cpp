#include "qprangeroomxmlparser.h"
#include <QXmlStreamReader>
#include "qpcabinetnode.h"
#include "qpnode.h"
#include <QDebug>
QPRangeRoomDeserialize::QPRangeRoomDeserialize()
{
    readXMLFile("D:\\icon\\room.xml");
    vector = new (std::nothrow) QVector<QPCabinetNode*>;
}

QPRangeRoomDeserialize::~QPRangeRoomDeserialize()
{
    closeXMLFile();
}

void QPRangeRoomDeserialize::deSerialize()
{
    if(xmlReader && xmlReader->readNextStartElement())
    {
        if(xmlReader->name() == "RangeRoom")
            deSerializeRangeRoom();
    }
}

void QPRangeRoomDeserialize::deSerializeRangeRoom()
{
    while (xmlReader->readNextStartElement())
    {
        if (xmlReader->name() == "Node")
        {
            QPCabinetNode *cabinet = new (std::nothrow) QPCabinetNode;
            vector->append(cabinet);
            if(cabinet)
                deSerializeCabinetNode(cabinet);
            else
                continue;
            xmlReader->skipCurrentElement();
        }
    }
}

void QPRangeRoomDeserialize::deSerializeCabinetNode(QPCabinetNode *node)
{
    //important
    //readElement is a pop function, only can be executed one time.
    //if is not executed, you have skipCurrentElement();
    while (xmlReader->readNextStartElement()) {
        if(xmlReader->name() == "type")
        {
            node->setNodeType(CABINET);
            xmlReader->skipCurrentElement();
        }
        else if(xmlReader->name() == "name")
            node->setNodeName(xmlReader->readElementText());
        else if(xmlReader->name() == "sn")
            node->setNodeSN(xmlReader->readElementText());
        else if(xmlReader->name() == "pos")
        {
            node->setDeployPoint(xmlReader->attributes().value("x").toDouble(),\
                                 xmlReader->attributes().value("y").toDouble());
//            qDebug() << xmlReader->attributes().value("x");
//            qDebug() << xmlReader->attributes().value("y");
//            QString pos = xmlReader->readElementText();
//            qDebug() << pos;
        }
    }
}

void QPRangeRoomDeserialize::deSerializeDevice(QPNode *node)
{
    while(xmlReader->readNextStartElement())
    {
        if(xmlReader->name() == "type")
        {
            node->setNodeType(ROUTER);
        }
        if(xmlReader->name() == "name")
        {
            node->setNodeName(xmlReader->readElementText());
        }
        if(xmlReader->name() == "sn")
        {
            node->setNodeSN(xmlReader->readElementText());
        }
    }
}
QVector<QPCabinetNode *> *QPRangeRoomDeserialize::getVector()
{
    return vector;
}

void QPRangeRoomDeserialize::setVector(QVector<QPCabinetNode *> *value)
{
    vector = value;
}


