#include "util.h"
#include "test.h"
#include <QSet>
#include <QMap>
#include <QPair>
#include <QtDebug>
#include <QTextCursor>
#include <QTextTable>
#include <QScrollBar>



Util::Util(const Scene* scene)
{
    myScene=scene;
    myLastLevel=0;
    setMyFluxCapacity();
}

///////////////////////FORD BELLMAN/////////////////////






///////////////////////PRIM////////////////////////////////////

QStringList Util::prim(Node* first)
{
    QStringList res;
    if(!primCritera())
    {
       res<<"Ce graphe ne remplit par le critère pour implémenter l'algorithme de Prim";
       res<<"Il n'est peut-être pas connexe, pas valué ou orienté";
       return res;
    }

 QList<Arc* > newArc;
 QList<Node* > added;
 added.clear();
 if(!myScene->getNodes().contains(first))
 {
     res<<"Une erreur sur le noeud";
     return res;
 }

 res<<"Début de l'algorithme Prim";
 res<<"On commence avec le premier sommet dans cette version : "+nm(first);

 added.append(first);

 int k=0;

 while(added.size()!=myScene->getNodes().size() && k<90)
 {
     if(k==89){
         res<<"oh oh boucle";
     }
    res<<"On prend un sommet tel qu' il existe un arc de valuation minimale qui le relie à un autre sommet déjà marqué";
    Node* min = primMin(added,newArc);
    res<<"On trouve le sommet "+nm(min)+", en considérant l'arc <strong>"+newArc.last()->nme()+"</strong>";
    res<<"On le marque";
    added.append(min);

     k++;
 }

 res<<"finalement l'arbre couvrant a "+QString::number(added.size())+" sommets et "
         +QString::number(newArc.size())+" arrêtes ";

 return res;


}

Node* Util::primMin(QList<Node *> added,QList<Arc *> &newArc)
{   
    QMap<int, Node*> m;
    QMap<int, Node*> nodeCpl;
    m.clear();
    nodeCpl.clear();

    foreach(Node* n, added)
    {
        foreach(Node* ad, getAdjacentNode(n))
        {
           if(!added.contains(ad))
            {
               int value= getArcValueNotOriented(n,ad);
               if(value !=-999000)
               {
                   m.insert(value,ad);
                   nodeCpl.insert(value,n);
               }
           }
        }
    }
    QList<int > listV= m.keys();
    qSort(listV);
    int keyMinArcValue=listV.first();

    Node* res= m.value(keyMinArcValue);
    Arc* ar= arc(res,nodeCpl.value(keyMinArcValue));

    newArc.append(ar);

    return res;
}

int Util::getArcValueNotOriented(Node* n, Node* e)
{
    if(arcExists(n,e))
    {
        return arc(n,e)->getValue();
    }else
    {
       return arc(e,n)->getValue();
    }
    return -999000;

}

bool Util::primCritera()
{
if( myScene->getArcs().length()<1)
    return false;

Arc* a= myScene->getArcs().first();

if(!a->isValued() || a->isOriented())
    return false;

if(!isConnexe().b)
    return false;

return true;

}


///////////////////////////FORD-FULKERSON//////////////////////////////////////////////

void Util::fordFulkerson(Node* source, Node* puit)
{
    textFordFulkerson<<"Début de l'algorithme Ford-Fulkerson";

     QList< QList< Node *> > allChain= allPaths(source,puit);

     if(allChain.isEmpty() || !graphHasValidNodeForFlux(source, puit))
     {
        textFordFulkerson<<"Le graphe n'est pas valide pour l'implémentation";
         return;
     }

    textFordFulkerson<<"On remet à zéro tout les flux";
     allFluxToZero();

     textFordFulkerson<<"On recherche tout les chaines augmentantes";
     QList< QList< Node *> > aC= allAugmentingChain(allChain);
     int k=0;

     textFordFulkerson<<" -  Tant qu'il y en a, on l'augmente";

     while(!aC.isEmpty() && k<155)
     {
        textFordFulkerson<<"On trouve la chaîne: ";

         QList< Node *> pat = aC.first();

         textFordFulkerson<<nmList(pat);
         textFordFulkerson<<"On l'augmente: ";

         augmentChain(pat,delta(pat));

         k++;
         aC= allAugmentingChain(aC);

     }
      textFordFulkerson<<" -  Il n'y a plus de chaine augmentante";
      textFordFulkerson<<" FIN";

}


