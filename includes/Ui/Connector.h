#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <QtCore>
#include "Game.h"
#include "Observer.h"

class StartMenuConnector: public QObject{
Q_OBJECT
public slots:
    void startButtonHandler();
public:
    StartMenuConnector()=default;
};

class Connector{
public:
    Connector(Game* game);
};

#endif // CONNECTOR_H
