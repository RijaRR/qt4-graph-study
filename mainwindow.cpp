#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scene.h"
#include "arc.h"
#include "test.h"
#include "arcpropertie.h"
#include "graphproperties.h"
#include "welcome.h"
#include <QtDebug>
#include <QSettings>
#include <QDateTime>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->drawNode->setIcon(QIcon(":/img/a.png"));
    ui->drawArc->setIcon(QIcon(":/img/drawArc.png"));
    ui->deleteNode->setIcon(QIcon(":/img/delete.png"));

    readSetting();

    createActions();
    createMenuRecentFile();
     itemMenu = new QMenu();
     itemMenuArc = new QMenu();
   itemMenu->addAction(deleteNode);
   itemMenuArc->addAction(deleteNode);
   itemMenuArc->addAction(arcProperties);


   w= new Welcome(this);
   w->show();

   connect(w,SIGNAL(typeSet()),this,SLOT(configScene()));



   ui->deleteNode->addAction(deleteNode);

    scene= new Scene(itemMenu,itemMenuArc);
    ui->graphicsView->setScene(scene);




    pointerTypeGroup = new QButtonGroup;
    pointerTypeGroup->addButton(ui->drawNode, int(Scene::InsertNode));
    pointerTypeGroup->addButton(ui->drawArc,
                                int(Scene::InsertLine));
    connect(pointerTypeGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(buttonGroupClicked(int)));


    connect(ui->graphPropertiesAction,SIGNAL(triggered()),this, SLOT(showGraphProperties()));
    connect(ui->actionEnregistrer,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->actionSupprimer_tout, SIGNAL(triggered()),this,SLOT(clearScene()));
     connect(ui->actionEnregistrer_sous, SIGNAL(triggered()),this,SLOT(saveAs()));
     connect(ui->actionOuvrir,SIGNAL(triggered()),this,SLOT(open()));
connect(ui->actionAlgorithme,SIGNAL(triggered()),this,SLOT(showAlgorithmWindow()));
connect(ui->actionNouveau,SIGNAL(triggered()),this, SLOT(newProject()));
connect(ui->actionExporter_une_image,SIGNAL(triggered()),this,SLOT(exportAsImage()));

    myFileName="";


}

void MainWindow::newProject()
{
    clearScene();
    w= new Welcome(this);
   w->show();

   connect(w,SIGNAL(typeSet()),this,SLOT(configScene()));
    myFileName="";
    this->setWindowTitle("Nouveau graphe");

}



void MainWindow::configScene(){

    myGraphType = w->graphType();

    if(myGraphType=="Valué, non orienté")
    {
        scene->setArcType(Arc::ArcType(1));
    }
    if(myGraphType=="Valué, orienté")
    {
        scene->setArcType(Arc::ArcType(0));
    }
    if(myGraphType=="Non valué, orienté")
    {

        scene->setArcType(Arc::ArcType(2));
    }
    if(myGraphType=="Non valué, non orienté")
    {

        scene->setArcType(Arc::ArcType(3));
    }
    if(myGraphType=="Valué avec flux")
    {
        scene->setArcType(Arc::ArcType(5));
    }
     if(myGraphType=="Non valué avec flux")
    {
        scene->setArcType(Arc::ArcType(4));
    }

     w->deleteLater();
}






void MainWindow::createMenuRecentFile(){
    QAction* a;
QAction* b;
if(!myRecentFile.isEmpty())
{
int sz = myRecentFile.size();
    if(sz>2)
    {
        QString nm= myRecentFile.keys().at(sz-1);
        int ind= nm.lastIndexOf("/");
        a = new QAction(nm.right(nm.size()-ind-1),this);
    ui->menuFichier->addAction(a);
    a->setData(QVariant(nm));
    connect(a,SIGNAL(triggered()),this,SLOT(wireRecents()));


    QString nm2= myRecentFile.keys().at(sz-2);
        ind= nm2.lastIndexOf("/");
    b = new QAction(nm2.right(nm2.size()-ind-1),this);
    ui->menuFichier->addAction(b);
    b->setData(QVariant(nm2));
     connect(b,SIGNAL(triggered()),this,SLOT(wireRecents()));

    }
    if(sz==2)
    {
       QString nm= myRecentFile.keys().at(1);
        int ind= nm.lastIndexOf("/");
        a = new QAction(nm.right(nm.size()-ind-1),this);
    ui->menuFichier->addAction(a);
    }

}

}

void MainWindow::exportAsImage()
{

 if(scene->getArcs().size()<1 && scene->getNodes().size()<1){
       // ui->actionEnregistrer->setDisabled(false);
        QMessageBox::information(this, tr("Graphe vide"),
                                 tr("Le graphe est vide"));
    }else{
        QImage image(500,500,QImage::Format_ARGB32);
       image.fill(0);
       QPainter painter(&image);

 // print, fitting the viewport contents into a full page
       ui->graphicsView->render(&painter);
            QString fileName;
             fileName = QFileDialog::getSaveFileName(this,
        tr("Enregistrer"), "", "*.PNG");


    if (!fileName.isEmpty()) {
           QFile file(fileName);
          file.open( QIODevice::WriteOnly);
          if(!image.save(&file,"PNG"))
          {
              QMessageBox::information(this, tr("erreur"),
                                 tr("Erreur lors de l'ecriture de l'image"));
          }
         file.close();
}
    }

     }












void MainWindow::wireRecents()
{
    QAction* a = (QAction* )sender();

    QString fileName =a->data().toString ();
    if(!fileName.isEmpty()){
         if(scene->open(fileName)){
           myFileName=fileName;
            this->setWindowTitle(fileName);
         }else{
              QMessageBox::information(this, tr("Erreur"),
                                 tr("Une erreur est survenu lors de l'ouverture"));
         }
    }


}



