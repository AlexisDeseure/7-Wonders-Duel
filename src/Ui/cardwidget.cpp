#include "cardwidget.h"
#include "Card.h"
#include <QVBoxLayout>

CardWidget::CardWidget(QWidget *parent) : QWidget(parent),  clickable(false)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // nameLabel = new QLabel("Card", this); //QString::fromStdString(getCard()->getName())
    // effectLabel = new QLabel("Effect", this);

    // QPixmap pixmap("../../../data/image/cards/academy.jpg");
    // QIcon ButtonIcon(pixmap);
    // selectButton->setIcon(ButtonIcon);

    selectButton = new QPushButton(this);
    selectButton->setIcon(QIcon("../../../data/image/cards/academy.jpg"));

    selectButton->setIconSize(QSize(100, 159));
    selectLabel = new QLabel("Sélectionner", this);

    selectLabel->setAlignment(Qt::AlignCenter);
    opacityEffect = new QGraphicsOpacityEffect(this);

    selectLabel->setGraphicsEffect(opacityEffect);
    selectLabel->setVisible(false);

    // selectButton->setIconSize(pixmap.rect().size());
    // this->resize(40,40);
    // selectButton->resize(40,40);
    this->setStyleSheet("background-color: blue; color: white;");

    // layout->addWidget(nameLabel);
    // layout->addWidget(effectLabel);
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

void CardWidget::cardClicked()
{
    qDebug() << "Button clicked!";
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



