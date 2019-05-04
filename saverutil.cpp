#include "saverutil.h"
#include <QtDebug>


SaverUtil::Nod::Nod(QPointF p,QString n, int id1){
    pos=p;
    name=n;
    id=id1;
}

SaverUtil::Nod::Nod(const Nod &copie){
    pos=copie.pos;
    name=copie.name;
    id=copie.id;
}


SaverUtil::SaverUtil()
{
  myNodes=Nodes();
  myArcs= Arcs();
     myValue = Values();
     myCapacity= Values();
    myFlux= Values();
    myArcType=QString("");
}

SaverUtil::SaverUtil(const SaverUtil &c){
    myNodes=c.myNodes;
    myArcs= c.myArcs;
    myValue= c.myValue;
    myCapacity= c.myCapacity;
    myFlux=c.myFlux;
    myArcType= c.myArcType;
}

SaverUtil::SaverUtil(const Nodes n,const Arcs as,const Values v,const Values c,const Values f,
                     const QString at){
    myNodes= n;
    myArcs= as;
    myValue= v;
    myCapacity= c;
    myFlux=f;
    myArcType= at;

}


QDataStream & operator << (QDataStream & out, const SaverUtil::Nod & Valeur)
{
        out << Valeur.name
                << Valeur.pos
                   << Valeur.id;

        return out;
}

QDataStream & operator >> (QDataStream & in, SaverUtil::Nod & Valeur)
{
        in >> Valeur.name;
        in >> Valeur.pos;
         in >> Valeur.id;
        return in;
}








QDataStream & operator << (QDataStream & out, const SaverUtil & Valeur)
{

        out << Valeur.myNodes
                << Valeur.myArcs
                << Valeur.myValue
                << Valeur.myCapacity
                << Valeur.myFlux
                << Valeur.myArcType;

        return out;
}

QDataStream & operator >> (QDataStream & in, SaverUtil & Valeur)
{
        in >> Valeur.myNodes;
        in >> Valeur.myArcs;
        in >> Valeur.myValue;
        in >> Valeur.myCapacity;
        in >> Valeur.myFlux;
        in >> Valeur.myArcType;
        return in;
}



void SaverUtil::initContactSystem ()
{

        qRegisterMetaTypeStreamOperators<SaverUtil::Nod>("SaverUtil::Nod");
        qRegisterMetaTypeStreamOperators<SaverUtil>("SaverUtil");

        qMetaTypeId<SaverUtil::Nod>();
        qMetaTypeId<SaverUtil>();				// Teste la validité de la classe Contact
}


bool SaverUtil::Nod::Nod::operator < (const SaverUtil::Nod &w)const
{
        return pos.x()<w.pos.x() && pos.y()<w.pos.y();
}

bool SaverUtil::Nod::Nod::operator == (const SaverUtil::Nod &w)const
{
        return pos.x()==w.pos.x() && pos.y()==w.pos.y();
}





