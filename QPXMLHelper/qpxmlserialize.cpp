#include "qpxmlserialize.h"
#include <QXmlStreamWriter>
#include <QFile>
#include <QDebug>
QPXMLSerialize::QPXMLSerialize():xmlWriter(new (std::nothrow) QXmlStreamWriter)
{
    xmlWriter->setAutoFormatting(true);
}

bool QPXMLSerialize::saveXMLFile(const QString &filePath)
{
    QFile *file = new QFile(filePath);
    if(!file->open(QFile::WriteOnly | QFile::Text | QFile::Truncate))
    {
        //TODO:add error
        qDebug() << "open xml file: " << filePath << "error";
        return false;
    }
    if(xmlWriter)
        xmlWriter->setDevice(file);
    return true;
}
void QPXMLSerialize::closeXMLFile()
{
    QFile *file =(QFile*)(xmlWriter->device());
    file->close();
}

