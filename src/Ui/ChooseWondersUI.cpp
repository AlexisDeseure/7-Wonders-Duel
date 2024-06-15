#include "ChooseWondersUI.h"
#include "Game.h"
#include "Player.h"

using namespace std ;

ChooseWonderStart::ChooseWonderStart(QWidget *parent,std::vector<Wonder*> wonders_vect, Game* g) : QWidget(parent), game(g){
    //phase de selection de wonders
    // comment les wonders sont reparties
// pour donner des nouveaux vecteurs
    //on donne des signaux
    //on peut utiliser des slots et des signaux
    //definir setwonders
//a travers les signaux mettre a jour l'attribut wonders

//boucle d'evenement
//Ce contructeur
    QSize size = parent->size();
    QRect ALL_size = QRect({0,0},size);
    qDebug() << ALL_size;

    this->setFixedSize(size);
    columns = new QVBoxLayout(this);
    columns->setGeometry(ALL_size);

    QVBoxLayout* cards = displayCurrentCards(wonders_vect);
    columns->addLayout(cards);

}



    // Créer un layout vertical principal qui prend tout l'écran
QVBoxLayout* ChooseWonderStart::displayCurrentCards(vector<Wonder*> wond_vect) {
        // Créer un layout vertical principal qui prend tout l'écran
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QGridLayout* gridLayout = new QGridLayout;
        currentPlayerLabel = new QLabel("");
        currentPlayerLabel->setStyleSheet("QLabel { font-size: 30px; font-weight: bold;}");
        mainLayout->addWidget(currentPlayerLabel);
        mainLayout->addLayout(gridLayout);
        currentPlayerLabel->setAlignment(Qt::AlignCenter);
        // QVBoxLayout* mainLayout = new QVBoxLayout;
        // QVBoxLayout* upperLayout = new QVBoxLayout;
        // QHBoxLayout* lowerLayout = new QHBoxLayout;
        int row = 1; // Ligne courante pour les boutons d'image
        int col = 0;
        // int* count = new int(0);
        for (Wonder* wonder : wond_vect) {
            QPushButton* imageButton = new QPushButton(this);
            imageButton->setIcon(QIcon(wonder->getImage()));
            imageButton->setIconSize(QSize(330, 500));
            imageButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            gridLayout->addWidget(imageButton, row, col);
            dictionary[wonder] = imageButton;
            connect(imageButton, &QPushButton::clicked, this, [this, wonder, imageButton]() {
                emit selectionDone(wonder);
                delete imageButton;
                // (*count)++;
                // qDebug() <<"count: "<< *count;
                // if (*count >=4){
                //     emit exitBoucleSelection();
                // }
            });



            // Alterner entre les colonnes 0 et 1
            col = (col + 1) % 2;

            // Passer à la ligne suivante si nécessaire
            if (col == 0) {
                row++;
            }
        }

        connect(&game->getTurnPlayer(), SIGNAL(destroyWondersAi(Wonder*)), this, SLOT(handleAiChoice(Wonder*)));
        connect(&game->getOtherPlayer(), SIGNAL(destroyWondersAi(Wonder*)), this, SLOT(handleAiChoice(Wonder*)));

        // delete count;
        // mainLayout->addLayout(upperLayout);
        // mainLayout->addLayout(lowerLayout);

        return mainLayout;
}


void ChooseWonderStart::handleAiChoice(Wonder* wonder){
    delete dictionary[wonder];
}
//void ChooseWonderStart::changeChooser(){

//}




