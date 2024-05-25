// #include "gamewindow.h"
// #include <QVBoxLayout>
// #include <QHBoxLayout>

// GameWindow::GameWindow(QWidget *parent) :
//     QMainWindow(parent)
// {
//     setupUi();
//     setupConnections();
// }

// GameWindow::~GameWindow()
// {
//     // TODO : code to clean and restart the game
// }

// void GameWindow::setupUi()
// {
//     player1Widget = new PlayerWidget(this);
//     player2Widget = new PlayerWidget(this);

//     QWidget *centralWidget = new QWidget(this);
//     QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

//     mainLayout->addWidget(player1Widget);
//     mainLayout->addWidget(player2Widget);

//     QHBoxLayout *cardsLayout = new QHBoxLayout();
//     for (int i = 0; i < 5; ++i) {
//         CardWidget *cardWidget = new CardWidget(this);
//         cardWidgets.append(cardWidget);
//         cardsLayout->addWidget(cardWidget);
//     }
//     mainLayout->addLayout(cardsLayout);

//     setCentralWidget(centralWidget);
// }

// void GameWindow::setupConnections()
// {
//     for (CardWidget *cardWidget : cardWidgets) {
//         connect(cardWidget, &CardWidget::cardClicked, this, &GameWindow::onCardClicked);
//     }
// }

// void GameWindow::onCardClicked()
// {
//     // TODO : Handle card click events and interact with the game logic
// }


// void GameWindow::setupUi()
// {
//     player1Widget = new PlayerWidget(this);
//     player2Widget = new PlayerWidget(this);

//     QWidget *centralWidget = new QWidget(this);
//     QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

//     mainLayout->addWidget(player1Widget);
//     mainLayout->addWidget(player2Widget);

//     QHBoxLayout *cardsLayout = new QHBoxLayout();
//     for (int i = 0; i < 5; ++i) {
//         CardWidget *cardWidget = new CardWidget(this);
//         cardWidget->setCardInfo(QString("Card %1").arg(i + 1), "Effect Example");
//         cardWidgets.append(cardWidget);
//         cardsLayout->addWidget(cardWidget);
//     }
//     mainLayout->addLayout(cardsLayout);

//     setCentralWidget(centralWidget);

//     // Example: Initialize player resources and points
//     QMap<QString, int> initialResources;
//     initialResources["Wood"] = 3;
//     initialResources["Stone"] = 2;

//     player1Widget->updateResources(initialResources);
//     player1Widget->updateVictoryPoints(5);

//     player2Widget->updateResources(initialResources);
//     player2Widget->updateVictoryPoints(7);
// }


