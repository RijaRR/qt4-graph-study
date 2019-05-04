
#ifndef UTIL_H
#define UTIL_H
#include "scene.h"

#include <QTextEdit>



struct Cause
   {
    bool b;
    QString raison;
   };

class Util
{
public:

    Util(const Scene* scene);

    int getOrder();
    int getNodeDegree(Node* node);
    QList<Node *> getParents(Node* node);
    QList<Node *> getChilds(Node* node);
    Cause isRegular();
    Cause isComplete();
    QList<Node *> getAdjacentNode(Node* node);
    QList<Node *> adjacentOrSuccessorNodes(Node* node);
    int getArcValueNotOriented(Node* n, Node* e);
    Cause hasCycle();
    Cause isConnexe();
    bool hasCircuit();
    int d_(Node* n);
    void setD_(int n, Node* n);
    QList<Arc *> fermetureTransitive();
     QList<Arc *> fermetureTransitiveNotOriented();
    bool arcExists(Node* nodeStart, Node* nodeEnd);
    bool arcExistsOriented(Node* nodeStart, Node* nodeEnd);
    bool arcExistsInList(Node* nodeStart, Node* nodeEnd,QList<Arc *> list);
    Arc* createArc(Node* nodeStart, Node* nodeEnd);

     QStringList prim(Node* nodeStart);
     Node* primMin(QList<Node *> added,QList<Arc *> &newArc);
     bool primCritera();

     QStringList fordBellMan();
    QStringList dijkstra(Node* nodeStart, Node* nodeEnd);
    QStringList inDephSearch(Node* start);
    QStringList inBreadthSearch(Node* start);


    bool isAllVisited(QList<Node *> list,QList<Node *> reference);
    Node* hasCycleDS(QList<Node *> adjacentOrSuccessorNode,QList<Node *> visited);

    QList< QList< Node *> > listPathBetween(Node* source, Node* end);

    void goBack(QList< Node *> currentPath, Node* currentStartingNode, int currentLevel,Node* destination, int k);



    Node* firstNotVisited(QList<Node *> list,QList<Node *> reference);
    Node* nodeMinValue(QList<Node *> list);
     QList<Arc *> getArcOut(Node* start);
     bool isAllValueZero();
     void nextNodeInSameLevel(Node* start,Node* predecessor, QList< Node *> path);
      QList< QList< Node *> > allPaths(Node* source, Node* puit);

      void fordFulkerson(Node* source, Node* puit);

      bool isAugmentingChain(QList< Node *> path);
      int delta(QList< Node *>  path);
Arc* arc(Node* nodeStart, Node* nodeEnd) ;
void augmentChain(QList< Node *>  path,int delta);
QList< QList< Node *> > allAugmentingChain(QList< QList< Node *> > paths);
  QList< QList< Node *> > appendEndNode(QList< QList< Node *> > a,Node* n);

  QList<QPair<int, int > > getMyFluxCapacityBeforeAll() const;
  QStringList getTextFordFulkerson() const;
  QStringList getTextListPathBetween() const;
   QString nm(Node* n);

   void printAll();

private:
    const Scene* myScene;
    Node* resolveClosestParent(Node* n);

     int getDistance(Node* n);
     bool m_hasCycle;
     QList< QList< Node *> > searchInPaths(Node* n,QList< QList< Node *> > paths );
     void P(QList< Node *> j);
     void setLevel(int i,Node* n);
     int getLevel(Node* n);
     QList< Node *> getNodeReachableInSubLevel(Node* n);
        QList< QList< Node *> > allNodeReachableInSameLevel(Node* n);

        QList< Node *> nodeInLevel(int level);
        int myLastLevel;
        int getMaxLevel();

        QList<QPair<int, int > > myFluxCapacityBeforeAll;
        void setMyFluxCapacity();
        bool intersectAB(QList<Node *> A,QList<Node *> B);
        QString dup(QList<Node *> A);

        bool graphHasValidNodeForFlux(Node* source, Node* puit);

       QStringList textFordFulkerson;
       QStringList textListPathBetween;

        QList< QList< Node *> > myResultPathFlux;

        void allFluxToZero();

        QString nmList(QList<Node *> A);

        bool dijkstraCritera();

};

#endif // UTIL_H
