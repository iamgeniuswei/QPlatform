#include "qptopologynode.h"
#include "private/qptopologynode_p.h"
#include <QPainter>
#include <QSvgRenderer>
#include <QStyleOptionGraphicsItem>
#include <QDebug>
#include "qplinkelement.h"
#include "qpuipopupwindow.h"
#include <QLabel>
#include "qpnodeattribute.h"
QPTopologyNode::QPTopologyNode(QGraphicsItem *parent):
    QGraphicsObject(nullptr), d_ptr(new (std::nothrow) QPTopologyNodePrivate(this))
{
    setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable| QGraphicsItem::ItemSendsGeometryChanges);
    Q_D(QPTopologyNode);
    d->init(parent);
}

QPTopologyNode::QPTopologyNode(const QString &fileName, QGraphicsItem *parent):QGraphicsObject(nullptr), d_ptr(new (std::nothrow) QPTopologyNodePrivate(this))
{
    setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable| QGraphicsItem::ItemSendsGeometryChanges);
    Q_D(QPTopologyNode);
    d->init(parent);
    setSvgFile(fileName);
}

int QPTopologyNode::type() const
{
    return Type;
}

void QPTopologyNode::setSvgFile(const QString &file)
{
    Q_D(QPTopologyNode);
    d->svgFile = file;
    if(d->renderer)
    {
        d->renderer->load(file);
        d->updateDefaultSize();
    }
}

QString QPTopologyNode::svgFile() const
{
    Q_D(const QPTopologyNode);
    return d->svgFile;
}

void QPTopologyNode::setSharedRenderer(QSvgRenderer *renderer)
{
    Q_D(QPTopologyNode);
    if(!renderer)
        return;
    if (!d->shared)
    {
        delete d->renderer;
        d->renderer = nullptr;
    }

    d->renderer = renderer;
    d->shared = true;

    d->updateDefaultSize();

    update();
}

QSvgRenderer *QPTopologyNode::renderer() const
{
    Q_D(const QPTopologyNode);
    return d->renderer;
}

void QPTopologyNode::setElementId(const QString &id)
{
    Q_D(QPTopologyNode);
    d->svgElemID= id;
    d->updateDefaultSize();
    update();
}

QString QPTopologyNode::elementId() const
{
    Q_D(const QPTopologyNode);
    return d->svgElemID;
}

//void QPTopologyNode::setMaximumCacheSize(const QSize &size)
//{

//}

//QSize QPTopologyNode::maximumCacheSize() const
//{
//    return QSize();
//}

QString QPTopologyNode::nodeText() const
{
    Q_D(const QPTopologyNode);
    return d->nodeText;
}

void QPTopologyNode::setNodeText(const QString &value)
{
    //TODO:PrepareGeomety
    Q_D(QPTopologyNode);
    if(d->nodeText == value)
        return;
    d->showText = true;
    d->nodeText = value;
    prepareGeometryChange();
    d->textRect.setSize(textSize());


//    d->boundingRect.width() > d->textRect.width() ? d->boundingRect.adjust(0, 0, 0,d->textRect.height())
//                                                  :d->boundingRect.adjust(d->textRect.width()/2, 0, 0, d->textRect.height());
    update();
}


//void QPTopologyNode::setMaximumCacheSize(const QSize &size)
//{

//}

//QSize QPTopologyNode::maximumCacheSize() const
//{

//}



QRectF QPTopologyNode::boundingRect() const
{
    Q_D(const QPTopologyNode);
//    qDebug() << "boundingRect" << d->boundingRect;
//    d->boundingRect += d->textRect;
//    QRectF rect = d->boundingRect.adjust(0,0,0,d->charHeigth);
    QRectF boundingRect;
    d->boundingRect.width() > d->textRect.width() ? boundingRect.adjust(0, 0, d->boundingRect.width(), d->boundingRect.height() + d->charHeigth) :
                                                    boundingRect.adjust(0, 0, d->textRect.width(), d->boundingRect.height() + d->charHeigth);
    return boundingRect;
}

