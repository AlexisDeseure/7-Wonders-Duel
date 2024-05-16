#ifndef INSTANCIATOR_H
#define INSTANCIATOR_H

#include "../../Cards/Card.h"
#include "../../DataFetcher/File.h"

class Instanciator
{
private:
    std::vector<Card> LCartesBuildings;
    File json;
    std::vector<std::pair<QString,QString>> LNames = json.getNames();
public:
    Instanciator();
    std::vector<Card> getLBuildings() {return LCartesBuildings;};
    std::vector<std::pair<QString,QString>> getLNames() {return LNames;}
    void addBuilding(Card carte);
    Card instantCard(QString name);
};

#endif // INSTANCIATOR_H
