// #include "cardwidget.h"
// #include <QVBoxLayout>

// CardWidget::CardWidget(QWidget *parent) :
//     QWidget(parent)
// {
//     QVBoxLayout *layout = new QVBoxLayout(this);

//     nameLabel = new QLabel("Card Name", this);
//     effectLabel = new QLabel("Effect", this);
//     selectButton = new QPushButton("Select", this);

//     layout->addWidget(nameLabel);
//     layout->addWidget(effectLabel);
//     layout->addWidget(selectButton);

//     connect(selectButton, &QPushButton::clicked, this, &CardWidget::cardClicked);
// }

// void CardWidget::setCardInfo(const QString &name, const QString &effect)
// {
//     nameLabel->setText(name);
//     effectLabel->setText(effect);
// }

// QString CardWidget::getCardName() const
// {
//     return nameLabel->text();
// }
