#include "welcome.h"
#include "ui_welcome.h"
#include <QtDebug>

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Welcome)
{
    m_ui->setupUi(this);
    m_ui->about->hide();
    myGraphType="Valu�, non orient�";
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

    if(myGraphType=="Valu�, non orient�")
    {
        return 1;
    }
    if(myGraphType=="Valu�, orient�")
    {
       return 0;
    }
    if(myGraphType=="Non valu�, orient�")
    {
       return 2;
    }
    if(myGraphType=="Non valu�, non orient�")
    {
       return 3;
    }
    if(myGraphType=="Valu� avec flux")
    {
       return 5;
    }
     if(myGraphType=="Non valu� avec flux")
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