QList< QList< Node *> > Util::allPaths(Node* source, Node* puit)
{
    QList< QList< Node *> > res;
    if( source == puit || !source->isValid() || !puit->isValid())
        return res;

    if(!source->getArcs().isEmpty() && !source->getArcs().first()->isOriented() ||
       (!puit->getArcs().isEmpty() && !puit->getArcs().first()->isOriented()))
        return res;

    if(hasCircuit())
        return res;

    this->inBreadthSearch(source);
    res.append(listPathBetween(source,puit));

    myResultPathFlux.append(res);

    if(myLastLevel>=3)
    {
     for(int i=2;i<=myLastLevel;i++)
        {
         foreach(Node* n, nodeInLevel(i))
         {
             QList< QList< Node *> > paths= listPathBetween(source,n);

             foreach(QList< Node *> list, paths)
             {
                 goBack(list,n,i,puit,0);
             }
         }
     }

     }else{

     return appendEndNode(res,puit);
 }



     return appendEndNode(myResultPathFlux,puit);
}


 QList< QList< Node *> > Util::appendEndNode(QList< QList< Node *> > a,Node* n)
{

     QList< QList< Node *> > res;

    for(int i=0;i<a.length();i++)
     {
        QList< Node *> list= a.at(i);
        list.append(n);
        res.append(list);
    }

    return res;
}

bool Util::graphHasValidNodeForFlux(Node* source, Node* puit)
{
foreach(Node* n, myScene->getNodes())
    {
    if(n!=source && n!=puit)
    {
        if(getChilds(n).isEmpty() || getParents(n).isEmpty())
            return false;
    }
   }
return true;
}

void Util::allFluxToZero()
{
   foreach(Arc* a, myScene->getArcs())
    {
       a->setFlux(0);
   }
}

QList<QPair<int, int > > Util::getMyFluxCapacityBeforeAll() const
{
    return myFluxCapacityBeforeAll;
}

QList< QList< Node *> > Util::allAugmentingChain(QList< QList< Node *> > paths)
{
    QList< QList< Node *> > res;

    foreach(QList< Node *> list,paths)
    {
        if(isAugmentingChain(list))
            res.append(list);
    }
    return res;
}

void Util::augmentChain(QList< Node *>  path,int delta)
{
    for(int i=0; i<path.length();i++)
    {
        if(i+1<path.length())
        {
                Arc* a=arc(path.at(i),path.at(i+1));

                //si arc direct
                if(a->data(4).toBool())
                {
                    a->setFlux(a->getFlux()+delta);
                }else{//arc indirect
                    a->setFlux(a->getFlux()-delta);
                }
                qDebug()<<a->nme()<<" flux= "<< a->getFlux();
        }
    }

}

//arc set data 4 , 0 indirect 1 direct
bool Util::isAugmentingChain(QList< Node *> path)
{

    for(int i=0; i<path.length();i++)
    {

        if(i+1<path.length())
        {

                Arc* a=arc(path.at(i),path.at(i+1));

              int f= a->getFlux();
              int c= a->getCapacity();

                //si arc direct
                if(a->data(4).toBool())
                {

                    if(f>=c)
                    {

                        return false;
                    }

                }else{//arc indirect

                    if(a->getFlux()<0){

                        return false;
                    }

                }

        }
    }

return true;
}

int Util::delta(QList< Node *>  path)
{

    QList< int> indirect;
    QList< int> direct;

     for(int i=0; i<path.length();i++)
    {
        if(i+1<path.length())
        {
                Arc* a = arc(path.at(i),path.at(i+1));
                //si arc direct
                if(a->data(4).toBool())
                {

                    direct.append(a->getCapacity() - a->getFlux());
                }else{//arc indirect
                    indirect.append(a->getFlux());

                }
        }
    }


 qSort(direct.begin(), direct.end());
  qSort(indirect.begin(), indirect.end());
//qDebug()<<"dir "<<direct.first();
  if(indirect.isEmpty())
      return direct.first();

  if(direct.first()>indirect.first())
  {
      return indirect.first();
  }
  return direct.first();
}

