#ifndef QPDEVICEELEMENT_H
#define QPDEVICEELEMENT_H
#include <QObject>
#include <QGraphicsObject>
#include "qptopology_global.h"
#include "misc_enum.h"
class QPTopologyNodePrivate;
class QSvgRenderer;
class QPLinkElement;
class QPUIPopupWindow;
class QPNodeAttribute;
class QPTOPOLOGY_EXPORT QPTopologyNode : public QGraphicsObject
{    
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
    enum { Type = UserType + 2 };
public:
    explicit QPTopologyNode(QGraphicsItem *parent = 0);
    explicit QPTopologyNode(const QString& fileName, QGraphicsItem *parent = 0);

    int type() const;
    void setSvgFile(const QString &file);
    QString svgFile() const;

    void setSharedRenderer(QSvgRenderer *renderer);
    QSvgRenderer *renderer() const;

    void setElementId(const QString &id);
    QString elementId() const;

    //TODO
//    void setMaximumCacheSize(const QSize &size);
//    QSize maximumCacheSize() const;

    bool showText() const;
    void setShowText(bool value);
    QString nodeText() const;
    void setNodeText(const QString &value);
    QFont textFont() const;
    void setTextFont(const QFont &value);
    QColor textColor() const;
    void setTextColor(const QColor &value);
    QBrush textRectBrush() const;
    void setTextRectBrush(const QBrush &value);


    //when selected, showBoundingRect.
    bool showBoundingRect() const;
    void setShowBoundingRect(bool value);

    QColor boundingRectColor() const;
    void setBoundingRectColor(const QColor &value);

    void addLink(QPLinkElement* link);
    void setLinkPoint(OrientationPoint linkpoint);
    QPointF linkPoint() const;

    QPNodeAttribute *getAttribute() const;


private:
    QSizeF textSize() const;

signals:
    void mouseDoubleClickSignal(QPTopologyNode *node);
private slots:
    void repaintItem();

public:
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
protected:
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    QPUIPopupWindow *getPopupWindow() const;

private:
//    Q_PRIVATE_SLOT(d_func(), void _q_repaintItem())
    QPTopologyNodePrivate *const d_ptr;
    Q_DECLARE_PRIVATE(QPTopologyNode)

};

#endif // QPDEVICEELEMENT_H
