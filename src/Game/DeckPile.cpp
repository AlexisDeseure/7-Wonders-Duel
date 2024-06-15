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


//Wonder* DeckPile::selectNextWonder(){
//    Wonder* W = wonders.back();
//    wonders.pop_back();
//    return W;
//}
//
//
//Building* DeckPile::selectNextBuilding(){
//    Building* B = buildings.first.back();
//    buildings.first.pop_back();
//    return B;
//}
//
//ProgressToken* DeckPile::selectNextProgressToken(){
//    ProgressToken* PT = progress_tokens.first.back();
//    progress_tokens.first.pop_back();
//    return PT;
//}


void DeckPile::advanceAge(int age){
    //first -> les buildings de l'age
    buildings.first = all_buildings[age-1];
}

void DeckPile::addDiscardedBuilding(Building* build){
    buildings.second.push_back(build);
}



// #include "DeckPile.h"
// #include "Instanciator.h"

// DeckPile::DeckPile(int nb_buildings, int nb_token, int nb_wonder) : nb_buildings(nb_buildings){
//     wonders = Instanciator::getInstanciator()->extractXRandomWondersFrom(Instanciator::getInstanciator()->getWonders(), nb_wonder);
//     progress_tokens = Instanciator::getInstanciator()->extractXRandomProgressTokensFrom(Instanciator::getInstanciator()->getPTInstanciator(), nb_token);
// }


// //Wonder* DeckPile::selectNextWonder(){
// //    Wonder* W = wonders.back();
// //    wonders.pop_back();
// //    return W;
// //}
// //
// //
// //Building* DeckPile::selectNextBuilding(){
// //    Building* B = buildings.first.back();
// //    buildings.first.pop_back();
// //    return B;
// //}
// //
// //ProgressToken* DeckPile::selectNextProgressToken(){
// //    ProgressToken* PT = progress_tokens.first.back();
// //    progress_tokens.first.pop_back();
// //    return PT;
// //}


// void DeckPile::advanceAge(int age){
//     //first -> les buildings de láge

//     buildings.first = Instanciator::getInstanciator()->extractXRandomBuildingsFrom(Instanciator::getInstanciator()->getCardFromXAge(age), nb_buildings).first;
// }

// void DeckPile::addDiscardedBuilding(Building* build){
//     buildings.second.push_back(build);
// }
