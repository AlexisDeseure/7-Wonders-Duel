#include "Connector.h"


void StartMenuConnector::startButtonHandler(){
    qDebug() << "START PRESSED";
}

Connector::Connector(Game* game):game(game) {
    game->attach(this);
}

void Connector::update(Subject* subject) {
    // Update UI 
}
