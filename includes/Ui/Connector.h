#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <QtCore>

class StartMenuConnector: public QObject{
Q_OBJECT
public slots:
    void startButtonHandler();
public:
    StartMenuConnector()=default;
};

#endif // CONNECTOR_H
