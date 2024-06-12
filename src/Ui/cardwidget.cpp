#include "cardwidget.h"
#include "Card.h"
#include <QVBoxLayout>

CardWidget::CardWidget(QWidget *parent) : QWidget(parent),  clickable(false)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    nameLabel = new QLabel("Card", this); //QString::fromStdString(getCard()->getName())
    effectLabel = new QLabel("Effect", this);
    selectButton = new QPushButton("Select", this);
    this->resize(40,40);
    selectButton->resize(40,40);
    this->setStyleSheet("background-color: blue; color: white;");

    layout->addWidget(nameLabel);
    layout->addWidget(effectLabel);
    layout->addWidget(selectButton);

    //connect(selectButton, &QPushButton::clicked, this, &CardWidget::cardClicked);
}

CardWidget::CardWidget(DeckElement* card, QWidget *parent) : QWidget(parent), card(card), clickable(false)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    nameLabel = new QLabel(QString::fromStdString(card->getBuilding()->getName()), this);
    //effectLabel = new QLabel(QString::fromStdString(card->getBuilding()->getEffects().pop_back()).print(sorti), this);
    selectButton = new QPushButton("Select", this);
    this->resize(40,40);
    selectButton->resize(40,40);
    this->setStyleSheet("background-color: blue; color: white;");

    layout->addWidget(nameLabel);
    layout->addWidget(effectLabel);
    layout->addWidget(selectButton);

    //connect(selectButton, &QPushButton::clicked, this, &CardWidget::cardClicked);
}
// void CardWidget::cardClicked(){
//     if (getClickable()){
//         QMessageBox::information(this, "Card Clicked", "You clicked the Card!");
//     }
// }