//setData "3" for level//does current path contains startNode?yes
//cherche des chaines en empruntant des arcs dans le sens opposé, il s'agit d'une fonction récursive
void Util::goBack(QList< Node *> currentPath, Node* startNode, int currentLevel,Node* destination,int k){

if(startNode == destination)
    {
    return;
}


    k++;
    k++;
    if(k>70)
        return;

if(currentLevel<2 || getLevel(startNode)!=currentLevel)
    {
    //qDebug()<<"returning void with "<<nm(startNode)<<currentLevel;
    return;
}

QList< Node *> sub= getNodeReachableInSubLevel(startNode);

if(sub.empty()){
    //qDebug()<<"sub nodes empty "<<nm(startNode)+" and current level: "<<currentLevel;
    return;
}

/*/go down level explore same level then go away
foreach(Node* n, sub){
   QList< QList< Node *> > reachable;
   QList< Node *> current(currentPath);
   current.append(n);
   reachable= allNodeReachableInSameLevel(n);

   foreach(QList< Node *> list, reachable){

       if(isAllVisited(list,current)){//return true if all element in lt not in path
           QList< Node *> p= current+list;
           goBack(p,p.last(),currentLevel-1);

       }

   }

}
*/
k++;
//go to uper level then continue exploring §/§ to do last level
//qDebug()<<" Noeud: "+nm(startNode)+" pour tout les noeuds du sous niveau, le niveau actuel etant "+QString::number(currentLevel);
//qDebug()<<" Noeud: "+nm(startNode)+", voici ces noueds";
// P(sub);
 //qDebug()<<" Noeud: "+nm(startNode)+", voici le parcours actuel";

 if(!currentPath.contains(startNode))
 {
 currentPath.append(startNode);
}
 if(currentPath.last()!=startNode)
 {
     currentPath.takeLast();
 }

 //P(currentPath);
foreach(Node* n, sub){


    if(!currentPath.contains(n))
    {
//qDebug()<<"             Noeuds: "+nm(n)+" se prépare à aller vers les niveaux suppérieurs";
    for (int i=currentLevel;i<myLastLevel;i++){
        //qDebug()<<"            Noeud: "+nm(n)+" on considère le niveau n° "+QString::number(i);
        QList< Node *> nodesInLevel= nodeInLevel(i);
         QList< Node *> current(currentPath);

         current.append(n);

        foreach(Node* nSup, nodesInLevel){
            if(!current.contains(nSup))
            {
            //qDebug()<<" Noeuds: "+nm(n)+" on y rencontre le noeud " +nm(nSup);
            //qDebug()<<" Noeuds: "+nm(n)+" voici le chemin pour y arriver ";
          QList< QList< Node *> > path;
          path.clear();
         path = listPathBetween(n,nSup);//nSup n'est pas compris, mais n compris


          //qDebug()<<" Noeuds: "+nm(n)+" path.length"+QString::number(path.length());
          if(path.length()>0)
          {
              foreach(QList< Node *> pa, path){
                  if(pa.contains(n))
         {
             pa.removeOne(n);
         }
                  if(!intersectAB(pa,current))
                  {
                 QList< Node *> pt= current+pa;
                 pt.append(nSup);
                 //qDebug()<<" Noeuds: "+nm(n)+"relance la fonction recursive ";
                goBack(pt,nSup,i,destination,k);
                }
              }
          }
          path.clear();
        }
        }
    }
}
    }
k++;
foreach(Node* n, sub)
{
   // qDebug()<<"Noeuds "+ nm(n)+" retourne vers la destination finale";
QList< QList< Node *> > path= listPathBetween(n,destination);
QList< Node *> current(currentPath);
//P(currentPath);
//qDebug()<<"...... ";
if( !path.isEmpty())
{


    foreach(QList< Node *> pa, path){
        if(!intersectAB(pa,current))
    {
                 QList< Node *> pt= current+pa;
                // qDebug()<<"Noeuds "+ nm(n)+" voici le chemin finale";
                 if(!myResultPathFlux.contains(pt))
                 {
                      myResultPathFlux.append(pt);
                // P(pt);
                 }else{
                // qDebug()<<"      :::::::::            :::::::                  duplicate";
                 }

}
              }

}
}

foreach(Node* n, sub)
{
    //qDebug()<<"Noeuds "+nm(n)+ " appel de la fonction recursive vers niveau inférieur";
goBack(currentPath,n,currentLevel-1,destination,k);
}


}


///////////////////////////PARCOURS EN LARGEUR AVEC DEFINITION DE NIVEAU//////////////////////////////////////////////

QStringList Util::inBreadthSearch(Node* start)
{
    QStringList res;
    QList< Node *> file;
    QList< Node *> visited;
    file.append(start);
    visited.append(start);
    int k=0;

    setLevel(0,start);

    while(k<199 && !file.isEmpty())
    {
        Node* current;
        current= file.takeFirst();
        res<<"Le noeud courant est "+nm(current);
        res<<"    pour tout les noeuds adjacent ou successeur si orienté ";
        foreach(Node* n, adjacentOrSuccessorNodes(current))
        {
            if(!visited.contains(n))
            {
                setLevel(getLevel(current)+1,n);
                res<<"                   Le noeud "+nm(n)+" a été visité on l'enfile. Il est de niveau "
                        +QString::number(getLevel(n));
                file.append(n);
                visited.append(n);
            }
    }
        k++;
}

res<<" fin de l'algorithme "+QString::number(k);

myLastLevel = getMaxLevel();

res<<" Le niveau le plus supérieur est  "+QString::number(myLastLevel);

return res;

    }


