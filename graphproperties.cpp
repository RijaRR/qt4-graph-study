#include "graphproperties.h"
#include "ui_graphproperties.h"
#include <QThread>
#include <qtconcurrentrun.h>
#include <QtDebug>
#include <QMessageBox>

GraphProperties::GraphProperties(Scene* scene,QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::GraphProperties)
{
    m_ui->setupUi(this);
    myScene=scene;
    myUtil= new Util(myScene);
    computeAndDisplayProperties();
    connect(m_ui->refreshB,SIGNAL(clicked()),this,SLOT(refresh()));
}

GraphProperties::~GraphProperties()
{
    delete m_ui;
}

void GraphProperties::changeEvent(QEvent *e)
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



void GraphProperties::computeAndDisplayProperties(){
    if(myScene->getArcs().size()>0 || myScene->getNodes().size()>0)
    {
        QFuture<int> future = QtConcurrent::run(myUtil, &Util::getOrder);
m_ui->orderL->setText(QString::number(future.result()));

 QFuture<Cause> future2 = QtConcurrent::run(myUtil, &Util::isComplete);
 m_ui->completeL->setText((future2.result().b)?QString("oui"):QString("non"));
  m_ui->completeLR->setText((future2.result().raison));

  // QFuture< QList< QList< Node *> > > future3 = QtConcurrent::run(myUtil, &Util::listPathBetween);
// m_ui->cycleL->setText((future3.result().b)?QString("oui"):QString("non"));
 // m_ui->cycleLR->setText((future3.result().raison));

   QFuture<Cause> future4 = QtConcurrent::run(myUtil, &Util::isConnexe);
 m_ui->connexeL->setText((future4.result().b)?QString("oui"):QString("non"));
  m_ui->connexeLR->setText((future4.result().raison));

   QFuture<Cause> future5 = QtConcurrent::run(myUtil, &Util::isRegular);
 m_ui->regularL->setText((future5.result().b)?QString("oui"):QString("non"));
  m_ui->regularLR->setText((future5.result().raison));

    }




}

void GraphProperties::refresh(){
    computeAndDisplayProperties();
}



