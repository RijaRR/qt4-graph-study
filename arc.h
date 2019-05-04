#ifndef ARC_H
#define ARC_H
#include "node.h"

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QGraphicsSimpleTextItem;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
class QGraphicsSceneContextMenuEvent;
QT_END_NAMESPACE


class Arc: public QGraphicsLineItem
{
public:
    enum { Type = UserType + 2 };
enum ArcType { valued_oriented,valued_not_oriented , not_valued_oriented ,not_valued_not_oriented,flux_not_valued,flux_valued };
    Arc(QMenu *contextMenuArc, Node *startNode, Node *endEnd,ArcType arcT=not_valued_oriented,int v=0,
      QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);

     QRectF boundingRect() const;
    QPainterPath shape() const;
    void setColor(const QColor &color)
        { myColor = color; }
    Node *startNode() const
        { return myStartNode; }
    Node *endNode() const
        { return myEndNode; }

    Node *startNodeC()
        { return myStartNode; }
    Node *endNodeC()
        { return myEndNode; }



     ArcType arcType() const
        { return myArcType; }
    int type() const
    { return Type;}
    void setV(int e);
    void setCapacity(int capacity);
    void setFlux(int flux);
    int getValue() const;
    int getFlux() const;
    int getCapacity() const;
    void setType(ArcType l);
    bool operator==(const Arc &ar);
    bool isOriented();
    bool isValued();
    bool hasFlux();
    QString nme();


public slots:
    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);


private:
    ArcType myArcType;
    Node *myStartNode;
    Node *myEndNode;
    QColor myColor;
    QPolygonF arrowHead;
    QMenu *contextMenuArc;
    int v;
    int myCapacity;
    int myFlux;
    QGraphicsSimpleTextItem* myText;



};

#endif // ARC_H