int Util::getMaxLevel(){
    if(!myScene->getNodes().isEmpty())
    {
        QList<int> list;
        foreach(Node* n,myScene->getNodes())
        {
            list.append(getLevel(n));
        }

        qSort(list.begin(), list.end());
        return list.last();

    }
    return -1;
}

///////////////////////////PARCOURS EN LONGUEUR //////////////////////////////////////////////

QStringList Util::inDephSearch(Node* s){

      QStringList res;
      res.clear();

      QList<Node* > pile;
      QList<Node* > visited;
      pile.append(s);
      int k=0;

      while(k<500 && pile.length()>0){

          Node* n= pile.last();

           res<<"<Strong class='j'>On passe par le noeud "+nm(n)+"</Strong>";

          Node* next=0;
          QList<Node* > adjacentOrSuccessorNode;

          if(n->getArcs().at(0)->isOriented())
          {
              adjacentOrSuccessorNode = getChilds(n);
          }else{
              adjacentOrSuccessorNode = getAdjacentNode(n);
          }

          if(adjacentOrSuccessorNode.length()>0 && !isAllVisited(adjacentOrSuccessorNode,visited)){
            next = firstNotVisited(adjacentOrSuccessorNode,visited);


            res<<"     On prend <Strong> "+nm(next)+", </Strong>un de ses successeurs ou sommet adjacent";

            if(visited.length()>0){
                if(!visited.contains(next)){
                    pile.append(next);
                    visited.append(next);
                    res<<"      On ne l'a pas encore visité, on l'inscrit dans la liste des noeuds visités ";

                   if(visited.length()>=3){
                      Node* cycle= hasCycleDS(adjacentOrSuccessorNodes(next),visited);
                     if(cycle->isValid()){
                        res<<"On a détecter un cycle relié au noeud "+nm(next);

                        m_hasCycle=true;
                     }
                   }


                }
            }else if(visited.length()==0){
                res<<"      On ne l'a pas encore visité, on l'inscrit dans la liste des noeuds visités (debut algo)";

                     pile.append(next);
                     visited.append(next);
            }

          }
          else
          {
               res<<"il n'y a aucun noeud adjacent ou successeur, on retire "+nm(n)+" de la pile";
              pile.removeOne(n);
              visited.append(n);
              res<<"<Strong>le noeud <i>"+nm(n)+"</i> a été visité</Strong>";
          }

k++;
if(k==499){
    res<<"boucle!:!!!!!";
}
      }

if(k<510 && pile.isEmpty()){
    res<<"<div style='background-color:blue;border:solid black;'>////////////////////////fin du parcours en profondeur/////////////////////////<div>";
}

return res;


 }

///////////////////////////RECHERCHE DE CHEMIN ET DE CHAINE ENTRE DEUX POINTS (ORIENTE)//////////////////////////////////////////////

///pour un graphe orienté

QList< QList<Node *> > Util::listPathBetween(Node* s, Node* end)
{
         if(getChilds(s).contains(end))
    {
             QList< QList<Node *> > res;
             QList<Node *> a;
             a.append(s);
             res.append(a);
             return res;
         }


      QList< QList< Node *> > res;
      QList<Node* > pile;
      QList<Node* > visited;
      pile.append(s);
      int k=0;

      while(k<500 && pile.length()>0){



          Node* n= pile.last();



          Node* next=0;
          QList<Node* > adjacentOrSuccessorNode;

          if(n->getArcs().at(0)->isOriented())
          {

              adjacentOrSuccessorNode = getChilds(n);
          }else{

              adjacentOrSuccessorNode = getAdjacentNode(n);
          }

          if(adjacentOrSuccessorNode.length()>0 && !isAllVisited(adjacentOrSuccessorNode,visited)){
            next = firstNotVisited(adjacentOrSuccessorNode,visited);

            if(visited.length()>0){
                if(!visited.contains(next)){

                    pile.append(next);
                    visited.append(next);

                    if(getChilds(next).contains(end)){
                        QList<Node* > path(pile);
                        res.append(path);

                    }

                    QList< QList< Node *> > partPathToEnd;

                    foreach(Node* no, getChilds(next))
                    {
                    partPathToEnd =searchInPaths(no,res);
                    if(!partPathToEnd.isEmpty()){
                         QList<Node* > path(pile);
                         foreach(QList< Node *> list, partPathToEnd)
                         {

                             QList< Node *> combination= path+list;
                             if(combination.size()==combination.toSet().size() && !res.contains(combination))
                             res.append(combination);
                         }
                       }
                     }


                }
            }else if(visited.length()==0){


                     pile.append(next);
                     visited.append(next);

                     if(getChilds(next).contains(end)){
                        QList<Node* > path(pile);
                        res.append(path);

                    }

            }

          }
          else
          {

              pile.removeOne(n);
              visited.append(n);

          }

k++;
if(k==499){
   qDebug()<<"boucle!:!!!!!";
}
      }

      textListPathBetween<<" Les chemins sont ";
      foreach(QList< Node *> list, res){
          textListPathBetween<<"-";
          QString s;
          foreach(Node* n, list)
          {
              s.append(nm(n)+"-");
          }
          textListPathBetween<<s;
      }

return res;
}


