#ifndef WELCOME_H
#define WELCOME_H

#include <QtGui/QDialog>



namespace Ui {
    class Welcome;
}


class Welcome : public QDialog{
    Q_OBJECT
    Q_DISABLE_COPY(Welcome)
public:
    explicit Welcome(QWidget *parent = 0);
    virtual ~Welcome();
    QString graphType();
    int graphTypeInt();

protected:
    virtual void changeEvent(QEvent *e);

signals:
    void typeSet();

private slots:
    void setGraphType();

private:
    Ui::Welcome *m_ui;
    QString myGraphType;
};

#endif // WELCOME_H
