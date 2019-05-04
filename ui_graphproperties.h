/********************************************************************************
** Form generated from reading ui file 'graphproperties.ui'
**
** Created: Sat 23. Dec 19:23:13 2017
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GRAPHPROPERTIES_H
#define UI_GRAPHPROPERTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphProperties
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *completeL;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *completeLR;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *cycleL;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *cycleLR;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLabel *regularL;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *regularLR;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLabel *connexeL;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *connexeLR;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_14;
    QLabel *orderL;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *refreshB;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GraphProperties)
    {
        if (GraphProperties->objectName().isEmpty())
            GraphProperties->setObjectName(QString::fromUtf8("GraphProperties"));
        GraphProperties->resize(393, 469);
        verticalLayoutWidget = new QWidget(GraphProperties);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 361, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(4, 3, 3, 3);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Andalus"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        completeL = new QLabel(verticalLayoutWidget);
        completeL->setObjectName(QString::fromUtf8("completeL"));

        horizontalLayout->addWidget(completeL);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        completeLR = new QLabel(verticalLayoutWidget);
        completeLR->setObjectName(QString::fromUtf8("completeLR"));

        horizontalLayout_2->addWidget(completeLR);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        cycleL = new QLabel(verticalLayoutWidget);
        cycleL->setObjectName(QString::fromUtf8("cycleL"));

        horizontalLayout_3->addWidget(cycleL);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        cycleLR = new QLabel(verticalLayoutWidget);
        cycleLR->setObjectName(QString::fromUtf8("cycleLR"));

        horizontalLayout_4->addWidget(cycleLR);


        verticalLayout->addLayout(horizontalLayout_4);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_5->addWidget(label_8);

        regularL = new QLabel(verticalLayoutWidget);
        regularL->setObjectName(QString::fromUtf8("regularL"));

        horizontalLayout_5->addWidget(regularL);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        regularLR = new QLabel(verticalLayoutWidget);
        regularLR->setObjectName(QString::fromUtf8("regularLR"));

        horizontalLayout_6->addWidget(regularLR);


        verticalLayout->addLayout(horizontalLayout_6);

        line_3 = new QFrame(verticalLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        horizontalLayout_7->addWidget(label_11);

        connexeL = new QLabel(verticalLayoutWidget);
        connexeL->setObjectName(QString::fromUtf8("connexeL"));

        horizontalLayout_7->addWidget(connexeL);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        connexeLR = new QLabel(verticalLayoutWidget);
        connexeLR->setObjectName(QString::fromUtf8("connexeLR"));

        horizontalLayout_8->addWidget(connexeLR);


        verticalLayout->addLayout(horizontalLayout_8);

        line_4 = new QFrame(verticalLayoutWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        horizontalLayout_9->addWidget(label_14);

        orderL = new QLabel(verticalLayoutWidget);
        orderL->setObjectName(QString::fromUtf8("orderL"));

        horizontalLayout_9->addWidget(orderL);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_9);

        refreshB = new QPushButton(verticalLayoutWidget);
        refreshB->setObjectName(QString::fromUtf8("refreshB"));

        verticalLayout->addWidget(refreshB);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        verticalLayoutWidget->raise();
        buttonBox->raise();

        retranslateUi(GraphProperties);
        QObject::connect(buttonBox, SIGNAL(accepted()), GraphProperties, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GraphProperties, SLOT(reject()));

        QMetaObject::connectSlotsByName(GraphProperties);
    } // setupUi

    void retranslateUi(QDialog *GraphProperties)
    {
        GraphProperties->setWindowTitle(QApplication::translate("GraphProperties", "Propri\303\251t\303\251s du graphe", 0, QApplication::UnicodeUTF8));
        GraphProperties->setStyleSheet(QApplication::translate("GraphProperties", "background-color:rgb(223, 255, 202);", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GraphProperties", "Complet:", 0, QApplication::UnicodeUTF8));
        completeL->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        completeLR->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GraphProperties", "Cycle:", 0, QApplication::UnicodeUTF8));
        cycleL->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        cycleLR->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("GraphProperties", "R\303\251gulier", 0, QApplication::UnicodeUTF8));
        regularL->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        regularLR->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("GraphProperties", "Connexe:", 0, QApplication::UnicodeUTF8));
        connexeL->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        connexeLR->setStyleSheet(QString());
        connexeLR->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("GraphProperties", "Ordre", 0, QApplication::UnicodeUTF8));
        orderL->setText(QApplication::translate("GraphProperties", "TextLabel", 0, QApplication::UnicodeUTF8));
        refreshB->setStyleSheet(QApplication::translate("GraphProperties", "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 144, 0, 255), stop:1 rgba(255, 255, 255, 255));", 0, QApplication::UnicodeUTF8));
        refreshB->setText(QApplication::translate("GraphProperties", "Rafra\303\256chir", 0, QApplication::UnicodeUTF8));
        buttonBox->setStyleSheet(QApplication::translate("GraphProperties", "background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 144, 0, 255), stop:1 rgba(255, 255, 255, 255));", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(GraphProperties);
    } // retranslateUi

};

namespace Ui {
    class GraphProperties: public Ui_GraphProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHPROPERTIES_H
