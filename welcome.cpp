#include "welcome.h"
#include "ui_welcome.h"
#include <QtDebug>

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Welcome)
{
    m_ui->setupUi(this);
    m_ui->about->hide();
    myGraphType="Valué, non orienté";
    connect(m_ui->buttonOk,SIGNAL(clicked()),this,SLOT(setGraphType()));
}

Welcome::~Welcome()
{
    delete m_ui;

}

void Welcome::setGraphType(){
    myGraphType= m_ui->comboBox->currentText();
    emit typeSet();

}

QString Welcome::graphType(){
    return myGraphType;
}

int Welcome::graphTypeInt(){

    if(myGraphType=="Valué, non orienté")
    {
        return 1;
    }
    if(myGraphType=="Valué, orienté")
    {
       return 0;
    }
    if(myGraphType=="Non valué, orienté")
    {
       return 2;
    }
    if(myGraphType=="Non valué, non orienté")
    {
       return 3;
    }
    if(myGraphType=="Valué avec flux")
    {
       return 5;
    }
     if(myGraphType=="Non valué avec flux")
    {
       return 4;
    }
return -1;
}

void Welcome::changeEvent(QEvent *e)
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
