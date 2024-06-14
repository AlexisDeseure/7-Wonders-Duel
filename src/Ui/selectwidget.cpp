#include "selectwidget.h"

selectWidget::selectWidget(QWidget* parent) : QWidget(parent) {
    //Initialisation et affichage
    acheterButton = new QPushButton("Acheter",this);
    defausseButton = new QPushButton("Defausser",this);
    vLayout = new QVBoxLayout(this);
    buttonLayout = new QHBoxLayout(this);
    vLayout->addWidget(new QLabel("Voulez vous acheter la carte ou la défausser pour de l'argent ?",this));
    vLayout->addLayout(buttonLayout);
    buttonLayout->addWidget(acheterButton);
    buttonLayout->addWidget(defausseButton);

    //Connexion
    connect(acheterButton, SIGNAL(clicked()),this,SLOT(acheter()));
    connect(defausseButton, SIGNAL(clicked()),this,SLOT(defausser()));
}

//SLOTS : réception du clic et envoi des signaux
void selectWidget::acheter(){
    emit acheterPressed();
    this->close();
    delete this;
}

void selectWidget::defausser() {
    emit defausserPressed();
    this->close();
    delete this;
}
