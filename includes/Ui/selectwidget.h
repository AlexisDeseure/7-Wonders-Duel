#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class selectWidget : public QWidget{
public:
    selectWidget(QWidget* parent = nullptr);
    bool achetestatus() const{return achete;};


private:
    //Layout
    QHBoxLayout* hLayout;
    QVBoxLayout* buttonLayout;

    //boutons
    QPushButton* acheterButton;
    QPushButton* defausseButton;

    //bools
    bool achete;
    bool defausse;

public slots:
    void acheter() {
        emit acheterPressed();
    };
    void defausser() {
        emit defausserPressed();
    };

signals:
    void acheterPressed();
    void defausserPressed();
};

#endif // SELECTWIDGET_H
