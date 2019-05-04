/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon 15. Jan 10:40:28 2018
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *graphPropertiesAction;
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionSupprimer_tout;
    QAction *actionEnregistrer_sous;
    QAction *actionRecents;
    QAction *actionAlgorithme;
    QAction *actionNouveau;
    QAction *actionExporter_une_image;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *drawArc;
    QToolButton *drawNode;
    QToolButton *deleteNode;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuAlgorithmes;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/img/logo.png")), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        graphPropertiesAction = new QAction(MainWindow);
        graphPropertiesAction->setObjectName(QString::fromUtf8("graphPropertiesAction"));
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        actionSupprimer_tout = new QAction(MainWindow);
        actionSupprimer_tout->setObjectName(QString::fromUtf8("actionSupprimer_tout"));
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName(QString::fromUtf8("actionEnregistrer_sous"));
        actionRecents = new QAction(MainWindow);
        actionRecents->setObjectName(QString::fromUtf8("actionRecents"));
        actionAlgorithme = new QAction(MainWindow);
        actionAlgorithme->setObjectName(QString::fromUtf8("actionAlgorithme"));
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QString::fromUtf8("actionNouveau"));
        actionExporter_une_image = new QAction(MainWindow);
        actionExporter_une_image->setObjectName(QString::fromUtf8("actionExporter_une_image"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        drawArc = new QToolButton(centralWidget);
        drawArc->setObjectName(QString::fromUtf8("drawArc"));

        horizontalLayout->addWidget(drawArc);

        drawNode = new QToolButton(centralWidget);
        drawNode->setObjectName(QString::fromUtf8("drawNode"));

        horizontalLayout->addWidget(drawNode);

        deleteNode = new QToolButton(centralWidget);
        deleteNode->setObjectName(QString::fromUtf8("deleteNode"));

        horizontalLayout->addWidget(deleteNode);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menuAlgorithmes = new QMenu(menuBar);
        menuAlgorithmes->setObjectName(QString::fromUtf8("menuAlgorithmes"));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuAlgorithmes->menuAction());
        menuAlgorithmes->addAction(graphPropertiesAction);
        menuAlgorithmes->addAction(actionAlgorithme);
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionNouveau);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addAction(actionExporter_une_image);
        menuEdition->addAction(actionSupprimer_tout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        MainWindow->setStyleSheet(QString());
        graphPropertiesAction->setText(QApplication::translate("MainWindow", "Propri\303\251t\303\251s du graphe", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir", 0, QApplication::UnicodeUTF8));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0, QApplication::UnicodeUTF8));
        actionSupprimer_tout->setText(QApplication::translate("MainWindow", "Supprimer tout", 0, QApplication::UnicodeUTF8));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "Enregistrer sous", 0, QApplication::UnicodeUTF8));
        actionRecents->setText(QApplication::translate("MainWindow", "Recents", 0, QApplication::UnicodeUTF8));
        actionAlgorithme->setText(QApplication::translate("MainWindow", "Impl\303\251menter un algorithme", 0, QApplication::UnicodeUTF8));
        actionNouveau->setText(QApplication::translate("MainWindow", "Nouveau", 0, QApplication::UnicodeUTF8));
        actionExporter_une_image->setText(QApplication::translate("MainWindow", "Exporter une image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        drawArc->setToolTip(QApplication::translate("MainWindow", "Dessinner un arc (A)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        drawArc->setStyleSheet(QApplication::translate("MainWindow", "background-color:rgb(237, 255, 231)", 0, QApplication::UnicodeUTF8));
        drawArc->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        drawNode->setToolTip(QApplication::translate("MainWindow", "Dessiner un noeud (N)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        drawNode->setStyleSheet(QApplication::translate("MainWindow", "background-color:rgb(237, 255, 231)", 0, QApplication::UnicodeUTF8));
        drawNode->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteNode->setToolTip(QApplication::translate("MainWindow", "Supprimer un \303\251l\303\251ment", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteNode->setStyleSheet(QApplication::translate("MainWindow", "background-color:rgb(237, 255, 231)", 0, QApplication::UnicodeUTF8));
        deleteNode->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        menuAlgorithmes->setTitle(QApplication::translate("MainWindow", "Algorithmes", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        mainToolBar->setStyleSheet(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
