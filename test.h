#ifndef TEST_H
#define TEST_H

#include <QtGui/QDialog>
#include "scene.h"
#include "util.h"


namespace Ui {
    class Test;
}

class Test : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Test)
public:

    explicit Test( Scene* s,QWidget *parent = 0);
    virtual ~Test();
    void appendMessage(const QString &type, const QString &message);
    void showAlgoText(QStringList l);

private slots:
    void startAlgo();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Test *m_ui;
    Scene* m_scene;
    Util* m_util;
    void makeUINodeList();

};

#endif // TEST_H
