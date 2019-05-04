/********************************************************************************
** Form generated from reading ui file 'arcpropertie.ui'
**
** Created: Mon 1. Jan 17:43:37 2018
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ARCPROPERTIE_H
#define UI_ARCPROPERTIE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ArcPropertie
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *value;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *flux;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *capacity;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ArcPropertie)
    {
        if (ArcPropertie->objectName().isEmpty())
            ArcPropertie->setObjectName(QString::fromUtf8("ArcPropertie"));
        ArcPropertie->resize(240, 201);
        verticalLayout = new QVBoxLayout(ArcPropertie);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ArcPropertie);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMargin(10);

        horizontalLayout->addWidget(label);

        value = new QSpinBox(ArcPropertie);
        value->setObjectName(QString::fromUtf8("value"));
        value->setMinimum(-888);
        value->setMaximum(888);

        horizontalLayout->addWidget(value);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ArcPropertie);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMargin(10);

        horizontalLayout_3->addWidget(label_3);

        flux = new QSpinBox(ArcPropertie);
        flux->setObjectName(QString::fromUtf8("flux"));

        horizontalLayout_3->addWidget(flux);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ArcPropertie);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMargin(10);

        horizontalLayout_2->addWidget(label_2);

        capacity = new QSpinBox(ArcPropertie);
        capacity->setObjectName(QString::fromUtf8("capacity"));

        horizontalLayout_2->addWidget(capacity);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(ArcPropertie);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ArcPropertie);
        QObject::connect(buttonBox, SIGNAL(accepted()), ArcPropertie, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ArcPropertie, SLOT(reject()));

        QMetaObject::connectSlotsByName(ArcPropertie);
    } // setupUi

    void retranslateUi(QDialog *ArcPropertie)
    {
        ArcPropertie->setWindowTitle(QApplication::translate("ArcPropertie", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ArcPropertie", "Value", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ArcPropertie", "Flux", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ArcPropertie", "Capacity", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ArcPropertie);
    } // retranslateUi

};

namespace Ui {
    class ArcPropertie: public Ui_ArcPropertie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARCPROPERTIE_H
