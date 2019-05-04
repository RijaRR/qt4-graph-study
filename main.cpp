#include <QtGui/QApplication>
#include <QtDebug>
#include <QFile>
#include <QVariant>
#include "mainwindow.h"
#include "welcome.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();







    return a.exec();
}
