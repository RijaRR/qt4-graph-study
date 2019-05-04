#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QList>
#include "node.h"
#include "arc.h"
class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Mode { InsertNode, InsertLine,MoveItem };
    Scene(QMenu *itemMenu=0, QMenu *myItemMenuArc=0, QObject *parent = 0);
    QGraphicsLineItem *line;

    void colorArcs(QList<Arc *> list,QColor &c);
    void resetColorArcs(QList<Arc *> list);
    void removeNode(Node *node);
    void removeArc(Arc *arc);
    QList<Arc *> getArcs() const;
    QList<Node *> getNodes() const;
    QMenu* getMyItemMenuArc() const;
    bool saveIn(QString fileName);
    void resetNodeId();
    void clean();
    bool open(QString fileName);
    Node* findById(int id);
    Arc*   arc(Node* start, Node* end);

     Arc::ArcType getArcType() const;
    void setArcType(Arc::ArcType a);
    void restoreFluxCapacityValues();

public slots:
    void setMode(Mode mode);
    void setInsertNode();




signals:
    void nodeInserted(Node *node);

private:
    Mode myMode;
    Node* n;
    int nodeId;
    QList<Node *> nodes;
    QList<Arc *> arcs;
    QMenu *myItemMenu;
    QMenu *myItemMenuArc;
    Arc::ArcType myArcType;
    Node* n1;
    Node* n2;
    Arc* a;



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

};

#endif // SCENE_H
