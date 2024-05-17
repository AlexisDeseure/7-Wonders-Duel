#ifndef INSTANCIATOR_H
#define INSTANCIATOR_H

#include "../../Cards/Card.h"
#include "../../DataFetcher/File.h"

class Instanciator
{
private:
    std::vector<Card> cartes_buildings;
    File json;
    std::vector<std::pair<QString,QString>> names;
public:
    Instanciator(): cartes_buildings() {
        names = json.getNames();
    };
    std::vector<Card>& getBuildings() {return cartes_buildings;};
    std::vector<std::pair<QString,QString>> getNames() {return names;}

    void addBuilding(Card carte);
    Card instantCard(QString name);
};

#endif // INSTANCIATOR_H
