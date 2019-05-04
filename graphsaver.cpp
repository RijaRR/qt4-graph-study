#include "graphsaver.h"
#include <QtDebug>
#include <QVariant>
GraphSaver::GraphSaver(const Scene* s)
{
    myScene= s;
    mySaver =0;
}



SaverUtil GraphSaver::getSaverFromFile(QFile& file){

         SaverUtil::initContactSystem();
        bool l= file.open(QIODevice::ReadOnly);
         QDataStream in(&file);    // read the data serialized from the file
         QVariant s;
         in >> s;
        file.close();
        SaverUtil saver=s.value<SaverUtil>();


        if(!l)
        qDebug()<<"error on getting saver from file";

        return saver;

}




bool GraphSaver::load(const QString fileName){
     QFile file(fileName);
     myDico.clear();
     SaverUtil mySav= getSaverFromFile(file);
     SaverUtil::Arcs myArcs= mySav.myArcs;
     SaverUtil::Nodes myNodes= mySav.myNodes;
     SaverUtil::Values myValue= mySav.myValue;
     SaverUtil::Values myCapacity= mySav.myCapacity;
     SaverUtil::Values myFlux= mySav.myFlux;
     QString myArcType= mySav.myArcType;

     m_arcs.clear();
     m_nodes.clear();

         foreach(SaverUtil::Arc a, myArcs){

             Arc* ar= convertArcS(a);
             Node* start= ar->startNode();
             Node* end= ar->endNode();

             if(myArcType == "valued_oriented" ){

                  ar->setV(myValue.value(a));
                  ar->setType(Arc::valued_oriented);
                  m_ArcType= Arc::valued_oriented;

             }else if(myArcType == "valued_not_oriented" ){

                  ar->setV(myValue.value(a));
                 ar->setType(Arc::valued_not_oriented);
                   m_ArcType=Arc::valued_not_oriented;

             }else if(myArcType == "flux_not_valued"){

                  ar->setType(Arc::flux_not_valued);
                   ar->setFlux(myFlux.value(a));
                ar->setCapacity(myCapacity.value(a));
                m_ArcType=Arc::flux_not_valued;

             }else if(myArcType == "flux_valued"){

                 ar->setV(myValue.value(a));
                ar->setType(Arc::flux_valued);
                ar->setFlux(myFlux.value(a));
                ar->setCapacity(myCapacity.value(a));
                    m_ArcType= Arc::flux_valued;
             }

             m_arcs.append(ar);
             if(!end->getArcs().contains(ar)){
                 end->addArc(ar);
             }
             if(!start->getArcs().contains(ar)){
                 start->addArc(ar);
             }

         }


     foreach(SaverUtil::Nod n,myNodes){

           if(isTreated(n)){
               continue;
           }else{
                convertNodeS(n);
           }
     }


       return 0<m_nodes.size();
}




bool GraphSaver::save(const QString fi){

    QFile fileName(fi);
    bool res=false;

    if(!createSaverFromScene()){
         qDebug()<<"erreur dans create saver form scne";
    }

    SaverUtil::initContactSystem();

    QVariant q= qVariantFromValue(*mySaver);

    fileName.open(QIODevice::WriteOnly);
     QDataStream out(&fileName);
        out << q;
        if(0<fileName.size()){
            res= true;
        }
        fileName.close();

        return res;
}


Node* GraphSaver::convertNodeS(SaverUtil::Nod &nd){


    if(isTreated(nd)){
        return getTreated(nd);
    }
        Node* res= new Node(myScene->getMyItemMenuArc());

        res->setPos(nd.pos);
        res->setName(nd.name);
        res->setNodeId(nd.id);
        m_nodes.append(res);
        return res;
}

SaverUtil::Nod GraphSaver::convertNode(Node* node){
        SaverUtil::Nod res;
        res.pos=node->pos();
        res.name= node->getName();
        res.id= node->getNodeId();
        return res;
    }

Arc* GraphSaver::convertArcS(SaverUtil::Arc ar){


    Node* startNode= convertNodeS(ar.first);
    Node* endNode= convertNodeS(ar.second);
    return new Arc(myScene->getMyItemMenuArc(),startNode,endNode);

    }


    SaverUtil::Arc GraphSaver::convertArc(Arc* ar){
        SaverUtil::Nod start= convertNode(ar->startNode());
        SaverUtil::Nod end= convertNode(ar->endNode());
        SaverUtil::Arc arc(start,end);
        return arc;

    }


    bool GraphSaver::createSaverFromScene(){
    SaverUtil::Arcs sArcs;
    SaverUtil::Nodes sNodes;
    SaverUtil::Values sValue;
    SaverUtil::Values sFlux;
    SaverUtil::Values sCapacity;
    QString sArcType= "";

  if(myScene->getArcType()==Arc::flux_not_valued)
    {

      sArcType= "flux_not_valued";
  }
   if(myScene->getArcType()==Arc::flux_valued)
    {

      sArcType= "flux_valued";
  }
    if(myScene->getArcType()==Arc::valued_not_oriented)
    {
      sArcType= "valued_not_oriented";
  }
     if(myScene->getArcType()==Arc::valued_oriented)
    {
      sArcType= "valued_oriented";
  }
      if(myScene->getArcType()==Arc::not_valued_not_oriented)
    {
      sArcType= "not_valued_not_oriented";
  }
       if(myScene->getArcType()==Arc::not_valued_oriented)
    {
      sArcType= "not_valued_oriented";
  }


    foreach(Arc* a,myScene->getArcs()){
        SaverUtil::Arc sA= convertArc(a);
        sArcs.append(sA);
        sValue.insert(sA,a->getValue());
        sFlux.insert(sA,a->getFlux());
        sCapacity.insert(sA,a->getCapacity());
    }
    foreach(Node* n, myScene->getNodes()){
        sNodes.append(convertNode(n));
    }

    mySaver= new SaverUtil(sNodes,sArcs,sValue,sCapacity,sFlux,sArcType);

    return mySaver->myNodes.size()> 0;
}



 bool   GraphSaver::isTreated(SaverUtil::Nod nd){

        foreach(Node* n, m_nodes){
            if(n->pos()==nd.pos){
                return true;
            }
        }
        return false;
    }

 Node*  GraphSaver::getTreated(SaverUtil::Nod nd){

        foreach(Node* n, m_nodes){
            if(n->pos()==nd.pos){
                return n;
            }
        }
        return m_nodes.first();

    }


