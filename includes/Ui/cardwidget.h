#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "DeckElement.h"
#include "Card.h"

class CardWidget : public QWidget
{
    Q_OBJECT

public:
    CardWidget(QWidget *parent = nullptr);
    CardWidget(DeckElement* card, QWidget *parent = nullptr);
    bool getClickable() {return clickable;};
    DeckElement* getCard() const{return card;};

// signals:
//     void cardClicked();

private:
    QLabel *nameLabel;
    QLabel *effectLabel;
    QPushButton *selectButton;
    bool clickable;
    DeckElement* card;
};

#endif // CARDWIDGET_H
