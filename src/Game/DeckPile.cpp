#include "DeckPile.h"
#include "Instanciator.h"

DeckPile::DeckPile(int nb_buildings, int nb_token, int nb_wonder){
    wonders = Instanciator::getInstanciator()->extractXRandomWondersFrom(Instanciator::getInstanciator()->getWonders(), nb_wonder);
    buildings.first = Instanciator::getInstanciator()->extractXRandomBuildingsFrom(Instanciator::getInstanciator()->getBuildings(), nb_buildings).first;
    progress_tokens = Instanciator::getInstanciator()->extractXRandomProgressTokensFrom(Instanciator::getInstanciator()->getPTInstanciator(), nb_buildings);
}


Wonder* DeckPile::selectNextWonder(){
    Wonder* W = wonders.back();
    wonders.pop_back();
    return W;
}

Building* DeckPile::selectNextBuilding(){
    Building* B = buildings.first.back();
    buildings.first.pop_back();
    return B;
}

ProgressToken* DeckPile::selectNextProgressToken(){
    ProgressToken* PT = progress_tokens.first.back();
    progress_tokens.first.pop_back();
    return PT;
}
