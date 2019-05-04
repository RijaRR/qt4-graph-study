#include "node.h"
#include "arc.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>

Node::Node(QMenu *contextMenu1, QGraphicsItem *parent, QGraphicsScene *scene)
    : QGraphicsItem(parent, scene){
setFlag(QGraphicsItem::ItemIsMovable,true);
  setFlag(QGraphicsItem::ItemIsSelectable, true);
 nodeId=0;
 contextMenu=contextMenu1;
 myName="";


}

Node::Node(){
nodeId=-1;
}

QRectF Node::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}
QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);

    return path;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{



    painter->setBrush(Qt::green);
    if(isSelected())
    painter->setBrush(Qt::blue);
    painter->drawEllipse(-10, -10, 20, 20);
    painter->drawText(QPointF(0,0),QString::number(nodeId));

    if(!myName.isEmpty())
        painter->drawText(0,-19,myName);

}

bool Node::isValid(){
    return nodeId != -1;
}
void Node::addArc(Arc *arc)
{
    arcs.append(arc);
}

void Node::setNodeId(int id){
    nodeId=id;
}

void Node::removeArcs()
{
    foreach (Arc *arrow, arcs) {

        arrow->startNode()->removeArc(arrow);
        arrow->endNode()->removeArc(arrow);
        scene()->removeItem(arrow);
        delete arrow;
    }
}

void Node::removeArc(Arc *arrow)
{
    int index = arcs.indexOf(arrow);

    if (index != -1)
        arcs.removeAt(index);
}

QList<Arc *> Node::getArcs(){
    return arcs;
}

void Node::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
 {
     scene()->clearSelection();
     setSelected(true);
     contextMenu->exec(event->screenPos());
 }

int Node::getNodeId(){
    return nodeId;
}

void Node::setName(QString n){
    myName=n;

}

QString Node::getName() const{
    return myName;
}

bool Node::operator==(const Node& nd) const{
    int idC= nd.nodeId;
    return this->nodeId == idC;
}




