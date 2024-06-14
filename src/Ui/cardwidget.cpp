#include "cardwidget.h"
#include "Card.h"
#include <QVBoxLayout>

/* To DO
- vector to check clickables
- refresh clickables vector at each turn
- initialisation test
- catch the deckElement at player.cpp and marketdeckwidget.cpp
*/

CardWidget::CardWidget(QWidget *parent) : QWidget(parent),  clickable(false)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // nameLabel = new QLabel("Card", this); //QString::fromStdString(getCard()->getName())
    // effectLabel = new QLabel("Effect", this);
    selectButton = new QPushButton(this);
    selectButton->setIcon(QIcon("../../../data/image/cards/academy.jpg"));
    selectButton->setIconSize(QSize(100, 159));

    selectLabel = new QLabel("Sélectionner", this);
    selectLabel->setAlignment(Qt::AlignCenter);
    opacityEffect = new QGraphicsOpacityEffect(this);
    selectLabel->setGraphicsEffect(opacityEffect);
    selectLabel->setVisible(false);

    this->setStyleSheet("background-color: blue; color: white;");

    layout->addWidget(selectButton);
    layout->addWidget(selectLabel);

    connect(selectButton, &QPushButton::clicked, this, &CardWidget::cardClicked);
}

void CardWidget::enterEvent(QEnterEvent *event)
{
    // Afficher le label avec une animation de transparence lorsque le curseur entre
    selectLabel->setVisible(true);
    opacityEffect->setOpacity(0.7); // Définir l'opacité souhaitée
}

void CardWidget::leaveEvent(QEvent *event)
{
    // Cacher le label lorsqu'on quitte le survol
    selectLabel->setVisible(false);
}

void CardWidget::removeCard(){
    this->close();
    delete this;
}

void CardWidget::cardClicked()
{
    if (clickable){
        //afficher un menu
        selectWidget* selectMenu = new selectWidget(this);
        selectMenu->show();
        connect(selectMenu,SIGNAL(selectMenu->acheterPressed()),this,SLOT(removeCard()));
        connect(selectMenu,SIGNAL(selectMenu->defausserPressed()),this,SLOT(removeCard()));
    }
}


// void CardWidget::cardClicked(){
//     if (getClickable()){
//         QMessageBox::information(this, "Card Clicked", "You clicked the Card!");
//     }
// }



