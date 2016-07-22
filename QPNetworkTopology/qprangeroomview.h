#ifndef QPRANGEROOMVIEW_H
#define QPRANGEROOMVIEW_H
#include "qpnetworktopology_global.h"
#include <QGraphicsView>
#include <QHash>
class QGraphicsScene;
class QSvgRenderer;
class QPTopologyNode;
class QPNodeAttribute;
class QPNode;
class QPCabinetNode;
class QPNETWORKTOPOLOGYSHARED_EXPORT QPRangeRoomView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QPRangeRoomView(QWidget *parent = 0);

signals:

public slots:
    void initilizeScene();
    void itemMouseDoubleClicked(QPTopologyNode *node);
    void btnClicked();


private:
    QGraphicsScene *scene;
    QSvgRenderer *svgRender;
    QHash<QPTopologyNode*, QPNode*> nodeAttrHash;
    QVector<QPCabinetNode *> *vector;
};

#endif // QPRANGEROOMVIEW_H