/*!
    \internal

    Highlights \a item as selected.

    NOTE: This function is a duplicate of qt_graphicsItem_highlightSelected() in qgraphicsitem.cpp!
*/
static void qt_graphicsItem_highlightSelected(
    QGraphicsItem *item, QPainter *painter, const QStyleOptionGraphicsItem *option)
{
    const QRectF murect = painter->transform().mapRect(QRectF(0, 0, 1, 1));
    if (qFuzzyIsNull(qMax(murect.width(), murect.height())))
        return;

    const QRectF mbrect = painter->transform().mapRect(item->boundingRect());
    if (qMin(mbrect.width(), mbrect.height()) < qreal(1.0))
        return;

    qreal itemPenWidth;
    switch (item->type()) {
        case QGraphicsEllipseItem::Type:
            itemPenWidth = static_cast<QGraphicsEllipseItem *>(item)->pen().widthF();
            break;
        case QGraphicsPathItem::Type:
            itemPenWidth = static_cast<QGraphicsPathItem *>(item)->pen().widthF();
            break;
        case QGraphicsPolygonItem::Type:
            itemPenWidth = static_cast<QGraphicsPolygonItem *>(item)->pen().widthF();
            break;
        case QGraphicsRectItem::Type:
            itemPenWidth = static_cast<QGraphicsRectItem *>(item)->pen().widthF();
            break;
        case QGraphicsSimpleTextItem::Type:
            itemPenWidth = static_cast<QGraphicsSimpleTextItem *>(item)->pen().widthF();
            break;
        case QGraphicsLineItem::Type:
            itemPenWidth = static_cast<QGraphicsLineItem *>(item)->pen().widthF();
            break;
        default:
            itemPenWidth = 1.0;
    }
    const qreal pad = itemPenWidth / 2;

    const qreal penWidth = 0; // cosmetic pen

    const QColor fgcolor = option->palette.windowText().color();
    const QColor bgcolor( // ensure good contrast against fgcolor
        fgcolor.red()   > 127 ? 0 : 255,
        fgcolor.green() > 127 ? 0 : 255,
        fgcolor.blue()  > 127 ? 0 : 255);

    painter->setPen(QPen(Qt::green, penWidth, Qt::SolidLine));
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(item->boundingRect().adjusted(pad, pad, -pad, -pad));

    painter->setPen(QPen(Qt::green, 0, Qt::DashLine));
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(item->boundingRect().adjusted(pad, pad, -pad, -pad));
}


void QPTopologyNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        Q_UNUSED(widget);

        Q_D(QPTopologyNode);
        if (!d->renderer->isValid())
            return;

        if (d->svgElemID.isEmpty())
            d->renderer->render(painter, d->svgRect);
        else
            d->renderer->render(painter, d->svgElemID, d->svgRect);

        //if showText, draw nodeText
        if(d->showText)
        {
            painter->save();
            painter->setFont(d->textFont);
            painter->setPen(QColor(255, 50, 50));
//            painter->setBrush(QBrush(Qt::white, Qt::Dense4Pattern));
//            painter->fillRect(QRectF(d->svgRect.x(), d->svgRect.height(), d->textRect.width(), d->charHeigth), QColor(255,255,255,100));
            painter->drawText(QRectF(d->svgRect.x(), d->svgRect.height(), d->textRect.width(), d->charHeigth), Qt::AlignCenter, d->nodeText);
            painter->restore();
        }

        //if selected, draw boundingRect
        if (option->state & QStyle::State_Selected)
            qt_graphicsItem_highlightSelected(this, painter, option);
}

QVariant QPTopologyNode::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    Q_D(QPTopologyNode);
    if (change == QGraphicsItem::ItemPositionHasChanged) {
        foreach (QPLinkElement *arrow, d->link) {
            setLinkPoint(CENTER);
            arrow->updatePosition();
        }
    }
    return value;
}

void QPTopologyNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouseDoubleClickSignal(this);
    qDebug() << "element double clicked!";
    QPUIPopupWindow *dlg = getPopupWindow();
    if(dlg)
        dlg->show();
}

QPUIPopupWindow *QPTopologyNode::getPopupWindow() const
{
    Q_D(const QPTopologyNode);
    QPUIPopupWindow *nodeAttrDlg = new (std::nothrow) QPUIPopupWindow;
    if(nodeAttrDlg && d->nodeAttr)
    {
        QLabel *logo = new QLabel(nodeAttrDlg);
        logo->setObjectName("nodeTL");
        nodeAttrDlg->setTitleLogo(logo);

        QLabel *text = new QLabel(nodeAttrDlg);
        text->setText(d->nodeAttr->getTypeName());
        nodeAttrDlg->setTitleWidget(text);
        nodeAttrDlg->initilizeUI();
        return nodeAttrDlg;
    }
    return nullptr;
}



bool QPTopologyNode::showText() const
{
    Q_D(const QPTopologyNode);
    return d->showText;
}

void QPTopologyNode::setShowText(bool value)
{
    Q_D(QPTopologyNode);
    d->showText = value;
    if(value)
    {
        prepareGeometryChange();
        update();
    }
}

bool QPTopologyNode::showBoundingRect() const
{
    Q_D(const QPTopologyNode);
    return d->showBoundingRect;
}

void QPTopologyNode::setShowBoundingRect(bool value)
{
    Q_D(QPTopologyNode);
    d->showBoundingRect = value;
}


