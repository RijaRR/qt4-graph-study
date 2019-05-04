/********************************************************************************
** Form generated from reading ui file 'algorithmeimplementation.ui'
**
** Created: Fri 29. Dec 13:24:52 2017
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ALGORITHMEIMPLEMENTATION_H
#define UI_ALGORITHMEIMPLEMENTATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlgorithmeImplementation
{
public:
    QAction *actionParcours_en_profondeur;
    QAction *actionParcours_en_largeur;
    QAction *actionDijkstra;
    QAction *actionFloyd_Warshall;
    QAction *actionFord_Bellman;
    QAction *actionPrim;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuAlgorithme;
    QMenu *menuChemin_le_plus_court;
    QMenu *menuArbre_opitmaux;
    QMenu *menuOptimisation_Flux;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AlgorithmeImplementation)
    {
        if (AlgorithmeImplementation->objectName().isEmpty())
            AlgorithmeImplementation->setObjectName(QString::fromUtf8("AlgorithmeImplementation"));
        AlgorithmeImplementation->resize(277, 378);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(7);
        sizePolicy.setVerticalStretch(8);
        sizePolicy.setHeightForWidth(AlgorithmeImplementation->sizePolicy().hasHeightForWidth());
        AlgorithmeImplementation->setSizePolicy(sizePolicy);
        AlgorithmeImplementation->setSizeIncrement(QSize(13, 12));
        AlgorithmeImplementation->setBaseSize(QSize(400, 500));
        actionParcours_en_profondeur = new QAction(AlgorithmeImplementation);
        actionParcours_en_profondeur->setObjectName(QString::fromUtf8("actionParcours_en_profondeur"));
        actionParcours_en_largeur = new QAction(AlgorithmeImplementation);
        actionParcours_en_largeur->setObjectName(QString::fromUtf8("actionParcours_en_largeur"));
        actionDijkstra = new QAction(AlgorithmeImplementation);
        actionDijkstra->setObjectName(QString::fromUtf8("actionDijkstra"));
        actionFloyd_Warshall = new QAction(AlgorithmeImplementation);
        actionFloyd_Warshall->setObjectName(QString::fromUtf8("actionFloyd_Warshall"));
        actionFord_Bellman = new QAction(AlgorithmeImplementation);
        actionFord_Bellman->setObjectName(QString::fromUtf8("actionFord_Bellman"));
        actionPrim = new QAction(AlgorithmeImplementation);
        actionPrim->setObjectName(QString::fromUtf8("actionPrim"));
        centralwidget = new QWidget(AlgorithmeImplementation);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(276, 335));
        centralwidget->setMaximumSize(QSize(276, 344));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(300, 300));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS UI Gothic"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 3);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 4, 0, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        AlgorithmeImplementation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AlgorithmeImplementation);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 277, 22));
        menuAlgorithme = new QMenu(menubar);
        menuAlgorithme->setObjectName(QString::fromUtf8("menuAlgorithme"));
        menuChemin_le_plus_court = new QMenu(menubar);
        menuChemin_le_plus_court->setObjectName(QString::fromUtf8("menuChemin_le_plus_court"));
        menuArbre_opitmaux = new QMenu(menubar);
        menuArbre_opitmaux->setObjectName(QString::fromUtf8("menuArbre_opitmaux"));
        menuOptimisation_Flux = new QMenu(menubar);
        menuOptimisation_Flux->setObjectName(QString::fromUtf8("menuOptimisation_Flux"));
        AlgorithmeImplementation->setMenuBar(menubar);
        statusbar = new QStatusBar(AlgorithmeImplementation);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AlgorithmeImplementation->setStatusBar(statusbar);

        menubar->addAction(menuAlgorithme->menuAction());
        menubar->addAction(menuChemin_le_plus_court->menuAction());
        menubar->addAction(menuArbre_opitmaux->menuAction());
        menubar->addAction(menuOptimisation_Flux->menuAction());
        menuAlgorithme->addAction(actionParcours_en_profondeur);
        menuAlgorithme->addAction(actionParcours_en_largeur);
        menuChemin_le_plus_court->addAction(actionDijkstra);
        menuChemin_le_plus_court->addAction(actionFloyd_Warshall);
        menuChemin_le_plus_court->addAction(actionFord_Bellman);
        menuArbre_opitmaux->addAction(actionPrim);

        retranslateUi(AlgorithmeImplementation);

        QMetaObject::connectSlotsByName(AlgorithmeImplementation);
    } // setupUi

    void retranslateUi(QMainWindow *AlgorithmeImplementation)
    {
        AlgorithmeImplementation->setWindowTitle(QApplication::translate("AlgorithmeImplementation", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionParcours_en_profondeur->setText(QApplication::translate("AlgorithmeImplementation", "Parcours en profondeur", 0, QApplication::UnicodeUTF8));
        actionParcours_en_largeur->setText(QApplication::translate("AlgorithmeImplementation", "Parcours en largeur", 0, QApplication::UnicodeUTF8));
        actionDijkstra->setText(QApplication::translate("AlgorithmeImplementation", "Dijkstra", 0, QApplication::UnicodeUTF8));
        actionFloyd_Warshall->setText(QApplication::translate("AlgorithmeImplementation", "Floyd-Warshall", 0, QApplication::UnicodeUTF8));
        actionFord_Bellman->setText(QApplication::translate("AlgorithmeImplementation", "Ford Bellman", 0, QApplication::UnicodeUTF8));
        actionPrim->setText(QApplication::translate("AlgorithmeImplementation", "Prim", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AlgorithmeImplementation", "Noeud de d\303\251part", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AlgorithmeImplementation", "Noeud d'arriv\303\251e", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AlgorithmeImplementation", "Lancer", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AlgorithmeImplementation", "Statut", 0, QApplication::UnicodeUTF8));
        menuAlgorithme->setTitle(QApplication::translate("AlgorithmeImplementation", "Parcours ", 0, QApplication::UnicodeUTF8));
        menuChemin_le_plus_court->setTitle(QApplication::translate("AlgorithmeImplementation", "Chemin le plus court", 0, QApplication::UnicodeUTF8));
        menuArbre_opitmaux->setTitle(QApplication::translate("AlgorithmeImplementation", "Arbre opitmaux", 0, QApplication::UnicodeUTF8));
        menuOptimisation_Flux->setTitle(QApplication::translate("AlgorithmeImplementation", "Optimisation Flux", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AlgorithmeImplementation: public Ui_AlgorithmeImplementation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALGORITHMEIMPLEMENTATION_H
