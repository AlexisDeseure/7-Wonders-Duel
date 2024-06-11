#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <QtCore>
#include "GameUI.h"
#include "StartMenu.h"

class Connector{
Q_OBJECT
private:
    GameUI* game;
public:
    Connector();
    void createGame(StartMenu* start);
signals:
    void wondersReady();
};

#endif // CONNECTOR_H
