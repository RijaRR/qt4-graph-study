#include "arc.h"
#include <QtGui>
#include <QtDebug>


const qreal Pi = 3.14;

Arc::Arc(QMenu *contextMenu1, Node *startNode, Node *endNode,ArcType arcT,int v1,
         QGraphicsItem *parent, QGraphicsScene *scene)
    : QGraphicsLineItem(parent, scene)
{
    myArcType= arcT;
    contextMenuArc = contextMenu1;
    myStartNode = startNode;
    myEndNode = endNode;
    v=v1;
    myCapacity=0;
    myFlux=0;
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    myColor = Qt::black;
    setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    myText= new QGraphicsSimpleTextItem(this);
    myText->show();



}





//! [0]

//! [1]
QRectF Arc::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}
//! [1]

//! [2]
QPainterPath Arc::shape() const
{
    QPainterPath path = QGraphicsLineItem::shape();
     path.addPolygon(arrowHead);
    return path;
}
//! [2]

//! [3]
void Arc::updatePosition()
{
    QLineF line(mapFromItem(myStartNode, 0, 0), mapFromItem(myEndNode, 0, 0));
    setLine(line);
}
//! [3]

//! [4]
void Arc::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
          QWidget *)
{
    if (myStartNode->collidesWithItem(myEndNode))
        return;

    qreal arrowSize = 10;
    QPen myPen = pen();
    if(isSelected()){
        myColor=Qt::blue;
    }else{
        myColor=Qt::black;
    }

    myPen.setColor(myColor);
    painter->setPen(myPen);
    painter->setBrush(myColor);
    QLineF centerLine(myStartNode->pos(), myEndNode->pos());
    qreal intersectLocation= (centerLine.length()-10)/centerLine.length();
    QPointF intersectPoint= centerLine.pointAt(intersectLocation);
    qreal beginLocation= (10)/centerLine.length();
    QPointF beginPoint= centerLine.pointAt(beginLocation);
    setLine(QLineF(intersectPoint, beginPoint));
     painter->drawLine(line());

double angle = ::acos(line().dx() / line().length());
     if(myArcType==valued_oriented || myArcType==not_valued_oriented || myArcType==flux_not_valued || myArcType== flux_valued)
     {

    if (line().dy() >= 0)
        angle = (Pi * 2) - angle;

        QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                        cos(angle + Pi / 3) * arrowSize);
        QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                        cos(angle + Pi - Pi / 3) * arrowSize);

        arrowHead.clear();
        arrowHead << line().p1()<< arrowP1 << arrowP2;
        painter->drawPolygon(arrowHead);
      }


     if(!hasFlux() && isValued())
     {
       myText->setText(QString::number(v));
       myText->setPos(line().pointAt(0.5));
     }

     if(hasFlux()){
         if(isValued())
         {
            myText->setText("v= "+QString::number(v)+" f= "+
                            QString::number(myFlux)+" ["+QString::number(myCapacity)+" ]");
       myText->setPos(line().pointAt(0.5));

         }else{
             myText->setText( QString::number(myFlux)+" ["+QString::number(myCapacity)+" ]");
       myText->setPos(line().pointAt(0.5));

         }
     }

}

void Arc::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
 {
     scene()->clearSelection();
     setSelected(true);
     contextMenuArc->exec(event->screenPos());
 }

void Arc::setV(int e){
    v=e;
}

void Arc::setCapacity(int c){
myCapacity=c;
}

void Arc::setFlux(int f){
    myFlux=f;
}

int Arc::getValue() const{
    return v;
}

    int Arc::getFlux() const{
        return myFlux;
    }

    QString Arc::nme(){
        QString s = QString::number(myStartNode->getNodeId());
        QString e = QString::number(myEndNode->getNodeId());
        return s+"-"+e;
    }

    int Arc::getCapacity() const{
        return myCapacity;
    }

 void Arc::setType(ArcType l){
      myArcType=l;

 }

 bool Arc::operator ==(const Arc &nd){
     return nd.startNode()->getNodeId()==myStartNode->getNodeId() && nd.endNode()->getNodeId()==myEndNode->getNodeId();
 }

 bool Arc::isOriented(){
     return myArcType==valued_oriented || myArcType==not_valued_oriented || myArcType==flux_valued
             || myArcType==flux_not_valued ;
 }

 bool Arc::isValued(){
     return myArcType==valued_oriented || myArcType==valued_not_oriented || myArcType==flux_valued;
 }

 bool Arc::hasFlux(){
     return myArcType==flux_valued || myArcType==flux_not_valued;
 }




