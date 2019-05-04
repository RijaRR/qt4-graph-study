#include "algoimplementation.h"
#include "ui_algoimplementation.h"

AlgoImplementation::AlgoImplementation(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::AlgoImplementation)
{
    m_ui->setupUi(this);
}

AlgoImplementation::~AlgoImplementation()
{
    delete m_ui;
}

void AlgoImplementation::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
