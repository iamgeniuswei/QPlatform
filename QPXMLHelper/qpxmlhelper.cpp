#include "qpxmlhelper.h"
#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>
QPXMLDeserialize::QPXMLDeserialize():xmlReader(nullptr)
{
    xmlReader = new (std::nothrow) QXmlStreamReader;
//    doc = new (std::nothrow) XMLDocument;
}

bool QPXMLDeserialize::readXMLFile(const QString &filePath)
{
    QFile *file = new QFile(filePath);
    if(!file->open(QFile::ReadOnly | QFile::Text))
    {
        //TODO:add error
        qDebug() << "open xml file: " << filePath << "error";
        return false;
    }
    if(xmlReader)
        xmlReader->setDevice(file);
    return true;
//    qDebug() << doc.LoadFile("D:\\icon\\room.xml");
//    qDebug() << doc.ErrorName();
//    return true;
}

bool QPXMLDeserialize::closeXMLFile()
{
    QFile *file =(QFile*)(xmlReader->device());
    file->close();
    return true;
}


