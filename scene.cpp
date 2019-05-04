#include "scene.h"
#include "node.h"
#include "arc.h"
#include "util.h"
#include "graphsaver.h"
#include <QtGui>
#include <QtDebug>
#include <QVariant>

//! [0]
Scene::Scene(QMenu *itemMenu, QMenu *myItemMenuArc1, QObject *parent)
    : QGraphicsScene(parent)
{

    //myArcType=0;
nodeId=0;
myMode=MoveItem;
line = 0;
myItemMenu= itemMenu;
myItemMenuArc = myItemMenuArc1;

}

void Scene::setMode(Mode mode){
      myMode = mode;
}
void Scene::setInsertNode(){
      myMode =InsertNode;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;


    switch (myMode) {
        case InsertNode:
            n=new Node(myItemMenu);
            addItem(n);
            n->setPos(mouseEvent->scenePos());
            myMode=MoveItem;
            n->setNodeId(nodeId);

            nodeId++;
            nodes.append(n);
            emit nodeInserted(n);
            break;
        case InsertLine:



            line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                                        mouseEvent->scenePos()));
            line->setPen(QPen(Qt::black, 2));

            addItem(line);


            break;


    default:
        ;
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}
//! [9]

//! [10]

void Scene::setArcType(Arc::ArcType a){
          myArcType=a;
}

Arc::ArcType Scene::getArcType() const{
    return myArcType;
}



void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
  if (myMode == InsertLine && line != 0) {


       QLineF newLine(line->line().p1(), mouseEvent->scenePos());
       line->setLine(newLine);

     } else if (myMode == MoveItem) {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
     }

}
//! [10]

//! [11]
void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
if (line != 0 && myMode == InsertLine) {
     QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();
        removeItem(line);
       delete line;

       if (startItems.count() > 0 && endItems.count() > 0 &&
            startItems.first()->type() == Node::Type &&
            endItems.first()->type() == Node::Type &&
            startItems.first() != endItems.first()) {
            Node *startNode =
                qgraphicsitem_cast<Node *>(startItems.first());
            Node *endNode =
                qgraphicsitem_cast<Node *>(endItems.first());
            Arc *arc = new Arc(myItemMenuArc, startNode, endNode);
            arc->setType(myArcType);
            arc->setColor(Qt::black);
            startNode->addArc(arc);
            endNode->addArc(arc);
            arc->setZValue(-1000.0);
            addItem(arc);
            arcs.append(arc);
            arc->updatePosition();
            myMode=MoveItem;
        }


    }

 line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}



void Scene::removeNode(Node *node)
{
    int index = nodes.indexOf(node);
    if (index != -1){
        if(node->getArcs().length()>0){
        foreach(Arc *arc, node->getArcs()){
            int indexArc=arcs.indexOf(arc);
            if(indexArc !=-1){
                arcs.removeAt(indexArc);//supprime arc de la liste
            }
        }
         }
        nodes.removeAt(index);//supprime noeud de la liste
    }
}



void Scene::removeArc(Arc *arc)
{
    int index = arcs.indexOf(arc);
    Node* start= arc->startNode();
    Node* end= arc->endNode();
    start->removeArc(arc);
    end->removeArc(arc);
    arcs.removeAt(index);


}




QList<Arc *> Scene::getArcs()const {
    return arcs;
}

QList<Node *> Scene::getNodes() const{
    return nodes;
}

QMenu* Scene::getMyItemMenuArc() const{
return myItemMenuArc;
}


  bool Scene::saveIn(QString fileName){
       GraphSaver s(this);
       return s.save(fileName);
  }



bool Scene::open(QString fi){
    GraphSaver s(this);
    if(s.load(fi)){
         clean();
         nodes=s.m_nodes;
         arcs=s.m_arcs;
         nodeId= s.m_nodes.size();
         setArcType(s.m_ArcType);
         foreach(Node* n, nodes){
             addItem(n);
         }
           foreach(Arc* a,arcs){
               addItem(a);
           }

           return true;
    }
    return false;
}


Node* Scene::findById(int id) {
   Node* n=0;
    foreach(Node* n, this->nodes){
        if(n->getNodeId()== id){
            return n;
        }
    }
  return n;
}

void Scene::colorArcs(QList<Arc *> list, QColor &color)
{
    foreach(Arc* a, list)
    {
        a->setColor(color);
    }
}

void resetColorArcs(QList<Arc *> list)
{
    foreach(Arc* a, list)
    {
        a->setColor(Qt::black);
    }

}


//set data 4 indirect ou direct
Arc*   Scene::arc(Node* start, Node* end)
{
    foreach(Arc* a, arcs)
    {
        if(a->startNode()==start && a->endNode()==end)
        {
            //is direct true
            a->setData(4,QVariant(true));
            return a;
        }
        if(a->startNode()==end && a->endNode()==start)
        {
            //indirect false
           a->setData(4,QVariant(false));
            return a;
        }

    }
return NULL;
}





  void Scene::clean(){
       nodeId=0;
      nodes.clear();
      arcs.clear();
      clear();
  }
