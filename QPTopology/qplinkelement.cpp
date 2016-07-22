#include "qplinkelement.h"
#include "private/qplinkelement_p.h"
#include <QPainter>
#include "qptopologynode.h"
QPLinkElement::QPLinkElement(QGraphicsItem *parent):
    QGraphicsObject(parent), d_ptr(new (std::nothrow) QPLinkElementPrivate(this))
{
}

QPLinkElement::QPLinkElement(const QLineF &line, QGraphicsItem *parent):
    QGraphicsObject(parent), d_ptr(new (std::nothrow) QPLinkElementPrivate(this))
{
    setLine(line);
}

QPLinkElement::QPLinkElement(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent):
    QGraphicsObject(parent), d_ptr(new (std::nothrow) QPLinkElementPrivate(this))
{
    setLine(x1, y1, x2, y2);
}

int QPLinkElement::type() const
{
    return Type;
}

QPen QPLinkElement::pen() const
{
    Q_D(const QPLinkElement);
    return d->pen;
}

void QPLinkElement::setPen(const QPen &pen)
{
    Q_D(QPLinkElement);
    d->pen = pen;
}

QLineF QPLinkElement::line() const
{
    Q_D(const QPLinkElement);
    return d->line;
}

void QPLinkElement::setLine(qreal x1, qreal y1, qreal x2, qreal y2)
{
    setLine(QLineF(x1, y1, x2, y2));
}

void QPLinkElement::setEndPoint(QPTopologyNode *from, QPTopologyNode *to)
{
    Q_D(QPLinkElement);
    d->from = from;
    d->to = to;
    if(d->from && d->to)
    {
        d->from->addLink(this);
        d->from->setLinkPoint(CENTER);
        d->to->addLink(this);
        d->to->setLinkPoint(CENTER);
    }
    updatePosition();
}

QRectF QPLinkElement::boundingRect() const
{
    Q_D(const QPLinkElement);
    if (d->pen.widthF() == 0.0) {
        const qreal x1 = d->line.p1().x();
        const qreal x2 = d->line.p2().x();
        const qreal y1 = d->line.p1().y();
        const qreal y2 = d->line.p2().y();
        qreal lx = qMin(x1, x2);
        qreal rx = qMax(x1, x2);
        qreal ty = qMin(y1, y2);
        qreal by = qMax(y1, y2);
        return QRectF(lx, ty, rx - lx, by - ty);
    }
    return shape().controlPointRect();
}

static QPainterPath qt_graphicsItem_shapeFromPath(const QPainterPath &path, const QPen &pen)
{
    // We unfortunately need this hack as QPainterPathStroker will set a width of 1.0
    // if we pass a value of 0.0 to QPainterPathStroker::setWidth()
    const qreal penWidthZero = qreal(0.00000001);

    if (path == QPainterPath())
        return path;
    QPainterPathStroker ps;
    ps.setCapStyle(pen.capStyle());
    if (pen.widthF() <= 0.0)
        ps.setWidth(penWidthZero);
    else
        ps.setWidth(pen.widthF());
    ps.setJoinStyle(pen.joinStyle());
    ps.setMiterLimit(pen.miterLimit());
    QPainterPath p = ps.createStroke(path);
    p.addPath(path);
    return p;
}

QPainterPath QPLinkElement::shape() const
{
    Q_D(const QPLinkElement);
    QPainterPath path;
    if (d->line == QLineF())
        return path;

    path.moveTo(d->line.p1());
    path.lineTo(d->line.p2());
    return qt_graphicsItem_shapeFromPath(path, d->pen);
}

bool QPLinkElement::contains(const QPointF &point) const
{
    return QGraphicsItem::contains(point);
}

void QPLinkElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_D(QPLinkElement);
    Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(d->pen);
    painter->drawLine(d->line);

//    if (option->state & QStyle::State_Selected)
    //        qt_graphicsItem_highlightSelected(this, painter, option);
}

void QPLinkElement::updatePosition()
{
    Q_D(QPLinkElement);
    if(d->from && d->to)
    {
        QLineF line(d->from->linkPoint(), d->to->linkPoint());
        setLine(line);
    }
}

void QPLinkElement::setLine(const QLineF &line)
{
    Q_D(QPLinkElement);
    if (d->line == line)
        return;
    prepareGeometryChange();
    d->line = line;
    update();
}
