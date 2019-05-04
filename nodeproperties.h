#ifndef NODEPROPERTIES_H
#define NODEPROPERTIES_H

#include <QtGui/QDialog>

namespace Ui {
    class NodeProperties;
}

class NodeProperties : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(NodeProperties)
public:
    explicit NodeProperties(QWidget *parent = 0);
    virtual ~NodeProperties();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::NodeProperties *m_ui;
};

#endif // NODEPROPERTIES_H
