#ifndef SAVERUTIL_H
#define SAVERUTIL_H
 #include <QVariant>
#include <QPointF>
#include <QList>
#include <QMap>
class SaverUtil
{
public:

    struct Nod
                        {
                                Nod (const QPointF pos = QPointF(0,0), const QString name = "",const int id=0);
                                bool operator<(const Nod &w) const;
                                bool operator==(const Nod &w) const;
                                Nod(const Nod &copie);
                                QString name;
                                QPointF pos;
                                int id;
                        };


    typedef QList<Nod> Nodes;
    typedef QPair<Nod,Nod> Arc;
    typedef QList<Arc> Arcs;
    typedef QMap<Arc,int> Values;


    SaverUtil();
    SaverUtil(const SaverUtil & Copie);
    SaverUtil(const Nodes myNodes, const Arcs myArcs, const Values myValue,
             const Values myCapacity, const Values myFlux,
             const QString myArcType);


    Nodes myNodes;
    Arcs myArcs;
    Values myValue;
    Values myCapacity;
    Values myFlux;
    QString myArcType;


                        friend QDataStream & operator << (QDataStream &, const SaverUtil::Nod &);
                        friend QDataStream & operator >> (QDataStream &, SaverUtil::Nod &);

                        friend QDataStream & operator << (QDataStream &, const SaverUtil &);
                        friend QDataStream & operator >> (QDataStream &, SaverUtil &);


                    static  void initContactSystem ();








};

Q_DECLARE_METATYPE(SaverUtil::Nod)
        QDataStream & operator << (QDataStream & out, const SaverUtil::Nod & Valeur);
        QDataStream & operator >> (QDataStream & in, SaverUtil::Nod & Valeur);


        Q_DECLARE_METATYPE(SaverUtil)
        QDataStream & operator << (QDataStream & out, const SaverUtil & Valeur);
        QDataStream & operator >> (QDataStream & in, SaverUtil & Valeur);


#endif // SAVERUTIL_H



