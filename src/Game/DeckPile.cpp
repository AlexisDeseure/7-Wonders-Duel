#include "DeckPile.h"
#include "Instanciator.h"
#include "GameParameters.h"

DeckPile::DeckPile(int nb_buildings, int nb_token, int nb_wonder) : nb_buildings(nb_buildings){
    wonders = Instanciator::getInstanciator()->extractXRandomWondersFrom(Instanciator::getInstanciator()->getWonders(), nb_wonder);
    progress_tokens = Instanciator::getInstanciator()->extractXRandomProgressTokensFrom(Instanciator::getInstanciator()->getPTInstanciator(), nb_token);
    for(int i=1; i<= Instanciator::getInstanciator()->getGameParameters().getNumberAge(); i++){
        all_buildings.push_back(Instanciator::getInstanciator()->extractXRandomBuildingsFrom(Instanciator::getInstanciator()->getCardFromXAge(i), nb_buildings).first);
    }
}




void DeckPile::advanceAge(int age){
    //first -> les buildings de l'age
    buildings.first = all_buildings[age-1];
}

void DeckPile::addDiscardedBuilding(Building* build){
    buildings.second.push_back(build);
}
