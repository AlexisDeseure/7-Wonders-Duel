#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <QtCore>
#include "Game.h"
#include "Observer.h"
#include "StartMenu.h"

class Connector{
private:
    Game* game;
public:
    Connector();
    void createGame(StartMenu* start);

};

#endif // CONNECTOR_H
