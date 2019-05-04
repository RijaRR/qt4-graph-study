/********************************************************************************
** Form generated from reading ui file 'algoimplementation.ui'
**
** Created: Fri 29. Dec 10:51:10 2017
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ALGOIMPLEMENTATION_H
#define UI_ALGOIMPLEMENTATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlgoImplementation
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_3;
    QLCDNumber *lcdNumber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AlgoImplementation)
    {
        if (AlgoImplementation->objectName().isEmpty())
            AlgoImplementation->setObjectName(QString::fromUtf8("AlgoImplementation"));
        AlgoImplementation->resize(577, 431);
        AlgoImplementation->setMaximumSize(QSize(600, 900));
        centralwidget = new QWidget(AlgoImplementation);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 371, 371));
        graphicsView->setSceneRect(QRectF(0, 0, 300, 600));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(380, 10, 471, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(3, -1, 278, 9);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(50, 16777215));
        pushButton->setBaseSize(QSize(20, 0));
        pushButton->setAutoFillBackground(true);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(50, 16777215));
        pushButton_2->setAutoFillBackground(true);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lcdNumber = new QLCDNumber(verticalLayoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);
        lcdNumber->setMinimumSize(QSize(55, 55));

        horizontalLayout_3->addWidget(lcdNumber);


        verticalLayout->addLayout(horizontalLayout_3);

        AlgoImplementation->setCentralWidget(centralwidget);
        graphicsView->raise();
        verticalLayoutWidget->raise();
        menubar = new QMenuBar(AlgoImplementation);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 577, 22));
        AlgoImplementation->setMenuBar(menubar);
        statusbar = new QStatusBar(AlgoImplementation);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AlgoImplementation->setStatusBar(statusbar);

        retranslateUi(AlgoImplementation);

        QMetaObject::connectSlotsByName(AlgoImplementation);
    } // setupUi

    void retranslateUi(QMainWindow *AlgoImplementation)
    {
        AlgoImplementation->setWindowTitle(QApplication::translate("AlgoImplementation", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AlgoImplementation", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AlgoImplementation", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("AlgoImplementation", "PushButton", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AlgoImplementation);
    } // retranslateUi

};

namespace Ui {
    class AlgoImplementation: public Ui_AlgoImplementation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALGOIMPLEMENTATION_H
