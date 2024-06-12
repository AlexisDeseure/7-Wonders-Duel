#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsOpacityEffect>

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
    QLabel *selectLabel;
    QGraphicsOpacityEffect *opacityEffect;
    bool clickable;
    //Card* card;
protected:
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);

private slots:
    void cardClicked();

};

#endif // CARDWIDGET_H
