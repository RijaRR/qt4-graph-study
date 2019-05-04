/********************************************************************************
** Form generated from reading ui file 'test.ui'
**
** Created: Wed 10. Jan 15:35:56 2018
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *nodeList2;
    QPushButton *launch;
    QLabel *label_4;
    QComboBox *algoSelect;
    QComboBox *nodeList;

    void setupUi(QDialog *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QString::fromUtf8("Test"));
        Test->resize(368, 320);
        verticalLayout = new QVBoxLayout(Test);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(Test);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 4, 0, 1, 3);

        label = new QLabel(Test);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Test);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(Test);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        nodeList2 = new QComboBox(Test);
        nodeList2->setObjectName(QString::fromUtf8("nodeList2"));

        gridLayout->addWidget(nodeList2, 2, 1, 1, 2);

        launch = new QPushButton(Test);
        launch->setObjectName(QString::fromUtf8("launch"));

        gridLayout->addWidget(launch, 3, 2, 1, 1);

        label_4 = new QLabel(Test);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 2);

        algoSelect = new QComboBox(Test);
        algoSelect->setObjectName(QString::fromUtf8("algoSelect"));

        gridLayout->addWidget(algoSelect, 0, 1, 1, 2);

        nodeList = new QComboBox(Test);
        nodeList->setObjectName(QString::fromUtf8("nodeList"));

        gridLayout->addWidget(nodeList, 1, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QDialog *Test)
    {
        Test->setWindowTitle(QApplication::translate("Test", "Executer un algorithme", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Test", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Choisir Algorithme</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Test", "Noeud d\303\251part :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Test", "Noeud arriv\303\251 :", 0, QApplication::UnicodeUTF8));
        launch->setText(QApplication::translate("Test", "Lancer", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Test", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic;\">Statut</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        algoSelect->clear();
        algoSelect->insertItems(0, QStringList()
         << QApplication::translate("Test", "Dijkstra", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Test", "Ford-Fulkerson", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Test", "Parcours en profondeur", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Test", "Parcours en largeur", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Test", "Ford-Bellman", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Test", "Floyd-Warshall", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Test", "Prim", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Test", "Chemin entre deux noeuds (graphe orient\303\251)", 0, QApplication::UnicodeUTF8)
        );
        Q_UNUSED(Test);
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
