#ifndef ARCPROPERTIE_H
#define ARCPROPERTIE_H

#include <QtGui/QDialog>
#include "arc.h"

namespace Ui {
    class ArcPropertie;
}

class ArcPropertie : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(ArcPropertie)
public:
    explicit ArcPropertie(Arc *arc, QWidget *parent = 0);
    virtual ~ArcPropertie();
    void updateFields();

private slots:
    void changeArcValues();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::ArcPropertie *m_ui;
    Arc* m_arc;
    void  hideAccordingToType();
};

#endif // ARCPROPERTIE_H
