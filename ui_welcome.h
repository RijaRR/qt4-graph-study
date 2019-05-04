/********************************************************************************
** Form generated from reading ui file 'welcome.ui'
**
** Created: Wed 10. Jan 14:45:01 2018
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *buttonOk;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QTextEdit *about;

    void setupUi(QDialog *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QString::fromUtf8("Welcome"));
        Welcome->setWindowModality(Qt::WindowModal);
        Welcome->resize(445, 320);
        Welcome->setModal(true);
        verticalLayout = new QVBoxLayout(Welcome);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Welcome);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Raavi"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setMargin(2);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Welcome);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        comboBox = new QComboBox(Welcome);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        buttonOk = new QPushButton(Welcome);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));

        verticalLayout->addWidget(buttonOk);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Welcome);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        pushButton_2 = new QPushButton(Welcome);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMaximumSize(QSize(33, 33));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        about = new QTextEdit(Welcome);
        about->setObjectName(QString::fromUtf8("about"));
        about->setEnabled(true);
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS PMincho"));
        about->setFont(font2);
        about->setAcceptDrops(false);
        about->setAcceptRichText(false);
        about->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(about);


        retranslateUi(Welcome);
        QObject::connect(buttonOk, SIGNAL(clicked()), Welcome, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), about, SLOT(show()));

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QDialog *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "Bienvenu", 0, QApplication::UnicodeUTF8));
        Welcome->setStyleSheet(QApplication::translate("Welcome", "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 144, 0, 255), stop:1 rgba(255, 255, 255, 255))\n"
"", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Welcome", "Bienvenu", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Welcome", "Choisissez un type de graphe :", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Welcome", "Valu\303\251, non orient\303\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Welcome", "Valu\303\251, orient\303\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Welcome", "Non valu\303\251, orient\303\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Welcome", "Non valu\303\251, non orient\303\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Welcome", "Valu\303\251 avec flux", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Welcome", "Non valu\303\251 avec flux", 0, QApplication::UnicodeUTF8)
        );
        comboBox->setStyleSheet(QApplication::translate("Welcome", "background-color:white;", 0, QApplication::UnicodeUTF8));
        buttonOk->setStyleSheet(QApplication::translate("Welcome", "background-color:rgb(184, 213, 255)", 0, QApplication::UnicodeUTF8));
        buttonOk->setText(QApplication::translate("Welcome", "Ok", 0, QApplication::UnicodeUTF8));
        label_3->setStyleSheet(QApplication::translate("Welcome", "opacity:0;\n"
"", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Welcome", "A propos", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Welcome", "+", 0, QApplication::UnicodeUTF8));
        about->setStyleSheet(QApplication::translate("Welcome", "margin-left:5px;", 0, QApplication::UnicodeUTF8));
        about->setHtml(QApplication::translate("Welcome", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS PMincho'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">Ce programme porte sur les algrorithmes courants utiliis\303\251s sur diff\303\251rents types de graphes. Ces mod\303\250les peuvent servir \303\240 r\303\251soudre des probl\303\250mes d'optimisation et de recherche sur des structures de donn\303\251es, un ensemble de r\303\251seau, ou d'autres probl\303\250mes pouvant se ramener au graphe.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-fa"
                        "mily:'MS Shell Dlg 2'; font-size:8pt;\">Le programme est loin d'\303\252tre aboutit. Il reste encore des algorithmes \303\240 impl\303\251menter et la gestion des erreurs est in\303\251xistante. </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Welcome);
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
