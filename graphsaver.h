#ifndef GRAPHSAVER_H
#define GRAPHSAVER_H
#include <QFile>
#include <QMap>
#include "scene.h"
#include "saverutil.h"

class GraphSaver
{
public:
    GraphSaver(const Scene *s);
    bool save(const QString fileName);
    bool load(const QString fileName);
    QList<Node* > m_nodes;
    QList<Arc* > m_arcs;
    Arc::ArcType m_ArcType;

private:
    QMap<SaverUtil::Nod,Node* > myDico;
    const Scene* myScene;

    SaverUtil* mySaver;
    Node* convertNodeS(SaverUtil::Nod& nd);
    SaverUtil::Nod convertNode(Node* node);
    Arc* convertArcS(SaverUtil::Arc ar);
    SaverUtil::Arc convertArc(Arc* ar);
    bool createSaverFromScene();
    SaverUtil getSaverFromFile(QFile& file);
    bool isTreated(SaverUtil::Nod nd);
    Node* getTreated(SaverUtil::Nod nd);

};

#endif // GRAPHSAVER_H