/////////////////////////////////////DIJKSTRA recherche du chemin le plus court////////////////////////

QStringList Util::dijkstra(Node* s, Node* e){


    QStringList res;
    if(!dijkstraCritera()){
    res<<"eTout les valeurs des arcs sont encore à zero";//e= erreur
        return res;
    }

  QList<Node *> unTreatedNode(myScene->getNodes());
  QList<Arc *>  arcs(myScene->getArcs());

  int k=0;

res<<"iInitialisation du poid de tout les noeuds";//i= information
  foreach(Node* n, unTreatedNode){
    if(n->getNodeId()==s->getNodeId()){
        res<<"ion initilise le poids du noeud de départ à 0, les autres sont portés à plus infini";
        n->setData(1,QVariant(0));
    }else{
        n->setData(1,QVariant(990000));
    }
}


res<<"lTant que tout les noeuds ne sont pas traité";//l= debut boucle, m fin
 while(!unTreatedNode.isEmpty() && 300>k){

     if(k==200){
         qDebug()<<"Une boucle dans l'algo!!!!";
     }

     res<<"iOn cherche le noeud de <i>valeur minimum </i> dans les noeuds non traités";

  Node* nodMin = nodeMinValue(unTreatedNode);

if(nodMin==0)
  {
    res<<"Il n'y a plus de noeud de valeur minimale, On arrête l'algorithme";
    return res;
}

     res<<"i<strong class='j'>    On trouve le noeud "+nm(nodMin)+QString(" avec un poid de %1 </strong>").arg(nodMin->data(1).toInt());



  res<<" pour chaque arc partant de "+nm(nodMin);

  QList<Arc *> arcOut= getArcOut(nodMin);



  foreach(Arc* a, arcOut ){

      int val= nodMin->data(1).toInt() + a->getValue();
      if( (val < a->endNode()->data(1).toInt()) && val<980000){
          a->endNode()->setData(1,QVariant(val));
         res<<"<strong>on affecte à "+nm(a->endNode())+QString(" la valeur %1</strong>").arg(val);
      }
  }

  unTreatedNode.removeOne(nodMin);
  res<<"le noeud est traité";



k++;
 }
res<<"Tout les noeuds ont été traités";
res<<"////////////////////Calcul du chemin ///////////////////////////////////";

Node* end= e;
int j=0;
res<<"il faut compter une distance de "+QString::number(getDistance(end));
res<<"de <strong> "+nm(end)+"</strong> on passe à ";
while (end!=s && j<400)
{
    if(j==300){
        qDebug()<<"Boucle::!!!!!!!!!";
        res<<"oups il y a boucle !!!! ";
    }
     if(end!=0)
    end= resolveClosestParent(end);

     if(end==0)
         break;

//res<<"de <strong> "+nm(end)+"</strong> on passe à ";

j++;
    }

return res;

}

Node* Util::resolveClosestParent(Node* n){
    Node* res=0;
             foreach(Arc* ar, n->getArcs()){
                 if(ar->endNode()==n){
                     if(getDistance(n)-getDistance(ar->startNode())==ar->getValue()){
                         return ar->startNode();
                     }
                 }
             }
             return res;
}

bool Util::dijkstraCritera()
{
    if(myScene->getArcs().size()==0 || isAllValueZero())
        return false;
    Arc* a= myScene->getArcs().first();

    if(!a->isValued())
        return false;

    foreach(Arc* a, myScene->getArcs())
    {
        if(a->getValue()<0)
            return false;
    }

    return true;

}




