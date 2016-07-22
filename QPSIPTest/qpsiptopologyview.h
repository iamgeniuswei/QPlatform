#ifndef QPSIPTOPOLOGYVIEW_H
#define QPSIPTOPOLOGYVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include "qpsiptest_global.h"
class QSvgRenderer;
class QPTopologyNode;
class QPNode;

class QPSIPTESTSHARED_EXPORT QPSIPTopologyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QPSIPTopologyView(QWidget *parent = 0);

signals:

public slots:

private:
    void initilizeScene();

private:
    QGraphicsScene *scene;
    QSvgRenderer *svgRender;
    QHash<QPTopologyNode*, QPNode*> nodeAttrHash;
};

#endif // QPSIPTOPOLOGYVIEW_H
