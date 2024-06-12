#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "Card.h"

class CardWidget : public QWidget
{
    Q_OBJECT

public:
    CardWidget(QWidget *parent = nullptr);
    bool getClickable() const {return clickable;};
    //Card* getCard() const{return card;};

// signals:
//     void cardClicked();

private:
    QLabel *nameLabel;
    QLabel *effectLabel;
    QPushButton *selectButton;
    bool clickable;
    //Card* card;
};

#endif // CARDWIDGET_H