void MainWindow::readSetting(){
    QSettings settings("InfoL2", "Grapheur");
       myRecentFile.clear();
     int size = settings.beginReadArray("recents");


 for (int i = 0; i < size; ++i) {
     settings.setArrayIndex(i);
     myRecentFile.insert(settings.value("fileName").toString(),settings.value("date").toDateTime());
 }
 settings.endArray();

 if(0<size-3)
 {
  for (int i = size-3; 0 < i; --i) {
       QString rc="recents";
        QString nb= QString::number(i);
        QString s("/");
     QString strD=rc+s+nb+s+QString("date");
     QString strK=rc+s+nb+s+QString("fileName");


     settings.remove(strK);
     settings.remove(strD);

 }
}






}



void MainWindow::writeSetting(QString fileName){
     QSettings settings("InfoL2", "Grapheur");
     QDateTime now = QDateTime::currentDateTime();

 settings.beginWriteArray("recents");

     settings.setArrayIndex(settings.allKeys().size());
     settings.setValue("fileName", fileName);
     settings.setValue("date", now );

 settings.endArray();

 myRecentFile.insert(fileName,now);

}






void MainWindow::clearScene(){
    if(scene->getNodes().size()>0){
        scene->clean();
    }

}

void MainWindow::open(){
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Enregistrer"), "", "*.rj");
    if(!fileName.isEmpty()){
         if(scene->open(fileName)){
           myFileName=fileName;
            this->setWindowTitle(fileName);
         }else{
              QMessageBox::information(this, tr("Erreur"),
                                 tr("Une erreur est survenu lors de l'ouverture"));
         }
    }
}



void MainWindow::save(){

    if(scene->getArcs().size()<1 && scene->getNodes().size()<1){
       // ui->actionEnregistrer->setDisabled(false);
        QMessageBox::information(this, tr("Graphe vide"),
                                 tr("Le graphe est vide"));
    }else{
            QString fileName;
        if(myFileName.length()>0){
            fileName=myFileName;
        }else{
             fileName = QFileDialog::getSaveFileName(this,
        tr("Enregistrer"), "", "*.rj");
        }

    if (!fileName.isEmpty()) {
           if(!scene->saveIn(fileName)){
QMessageBox::information(this, tr("Erreur lors de la sauvegarde"),
                                 tr("Un erreur inatendu est survenu"));
           }else{
            this->setWindowTitle(fileName);
            myFileName= fileName;
            writeSetting(fileName);
           }
}
    }
    }

void MainWindow::saveAs(){
    QString fileName;
     if(scene->getArcs().size()<1 && scene->getNodes().size()<1){
       // ui->actionEnregistrer->setDisabled(false);
        QMessageBox::information(this, tr("Graphe vide"),
                                 tr("Le graphe est vide"));
    }else{
        fileName= QFileDialog::getSaveFileName(this,
        tr("Enregistrer sous"), "", "*.rj");
    }

       if (!fileName.isEmpty()) {
           if(!scene->saveIn(fileName)){
QMessageBox::information(this, tr("Erreur lors de la sauvegarde"),
                                 tr("Un erreur inatendu est survenu"));
               writeSetting(fileName);
           }else{
            this->setWindowTitle(fileName);
            myFileName= fileName;
           }
}
}





void MainWindow::buttonGroupClicked(int id){
    scene->setMode(Scene::Mode(id));
}

void MainWindow::deleteItem(){

foreach (QGraphicsItem *item, scene->selectedItems()) {
        if (item->type() == Node::Type) {

            Node* node=qgraphicsitem_cast<Node *>(item);
            //supprime les arcs rattachés au sommet
            scene->removeNode(node);
            node->removeArcs();//supprime les arcs du sommet de la liste arc/supprime noeuds de la liste noeuds
        }else if(item->type()==Arc::Type){
            // qDebug()<<"entrer condition arc";
            scene->removeArc(qgraphicsitem_cast<Arc *>(item));
        }

        scene->removeItem(item);
       // qDebug()<<"scene arcs lengh"<<scene->getArcs().size()<<" scene nodes length "<<scene->getNodes().size();

    }
}

void MainWindow::createActions(){

    deleteNode = new QAction(QIcon(":/img/delete.png"),
                               tr("&Delete"), this);
    deleteNode->setShortcut(tr("Delete"));
    deleteNode->setStatusTip(tr("Delete node from graph"));
    connect(deleteNode, SIGNAL(triggered()),
        this, SLOT(deleteItem()));

    arcProperties = new QAction(tr("Properties"),this);
    connect(arcProperties, SIGNAL(triggered()), this,
            SLOT(changeArcProperties()));



}


void MainWindow::changeArcProperties(){
    //which arc
    Arc* a=0;
    foreach (QGraphicsItem *item, scene->selectedItems()) {
        if (item->type() == Arc::Type) {
            a=qgraphicsitem_cast<Arc *>(item);
        }
    }
if(a!=0)
    {
    ArcPropertie* wdw= new ArcPropertie(a);
    wdw->show();
}


}


void MainWindow::showGraphProperties(){
    if(scene->getArcs().size()>0 || scene->getNodes().size()>0){
       GraphProperties* g = new GraphProperties(scene);
g->show();
    }else{
        QMessageBox::information(this, tr("Graph properties"),
                                 tr("Le graph est vide"));
    }




}

void MainWindow::showAlgorithmWindow(){
     Test* alogwindow = new Test(scene,this);
     alogwindow->show();


}




MainWindow::~MainWindow()
{
    delete ui;


}