QColor QPTopologyNode::boundingRectColor() const
{
    Q_D(const QPTopologyNode);
    return d->boundingRectColor;
}

void QPTopologyNode::setBoundingRectColor(const QColor &value)
{
    Q_D(QPTopologyNode);
    d->boundingRectColor = value;
}

void QPTopologyNode::addLink(QPLinkElement *link)
{
    Q_D(QPTopologyNode);
    d->link.append(link);
}

void QPTopologyNode::setLinkPoint(OrientationPoint linkpoint)
{
    Q_D(QPTopologyNode);
    switch (linkpoint) {
    case TOPLEFT:
        d->linkPoint = this->pos();
        break;
    case TOPMIDDLE:
        d->linkPoint = QPointF(this->x()+d->boundingRect.width()/2, this->y());
        break;
    case TOPRIGHT:
        d->linkPoint = QPointF(this->x()+d->boundingRect.width(), this->y());
        break;
    case RIGHTMIDDLE:
        d->linkPoint = QPointF(this->x()+d->boundingRect.width(), this->y()+d->boundingRect.height()/2);
        break;
    case RIGHTBOTTOM:
        d->linkPoint = QPointF(this->x()+d->boundingRect.width(), this->y()+d->boundingRect.height());
        break;
    case BOTTOMMIDDLE:
        d->linkPoint = QPointF(this->x()+d->boundingRect.width()/2, this->y()+d->boundingRect.height());
        break;
    case LEFTBOTTOM:
        d->linkPoint = QPointF(this->x(), this->y()+d->boundingRect.height());
        break;
    case LEFTMIDDLE :
        d->linkPoint = QPointF(this->x(), this->y()+d->boundingRect.height()/2);
        break;
    case CENTER:
        d->linkPoint = QPointF(this->x()+d->boundingRect.width()/2, this->y()+d->boundingRect.height()/2);
        break;
    default:
        break;
    }
}

QPointF QPTopologyNode::linkPoint() const
{
    Q_D(const QPTopologyNode);
    return d->linkPoint;
}

QPNodeAttribute *QPTopologyNode::getAttribute() const
{
    Q_D(const QPTopologyNode);
    return d->nodeAttr;
}

QSizeF QPTopologyNode::textSize() const
{
    Q_D(const QPTopologyNode);
    if(!(d->nodeText.isEmpty()))
    {
        return QSizeF(d->nodeText.size()*d->charWidth+d->padding, d->charHeigth+d->padding);
    }
    return QSizeF();
}

void QPTopologyNode::repaintItem()
{
    update();
}
QFont QPTopologyNode::textFont() const
{
    Q_D(const QPTopologyNode);
    return d->textFont;
}

void QPTopologyNode::setTextFont(const QFont &value)
{
    Q_D(QPTopologyNode);
    if(d->textFont != value)
    {
        prepareGeometryChange();
        d->textFont = value;
        QFontMetrics fm(d->textFont);
        d->charHeigth = fm.height();
        d->charWidth = fm.width('M');
        d->textRect.setSize(textSize());
//        update();
    }
}

QColor QPTopologyNode::textColor() const
{
    Q_D(const QPTopologyNode);
    return d->textColor;
}

void QPTopologyNode::setTextColor(const QColor &value)
{
    Q_D(QPTopologyNode);
    d->textColor = value;
}

QBrush QPTopologyNode::textRectBrush() const
{
    Q_D(const QPTopologyNode);
    return d->textRectBrush;
}

void QPTopologyNode::setTextRectBrush(const QBrush &value)
{
    Q_D(QPTopologyNode);
    d->textRectBrush = value;
}


void QPTopologyNodePrivate::init(QGraphicsItem *parent)
{
    Q_Q(QPTopologyNode);
    q->setParentItem(parent);
    renderer = new (std::nothrow) QSvgRenderer(q);
    if(renderer)
    {
        QObject::connect(renderer, SIGNAL(repaintNeeded()),
                         q, SLOT(repaintItem()));
    }
    q->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
#ifdef _WIN32
    q->setTextFont(QFont("Courier New", 14));
#else
    q-setTextFont(QFont("Free Mono", 14));
#endif


}

void QPTopologyNodePrivate::updateDefaultSize()
{
    QRectF bounds;
    if (svgElemID.isEmpty()) {
        bounds = QRectF(QPointF(0, 0), renderer->defaultSize());
    } else {
        bounds = renderer->boundsOnElement(svgElemID);
    }
    if (svgRect.size() != bounds.size()) {
        q_func()->prepareGeometryChange();
        svgRect.setSize(bounds.size());
        boundingRect.setSize(bounds.size());
    }
}




