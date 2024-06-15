#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QtCore>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class selectWidget : public QWidget{
    Q_OBJECT
public:
    selectWidget(QWidget* parent = nullptr);
    bool achetestatus() const{return achete;};
private:
    //Layout
    QVBoxLayout* vLayout;
    QHBoxLayout* buttonLayout;

    //boutons
    QPushButton* acheterButton;
    QPushButton* defausseButton;

    //bools
    bool achete;
    bool defausse;

public slots:
    void acheter();
    void defausser() ;

signals:
    void acheterPressed();
    void defausserPressed();
};

#endif // SELECTWIDGET_H
