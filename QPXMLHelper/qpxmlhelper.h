#ifndef QPXMLHELPER_H
#define QPXMLHELPER_H

#include "qpxmlhelper_global.h"
#include "tinyxml2.h"
using namespace tinyxml2;
class QXmlStreamReader;
class QPXMLHELPERSHARED_EXPORT QPXMLDeserialize
{

public:
    QPXMLDeserialize();
    bool readXMLFile(const QString &filePath);
    bool closeXMLFile();
    virtual void deSerialize() = 0;

protected:
    QXmlStreamReader *xmlReader;
};

#endif // QPXMLHELPER_H
