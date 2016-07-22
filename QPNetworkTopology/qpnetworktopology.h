#ifndef QPNETWORKTOPOLOGY_H
#define QPNETWORKTOPOLOGY_H

#include "qpnetworktopology_global.h"
#include <QObject>
class QGraphicsScene;
class QSvgRenderer;
class QPNETWORKTOPOLOGYSHARED_EXPORT QPNetworkTopology : public QObject
{
    Q_OBJECT
public:
    explicit QPNetworkTopology(QObject *parent = 0);

    QGraphicsScene *sence() const;
    void initilizeScene();
private:
    QGraphicsScene *scene;
    QSvgRenderer *svgRender;
};

#endif // QPNETWORKTOPOLOGY_H
