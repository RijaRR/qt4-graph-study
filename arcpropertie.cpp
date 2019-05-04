#include "arcpropertie.h"
#include "ui_arcpropertie.h"
#include <QtDebug>
#include <QMessageBox>

ArcPropertie::ArcPropertie(Arc *arc1, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::ArcPropertie)
{
    m_ui->setupUi(this);
    m_arc=arc1;
    this->setWindowTitle(QString("Arc properties"));
    hideAccordingToType();
    updateFields();
 connect(m_ui->buttonBox,SIGNAL(accepted()),this, SLOT(changeArcValues()));
}

ArcPropertie::~ArcPropertie()
{
    delete m_ui;
}

void ArcPropertie::changeEvent(QEvent *e)
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

void ArcPropertie::changeArcValues(){
    if(m_arc->isValued())
    {
         int e= m_ui->value->value();
  m_arc->setV(e);

    }
    if(m_arc->hasFlux()){
        int c= m_ui->capacity->value();
        int f= m_ui->flux->value();
        if(f<=c){
             m_arc->setCapacity(c);
        m_arc->setFlux(f);
        }else{
          QMessageBox::information(this, tr("Donné incohérent"),
                              tr("Un flux doit toujours être inférieur ou égale à la capacité de l'arc"));
        }

    }
}

void ArcPropertie::hideAccordingToType(){
if(m_arc->isValued() && !m_arc->hasFlux()){
   m_ui->capacity->setEnabled(false);
   m_ui->flux->setEnabled(false);

}
if(m_arc->hasFlux() && !m_arc->isValued())
{
    m_ui->value->setEnabled(false);
}
}

void ArcPropertie::updateFields(){

    if(m_arc->isValued())
    {

         m_ui->value->setValue(m_arc->getValue());
    }
    if(m_arc->hasFlux()){
        m_ui->capacity->setValue(m_arc->getCapacity());
       m_ui->flux->setValue(m_arc->getFlux());
    }
}


