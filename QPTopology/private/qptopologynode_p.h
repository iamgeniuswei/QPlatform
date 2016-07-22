#ifndef QPTOPOLOGYNODE_P_H
#define QPTOPOLOGYNODE_P_H
#include <QObject>
#include <QFont>
#include <QBrush>
class QGraphicsItem;
class QPTopologyNode;
class QPNodeAttribute;
class QSvgRenderer;
class QPLinkElement;
class QColor;
class QPTopologyNodePrivate
{
    Q_DECLARE_PUBLIC(QPTopologyNode)
public:
    QPTopologyNodePrivate(QPTopologyNode *parent = 0)
        : q_ptr(parent), renderer(nullptr), nodeAttr(nullptr), showText(false), showBoundingRect(true),
          charWidth(10), charHeigth(12), padding(8), shared(false)
    {}
    void init(QGraphicsItem *parent = 0);

    inline void updateDefaultSize();


public:
    //node Attribute.
    QPNodeAttribute *nodeAttr;

    //svg Renderer.
    QSvgRenderer *renderer;
    bool shared;
    QString svgFile;
    QString svgElemID;
    QRectF svgRect;

    //node text.
    QString nodeText;
    bool showText;
    QFont textFont;
    QColor textColor;
    QRectF textRect;
    QBrush textRectBrush;
    int charWidth;
    int charHeigth;
    int padding;

    //bounding Rect.
    bool showBoundingRect;
    QColor boundingRectColor;
    QRectF boundingRect;


    //link point
    QPointF linkPoint;
    QList<QPLinkElement* > link;










private:
    QPTopologyNode *const q_ptr;
};

#endif // QPTOPOLOGYNODE_P_H
