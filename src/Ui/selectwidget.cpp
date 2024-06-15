#include "selectwidget.h"

selectWidget::selectWidget(QWidget* parent) : QWidget(parent) {
    //Initialisation et affichage
    acheterButton = new QPushButton("Acheter",this);
    defausseButton = new QPushButton("Defausser",this);
    wonderButton = new QPushButton("Acheter wonder",this);;
    vLayout = new QVBoxLayout(this);
    buttonLayout = new QHBoxLayout(this);
    vLayout->addWidget(new QLabel("Voulez vous acheter la carte, la défausser pour de l'argent ou la défausser en achetant une wonder ?",this));
    vLayout->addLayout(buttonLayout);
    buttonLayout->addWidget(acheterButton);
    buttonLayout->addWidget(defausseButton);
    buttonLayout->addWidget(wonderButton);

    //Connexion
    connect(acheterButton, SIGNAL(clicked()),this,SLOT(acheter()));
    connect(defausseButton, SIGNAL(clicked()),this,SLOT(defausser()));
    connect(wonderButton, SIGNAL(clicked()),this,SLOT(wonderer()));
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

void selectWidget::wonderer() {
    emit wonderPressed();
    this->close();
    delete this;
}
