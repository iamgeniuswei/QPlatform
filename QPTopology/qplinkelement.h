#ifndef QPLINKELEMENT_H
#define QPLINKELEMENT_H

#include <QGraphicsObject>
#include "qptopology_global.h"
class QPLinkElementPrivate;
class QPTopologyNode;
class TestItem;
class QPTOPOLOGY_EXPORT QPLinkElement : public QGraphicsObject
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
    enum {
        Type = UserType + 3
    };
public:
    explicit QPLinkElement(QGraphicsItem *parent = 0);
    explicit QPLinkElement(const QLineF &line, QGraphicsItem *parent = 0);
    explicit QPLinkElement(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = 0);

    int type() const;
    QPen pen() const;
    void setPen(const QPen &pen);

    QLineF line() const;
    void setLine(const QLineF &line);
    inline void setLine(qreal x1, qreal y1, qreal x2, qreal y2);

    void setEndPoint(QPTopologyNode *from, QPTopologyNode *to);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    bool contains(const QPointF &point) const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void updatePosition();

private:
    QPLinkElementPrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPLinkElement)
};

#endif // QPLINKELEMENT_H
