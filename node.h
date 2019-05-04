#ifndef NODE_H
#define NODE_H
#include <QGraphicsItem>

#include <QList>
        #include <QGraphicsTextItem>

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;
QT_END_NAMESPACE

class Arc;

class Node : public QGraphicsItem
{
public:
    enum { Type = UserType + 4 };

    Node(QMenu *contextMenu, QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    Node();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void addArc(Arc *arc);
    void setNodeId(int id);
     int type() const{
        return Type;
    }
     void removeArcs();
     void removeArc(Arc* arc);
     int getNodeId();
     void setName(QString n);
     QString getName() const;
     QList<Arc *> getArcs();
     bool operator==(const Node &node) const;
     bool isValid();


private:
    int nodeId;
    QMenu *contextMenu;
    QList<Arc *> arcs;
    QString myName;



protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

};



#endif // NODE_H
