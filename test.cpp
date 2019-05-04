#include "test.h"
#include "ui_test.h"
#include <QtDebug>

Test::Test(Scene* s, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Test)
{
    m_ui->setupUi(this);
    m_scene = s;
    m_util =  new Util(s);

    makeUINodeList();
    connect(m_ui->launch,SIGNAL(clicked()),this,SLOT(startAlgo()));
}

void Test::startAlgo(){

           if(m_scene->items().size()==0){
                m_ui->textEdit->setText(QString("le graphe est vide"));
                return;
           }

              Node* start= m_scene->findById(m_ui->nodeList->currentText().toInt());
              Node* end = m_scene->findById(m_ui->nodeList2->currentText().toInt());

           if(m_ui->algoSelect->currentText()=="Ford-Fulkerson"){

              if(start==end){
                  m_ui->textEdit->setText(QString("noeud identique ! "));
                  return;
              }

                 m_ui->launch->setEnabled(false);
              m_util->fordFulkerson(start,end);
               m_ui->launch->setEnabled(true);
             showAlgoText(m_util->getTextFordFulkerson());
           }

           if(m_ui->algoSelect->currentText()=="Dijkstra")
           {
               if(start==end){
                  m_ui->textEdit->setText(QString("noeud identique ! "));
                  return;
              }
               m_ui->launch->setEnabled(false);
               showAlgoText(m_util->dijkstra(start,end));
                m_ui->launch->setEnabled(true);
           }


           if(m_ui->algoSelect->currentText()=="Parcours en profondeur"){
                   
                QStringList s= m_util->inDephSearch(start);
                showAlgoText(s);
           }

            if(m_ui->algoSelect->currentText()=="Parcours en largeur"){

                QStringList s= m_util->inBreadthSearch(start);

                showAlgoText(s);
           }
            if(m_ui->algoSelect->currentText()=="Prim"){


                if(start)
                {
                    QStringList s= m_util->prim(start);

                showAlgoText(s);
                }else{
                   qDebug()<<"non défini";
                }



           }


             if(m_ui->algoSelect->currentText()=="Chemin entre deux noeuds (graphe orienté)"){
                 if(start==end){
                  m_ui->textEdit->setText(QString("noeud identique ! "));
                  return;
              }
                 m_util->listPathBetween(start,end);
                 showAlgoText(m_util->getTextListPathBetween());
           }


}

void Test::makeUINodeList(){

    foreach(Node* n, m_scene->getNodes()){
        if(n->getName().size()>0){
            m_ui->nodeList->addItem(n->getName(),QVariant(n->getNodeId()));
             m_ui->nodeList2->addItem(n->getName(),QVariant(n->getNodeId()));
        }else{
            m_ui->nodeList->addItem(QString::number(n->getNodeId()),QVariant(n->getNodeId()));
             m_ui->nodeList2->addItem(QString::number(n->getNodeId()),QVariant(n->getNodeId()));
        }
    }

/*
    if(m_scene->getArcType()!= Arc::flux_not_valued && m_scene->getArcType()!=Arc::flux_not_valued)
    {
        int fulkerson=m_ui->algoSelect->findText("Ford-Fulkerson");
        m_ui->algoSelect->removeItem(fulkerson);
    }
    */

    if(!m_scene->getArcs().isEmpty())
    {
        if(!m_scene->getArcs().first()->isValued())
        {
           int dij =m_ui->algoSelect->findText("Dijkstra");
           m_ui->algoSelect->removeItem(dij);
           int belman= m_ui->algoSelect->findText("Ford-Bellman");
            m_ui->algoSelect->removeItem(belman);
           int prim = m_ui->algoSelect->findText("Prim");
           m_ui->algoSelect->removeItem(prim);

        }
        if(!m_scene->getArcs().first()->isOriented())
        {
            int parcour= m_ui->algoSelect->findText("Chemin entre deux noeuds (graphe orienté)");
            m_ui->algoSelect->removeItem(parcour);
        }

    }else{
        m_ui->algoSelect->setDisabled(true);
        m_ui->label_4->setText("Le graphe n'a pas d'arc");
    }

}


void Test::appendMessage(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
        return;


}


void Test::showAlgoText(QStringList l){
     m_ui->textEdit->document()->setDefaultStyleSheet(QString(".j{color:green;}"));
    foreach(QString e, l)
    {

m_ui->textEdit->append(e);
    }

}








Test::~Test()
{
    delete m_ui;
}

void Test::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
