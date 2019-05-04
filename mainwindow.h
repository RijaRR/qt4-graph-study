#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QButtonGroup>
#include "scene.h"
#include "welcome.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void showGraphProperties();
    void buttonGroupClicked(int id);
    void deleteItem();
    void changeArcProperties();
    void save();
    void clearScene();
    void saveAs();
    void open();
    void showAlgorithmWindow();
    void configScene();
    void newProject();
    void wireRecents();
    void exportAsImage();



private:
    Ui::MainWindow *ui;
    Scene *scene;
    void createActions();
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
    QButtonGroup *pointerTypeGroup;
    QMenu *itemMenu;
    QMenu *itemMenuArc;
    QAction *deleteNode;
    QAction *nodeProperties;
    QAction *arcProperties;
    QMap<QString,QDateTime> myRecentFile;
    QString myFileName;
    void readSetting();
    void writeSetting(const QString fileName);
    void createMenuRecentFile();
    QString myGraphType;
    Welcome* w;


};

#endif // MAINWINDOW_H
