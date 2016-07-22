#ifndef QPXMLSERIALIZE_H
#define QPXMLSERIALIZE_H
#include "qpxmlhelper_global.h"
#include <QVector>
class QXmlStreamWriter;
class QPXMLHELPERSHARED_EXPORT QPXMLSerialize
{
public:
    QPXMLSerialize();
    bool saveXMLFile(const QString &filePath);
    void closeXMLFile();
    virtual void serialize() = 0;

protected:
    QXmlStreamWriter *xmlWriter;
};

#endif // QPXMLSERIALIZE_H