int Util::getDistance(Node* n){
    return n->data(1).toInt();
}

Node* Util::nodeMinValue(QList<Node *> list){

Node* minNode=0;

for (int i=0;i<list.size();i++){
    if(i==0){
        minNode=list.at(i);
    }
    if(list.at(i)->data(1).toInt()<minNode->data(1).toInt()){
        minNode=list.at(i);
    }
}

if(minNode!=0)
{
    if(98000<minNode->data(1).toInt())
    {
        Node* n=0;
        return n;
    }
}

return minNode;

}

QList<Arc *> Util::getArcOut(Node* start){
    QList<Arc *> result;

    foreach(Arc* a, start->getArcs()){
        if(a->startNode()->getNodeId()==start->getNodeId())
            result.append(a);
    }

return result;

}







void Util::P(QList< Node *> j){
    qDebug()<<"  ";
    qDebug()<<"///////PRINTING LIST/////";
    foreach(Node* n, j){
        qDebug()<<"  "+nm(n);
    }
    qDebug()<<"///////END/////";
    qDebug()<<"  ";
}


QList< QList< Node *> > Util::searchInPaths(Node* n,QList< QList< Node *> > paths )
 {
QList< QList< Node *> > res;

if(paths.empty())
    return res;

foreach(QList< Node *> list, paths){
          if(list.contains(n)){
              int ind= list.indexOf(n);
              QList< Node *> partPathToEnd;
              for(int i=ind;i<list.length();i++)
              {
                  partPathToEnd.append(list.at(i));
              }

              if(!res.contains(partPathToEnd))
              res.append(partPathToEnd);
          }
      }

return res;
 }






bool Util::hasCircuit()
{

foreach(Node* nd, myScene->getNodes()){
setD_(0,nd);
}

foreach(Node* nd, myScene->getNodes())
{
    foreach(Node* nod, getChilds(nd))
    {
       int e= d_(nod);
       e++;
       setD_(e,nod);
    }
}

QList<Node *> aTraiter;
int nbSommet=0;
aTraiter.clear();

foreach(Node* nd, myScene->getNodes())
{
    if(d_(nd)==0)
    {
        aTraiter.append(nd);
        nbSommet++;
    }
}

int antiB=0;

while(antiB<111 && !aTraiter.isEmpty())
{
    Node* first=0;
    if(!aTraiter.isEmpty())
        first=aTraiter.first();

    aTraiter.removeOne(first);
    foreach(Node* n, getChilds(first)){
        int e= d_(n);
             e--;
             setD_(e,n);
        if(d_(n)==0)
        {
            aTraiter.append(n);
            nbSommet++;
        }
    }
    antiB++;
    if(antiB==99)qDebug()<<"boucle!!!!!!!";
}

if(nbSommet==getOrder())
{
    return false;
}
return true;

}

 int Util::d_(Node* n){
return n->data(2).toInt();
 }

void Util::setD_(int n1, Node* n){
 n->setData(2,QVariant(n1));
    }


QList<Node *> Util::adjacentOrSuccessorNodes(Node* n){

     if(n->getArcs().at(0)->isOriented())
          {
              return getChilds(n);
          }else{
              return getAdjacentNode(n);
          }

QList<Node *> res;
return res;
}

 bool Util::isAllVisited(QList<Node *> list,QList<Node *> reference)
 {
     if(reference.length()==0)
         return false;

 foreach(Node* n, list){
     if(!reference.contains(n))
         return false;
 }
 return true;

 }

 bool Util::intersectAB(QList<Node *> A,QList<Node *> B)
 {
     if(B.length()==0)
         return false;

 foreach(Node* n, A){
     if(B.contains(n))
         return true;
 }
 return false;

 }


 Node* Util::firstNotVisited(QList<Node *> list,QList<Node *> reference)
 {
             for(int i=0;i<list.length();i++){
                       if(!reference.contains(list.at(i)))
                           return list.at(i);
             }
             return new Node();
 }


int Util::getOrder(){
return myScene->getNodes().size();
}

int Util::getNodeDegree(Node *node){
    return node->getArcs().size();
}

 QList<Node *> Util::getParents(Node* node){
    QList<Node *> result;
    foreach(Arc *arc,myScene->getArcs()){
        if(arc->endNode()==node){
            result.append(arc->startNode());
        }
    }
    return result;
 }

 QList<Node *> Util::getChilds(Node* node){
     QList<Node *> result;
    foreach(Arc *arc,myScene->getArcs()){
        if(arc->startNode()==node){
            result.append(arc->endNode());
        }
    }
    return result;
 }

 void Util::printAll(){
     qDebug()<<"?...........................";
     foreach(Node* n,myScene->getNodes())
     {
         qDebug()<<nm(n);
     }
     foreach(Arc* a,myScene->getArcs())
     {
         qDebug()<<a->nme();
     }
 qDebug()<<"?...........................";

 }




