#include "ChooseWondersUI.h"
using namespace std ;
ChooseWonderStart::ChooseWonderStart(QWidget *parent,std::vector<Wonder*> wonders_vect) : QWidget(parent){
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

    ready = new QPushButton("READY");
    QUIT = new QPushButton("QUIT");
    p1 = new QLabel("Joueur 1, à toi de choisir!");
    p2 = new QLabel("Joueur 2, à toi de choisir!");
    columns->addWidget(p1);
    columns->addWidget(p2);
    columns->addWidget(ready);
    columns->addWidget(QUIT);
     QVBoxLayout* cards = displayCurrentCards(wonders_vect);
    columns->addLayout(cards);

    connect(QUIT, &QPushButton::clicked, this, &QWidget::close);
}

//QHBoxLayout* ChooseWonderStart::displayCurrentCards(std::vector<Wonder*> wond_vect){
    //Layout cartes
    //les wonders durant la selection
    // affichage, les boutons a enlever pas grave
    //debugger le size
    //label tour a tour
    //layout vertical qui prend toute l'ecran
    //Dans le layout vertical separe en deux,
    // partie superieur joueur un joueur 2
    //partie inferieur 4 cartes horizonta
    // signaux, relier a la logique
    // rajouter un bouton
// a chaque fois quatres bouches button, button une carte

    // Créer un layout vertical principal qui prend tout l'écran
QVBoxLayout* ChooseWonderStart::displayCurrentCards(vector<Wonder*> wond_vect) {
        // Créer un layout vertical principal qui prend tout l'écran
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QVBoxLayout* upperLayout = new QVBoxLayout;
        QHBoxLayout* lowerLayout = new QHBoxLayout;

        QLabel* player1Label = new QLabel("Joueur 1");
        QLabel* player2Label = new QLabel("Joueur 2");
        upperLayout->addWidget(player1Label);
        upperLayout->addWidget(player2Label);

        for (Wonder* wonder : wond_vect) {
            QPushButton* imageButton = new QPushButton;
          ///  QPixmap pixmap(wonder->getImage());
            imageButton->setIcon(QIcon(wonder->getImage()));
         //   imageButton->setIconSize(pixmap.size());

            lowerLayout->addWidget(imageButton);

            connect(imageButton, &QPushButton::clicked, this, [this, wonder]() {
                emit selectionDone(wonder);
            });
        }

        mainLayout->addLayout(upperLayout);
        mainLayout->addLayout(lowerLayout);

        return mainLayout;
}

//void ChooseWonderStart::changeChooser(){

//}




