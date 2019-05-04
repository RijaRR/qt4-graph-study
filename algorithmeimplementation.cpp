#include "algorithmeimplementation.h"
#include "ui_algorithmeimplementation.h"

AlgorithmeImplementation::AlgorithmeImplementation(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::AlgorithmeImplementation)
{
    m_ui->setupUi(this);
}

AlgorithmeImplementation::~AlgorithmeImplementation()
{
    delete m_ui;
}

void AlgorithmeImplementation::changeEvent(QEvent *e)
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