Cause Util::isRegular(){
Cause resultat;
resultat.b=true;
int degree=-1;
foreach(Node *node,myScene->getNodes()){
    int nodeDegree= getNodeDegree(node);
    if(degree==-1){
        degree= nodeDegree;
        continue;
    }
    if(degree != nodeDegree){
        resultat.b=false;
        QString numNode=QString::number(node->getNodeId());
        resultat.raison=QString("Le sommet n°")+numNode+QString(" a un degré ")
                        + QString::number(nodeDegree)+ QString(" alors que le precedent en a pour valeur ")+
                           QString::number(degree);
        return resultat;
    }
}
    resultat.raison=QString("Tout les sommets ont même degré");
    return resultat;
}

Cause Util::isComplete(){
    Cause resultat;
    foreach(Node *node,myScene->getNodes()){
        if(node->getArcs().size() < (getOrder()-1)){
            resultat.b=false;
            resultat.raison=QString("Déjà, le degré du sommet parcouru est inférieur de l'ordre moins un");
            return resultat;
        }
         QSet<Node *> set = getAdjacentNode(node).toSet();
         if(set.size()!= (getOrder()-1)){
             resultat.b=false;
            resultat.raison=QString(" Le nombre de noeud distinct en relation avec le sommet est different de l'ordre moins un");
            return resultat;
         }
    }


     resultat.b=true;
     resultat.raison=QString("Tous les sommets reliés deux à deux");
     return resultat;
}


QList<Node *> Util::getAdjacentNode(Node* node){
   QList<Node *> resultat;
    foreach(Arc *arc,node->getArcs()){
            if(arc->startNode()!=node){
                resultat.append(arc->startNode());
            }
            if(arc->endNode()!=node){
                resultat.append(arc->endNode());
            }
        }
    return resultat;
}

Node* Util::hasCycleDS(QList<Node *> adjacentOrSuccessorNode,QList<Node *> visited){

    foreach(Node* n, adjacentOrSuccessorNode){
           int ind= visited.indexOf(n);
           if(visited.contains(n) ){
                if(n!=visited.at(ind-1)){
                    return n;
                }
           }
    }
return new Node();
}



//algo s'appuie sur parcours en profondeur d'une graphe avec verification de cycle à chaque étape
Cause Util::hasCycle(){
     Cause r;

r.b=true;
r.raison="hlkjpokj";
return r;

      }

Cause Util::isConnexe(){

    QList<Arc *> arcTransitive= fermetureTransitiveNotOriented();
    Cause r;


foreach(Node* n,myScene->getNodes()){

    QList<Node *> nodes(myScene->getNodes());
    if(nodes.removeOne(n)){
       foreach(Arc*a, n->getArcs()+arcTransitive){
           if(a->startNode()!=n && a->endNode()==n){
//qDebug()<<"removing "<<a->startNode()->getNodeId();
               nodes.removeOne(a->startNode());
           }else if(a->startNode()==n && a->endNode()!=n){
               nodes.removeOne(a->endNode());
           }
       }
       if(nodes.size()>0){
         r.b=false;
         r.raison=QString("Le noeud n° ")+QString::number(n->getNodeId())+QString("n'est pas relié à tout les autres sommets");
         return r;
       }
    }else{
       qDebug("Error Util; node to be removed cannot be found");
    }
    nodes.clear();
}
        r.b=true;
        r.raison=QString("Il existe toujours une chaîne reliant chaque sommmets du graphe");
    return r;
}


QList<Arc *> Util::fermetureTransitiveNotOriented(){

QList<Arc *> resultat;
QList<Node *> nodes= myScene->getNodes();

foreach(Node* k,nodes){
    foreach(Node* i,nodes){
        foreach(Node* j,nodes){
           QList<Arc *> check= myScene->getArcs()+resultat;
            if(arcExistsInList(i,k,check) && arcExistsInList(k,j,check) && (i!=j) && !arcExistsInList(i,j,check)){
                resultat.append(createArc(i,j));

            }
        }
    }
}

return resultat;
}

