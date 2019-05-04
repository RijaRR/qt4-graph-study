#ifndef GRAPHPROPERTIES_H
#define GRAPHPROPERTIES_H

#include <QtGui/QDialog>
#include "scene.h"
#include "util.h"

namespace Ui {
    class GraphProperties;
}

class GraphProperties : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(GraphProperties)
public:
    explicit GraphProperties(Scene* scene, QWidget *parent = 0);
    virtual ~GraphProperties();

private slots:
    void refresh();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Scene* myScene;
    Util* myUtil;

    void computeAndDisplayProperties();
    Ui::GraphProperties *m_ui;
};

#endif // GRAPHPROPERTIES_H
