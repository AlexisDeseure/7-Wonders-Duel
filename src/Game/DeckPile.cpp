#include "DeckPile.h"
#include "Instanciator.h"

DeckPile::DeckPile(int nb_buildings, int nb_token, int nb_wonder){
    wonders = Instanciator::getInstanciator()->extractXRandomWondersFrom(Instanciator::getInstanciator()->getWonders(), nb_wonder);
    buildings.first = Instanciator::getInstanciator()->extractXRandomBuildingsFrom(Instanciator::getInstanciator()->getBuildings(), nb_buildings);
    progress_tokens = Instanciator::getInstanciator()->extractXRandomBuildingsFrom(Instanciator::getInstanciator()->getBuildings(), nb_buildings);
}