QList<Arc *> Util::fermetureTransitive(){

QList<Arc *> resultat;
QList<Node *> nodes= myScene->getNodes();


foreach(Node* k,nodes){
    foreach(Node* i,nodes){
        foreach(Node* j,nodes){

            if(!arcExistsOriented(i,j) && arcExistsOriented(i,k) && arcExistsOriented(k,j) && !arcExistsInList(i,j,resultat)){
                resultat.append(createArc(i,j));
            }
        }
    }
}

return resultat;
}




bool Util::arcExistsOriented(Node* nodeStart, Node* nodeEnd){

    foreach(Arc* a,myScene->getArcs()){
        if(a->startNode()==nodeStart && a->endNode()==nodeEnd){
                    return true;
        }
    }
    return false;
}

bool Util::arcExists(Node* nodeStart, Node* nodeEnd){

    foreach(Arc* a,myScene->getArcs()){
        if((a->startNode()==nodeStart && a->endNode()==nodeEnd)||(a->startNode()==nodeEnd && a->endNode()==nodeStart)){
                    return true;
        }
    }
    return false;
}

bool Util::arcExistsInList(Node* nodeStart, Node* nodeEnd,QList<Arc *> list){
    foreach(Arc* a,list){
        if((a->startNode()==nodeStart && a->endNode()==nodeEnd)||(a->startNode()==nodeEnd && a->endNode()==nodeStart)){

                    return true;

        }
    }

    return false;
}





bool Util::isAllValueZero(){

    foreach(Arc* a, myScene->getArcs()){
        if(a->getValue()!=0){
            return false;
        }
    }
    return true;
}

QString Util::nm(Node* n){
    return n->getName().size()>0?n->getName():QString::number(n->getNodeId());
}





Arc* Util::createArc(Node* nodeStart, Node* nodeEnd){
return new Arc(myScene->getMyItemMenuArc(),nodeStart,nodeEnd);
}



Arc* Util::arc(Node* start, Node* end) {

    foreach(Arc* a, myScene->getArcs())
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









 void Util::setLevel(int i,Node* n){
     n->setData(3,QVariant(i));
 }

int Util::getLevel(Node* n){
   return n->data(3).toInt();
}

QList< Node *> Util::getNodeReachableInSubLevel(Node* n){
  QList< Node *> res;
  int l= getLevel(n);

  if(l==0){
      return res;
  }
foreach(Node* nd,getAdjacentNode(n)){
    if(getLevel(nd)==(l-1))
        res.append(nd);
}
 return res;
}


 QList< QList< Node *> > Util::allNodeReachableInSameLevel(Node* n){
     QList< QList< Node *> > res;
     foreach(Node* nd, getAdjacentNode(n)){
         if(getLevel(nd)==getLevel(n))
         {
            QList< Node *> direction;
            direction.append(nd);  
            nextNodeInSameLevel(nd,n,direction);
            res.append(direction);
         }
     }

     //slice the result
   foreach(QList< Node *> list,res){
       QList< QList< Node *> > partPath;


       for(int i=2;i<=list.length();i++){
            QList< Node *> part;
           for(int k=0; k<i;k++){
             part.append(list.at(k));
           }
           partPath.append(part);
       }

       res.removeOne(list);
       res= res+partPath;
   }

return res;

 }


 void Util::nextNodeInSameLevel(Node* start,Node* predecessor, QList< Node *> path){

     foreach(Node* n,getAdjacentNode(start)){
         if(getLevel(n)==getLevel(start) && n!=predecessor)
         {
            path.append(n);
            nextNodeInSameLevel(n,start,path);
         }
     }
     return;

 }


 QList< Node *> Util::nodeInLevel(int level)
 {
       QList< Node *> res;
       res.clear();
       foreach(Node* n, myScene->getNodes()){
           if(getLevel(n)==level){
               res.append(n);
           }
       }
       return res;
 }

 QString Util::dup(QList<Node *> A)
 {
     if(A.toSet().size()!=A.size())
         return QString("il y a des éléments dupliqués");

      return QString("  rs ");

 }

 void Util::setMyFluxCapacity()
{

   for(int i=0; i<myScene->getArcs().length();i++)
    {
       QPair<int,int> pair (myScene->getArcs().at(i)->getFlux(),
                        myScene->getArcs().at(i)->getCapacity());
      myFluxCapacityBeforeAll.append(pair);
   }
}


 QStringList Util::getTextFordFulkerson() const
 {
     return textFordFulkerson;
 }

  QString Util::nmList(QList<Node *> A)
  {
      QString res="Chaine: ";

      foreach(Node* n, A)
      {
          res.append(nm(n)+"-");
      }
      return res;
  }

   QStringList Util::getTextListPathBetween() const
   {
       return textListPathBetween;
   }
