#include "nodeproperties.h"
#include "ui_nodeproperties.h"

NodeProperties::NodeProperties(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::NodeProperties)
{
    m_ui->setupUi(this);
}

NodeProperties::~NodeProperties()
{
    delete m_ui;
}

void NodeProperties::changeEvent(QEvent *e)
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
