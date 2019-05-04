/********************************************************************************
** Form generated from reading ui file 'nodeproperties.ui'
**
** Created: Wed 10. Jan 15:24:09 2018
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NODEPROPERTIES_H
#define UI_NODEPROPERTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_NodeProperties
{
public:

    void setupUi(QDialog *NodeProperties)
    {
        if (NodeProperties->objectName().isEmpty())
            NodeProperties->setObjectName(QString::fromUtf8("NodeProperties"));
        NodeProperties->resize(240, 320);

        retranslateUi(NodeProperties);

        QMetaObject::connectSlotsByName(NodeProperties);
    } // setupUi

    void retranslateUi(QDialog *NodeProperties)
    {
        NodeProperties->setWindowTitle(QApplication::translate("NodeProperties", "Propri\303\251t\303\251 du noeud", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NodeProperties);
    } // retranslateUi

};

namespace Ui {
    class NodeProperties: public Ui_NodeProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEPROPERTIES_H
