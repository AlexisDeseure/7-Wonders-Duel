#ifndef CARDWIDGET_H
#define CARDWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include "DeckElement.h"
#include "Card.h"
#include "DeckElement.h"
#include "Card.h"
#include "selectwidget.h"

class CardWidget : public QWidget
{
    Q_OBJECT
public:
    CardWidget(QWidget *parent = nullptr);
    CardWidget(DeckElement* card, QWidget *parent = nullptr);
    bool getClickable() {return clickable;};
    DeckElement* getCard() const{return card;};

// signals:
// void cardClicked();

private:
    QLabel *nameLabel;
    QLabel *effectLabel;
    QPushButton *selectButton;
    QLabel *selectLabel;
    QGraphicsOpacityEffect *opacityEffect;
    bool clickable;
    DeckElement* card;
protected:
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);

public slots:
    void cardClicked();
    void removeCard();
};

#endif // CARDWIDGET_H
