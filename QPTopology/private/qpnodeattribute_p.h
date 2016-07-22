#ifndef DEVICEINFO_P_H
#define DEVICEINFO_P_H
#include <QObject>
class QPNodeAttribute;
class QPNodeAttributePrivate
{
public:
    QPNodeAttributePrivate(QPNodeAttribute *parent)
        : q_ptr(parent)
    {}
public:
    int _sn;
    QString _manufacturer;
    int _nicCount;
    QStringList _macAddress;
    QStringList _ipAddress;
    QList<int> _openPort;
    QStringList _openServices;
    QString _runningOS;
    QStringList _vulnerabilities;

private:
    QPNodeAttribute *const q_ptr;
};
#endif // DEVICEINFO_P_H
