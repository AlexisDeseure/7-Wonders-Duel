#include "selectwidget.h"

selectWidget::selectWidget(QWidget* parent) : QWidget(parent) {
    //Initialisation et affichage
    acheterButton = new QPushButton("Acheter",this);
    defausseButton = new QPushButton("Defausser",this);
    hLayout = new QHBoxLayout(this);
    buttonLayout = new QVBoxLayout(this);
    hLayout->addWidget(new QLabel("Voulez vous acheter la carte ou la défausser pour de l'argent ?",this));
    hLayout->addLayout(buttonLayout);
    buttonLayout->addWidget(acheterButton);
    buttonLayout->addWidget(defausseButton);

    //Connexion
    connect(acheterButton, SIGNAL(clicked()),this,SLOT(acheter()));
    connect(defausseButton, SIGNAL(clicked()),this,SLOT(defausser()));

}


