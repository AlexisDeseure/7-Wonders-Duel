#include "DiscardAdversaryCard.h"
#include "Game.h"
#include "Player.h"
#include "Building.h"
#include "City.h"
#include "Instanciator.h"
#include "DeckPile.h"
#include <vector>
#include <iostream>

void DiscardAdversaryCard::effect(Game& game){
    City& city = game.getOtherPlayer().getCity();
    std::vector<Building *>& buildings = city.getBuildings();
    std::vector<Building *> buildings_to_discard;
    for (Building *building : buildings){
        if (building->getType() == type){
            buildings_to_discard.push_back(building);
        }
    }
    if (!buildings_to_discard.empty()){
        std::cout <<  "Choisir un bâtiment à supprimer de la ville de l'adversaire :" << std::endl;
        for (size_t i = 0; i < buildings_to_discard.size(); i++){
            std::cout << "\t" <<i+1 << " : " << buildings_to_discard[i]->getName() << std::endl;
        }
        int choice = game.getTurnPlayer().getPlayerChoice(buildings_to_discard.size());
        std::cout << "Vous avez choisi " << buildings_to_discard[choice-1]->getName() << std::endl;
        city.removeBuilding(buildings_to_discard[choice-1]);
        for (auto& effect : buildings_to_discard[choice-1]->getEffects()){
            effect->inverseEffect(game);
        }
        game.getDeck().addDiscardedBuilding(buildings_to_discard[choice-1]);
    }
    else{
        std::cout << "Malheureusement, "<<game.getOtherPlayer().getName()<<" ne dispose d'aucun bâtiment de type "<<buildingTypeToString(type)<<std::endl;
    }
}

void DiscardAdversaryCard::setParameters([[maybe_unused]] std::vector<int> int_parameters, std::vector<std::string> string_parameters){
    type = StringToBuildingType(string_parameters[0]);
    if (type != BuildingType::Gray && type != BuildingType::Brown)
        throw std::invalid_argument("DiscardAdversaryCard::setParameters: invalid building type : accepted values are 'Gray' or 'Brown'");
}

void DiscardAdversaryCard::print(){
    std::cout << "Défausser un bâtiment de type " << buildingTypeToString(type) << " de la ville de l'adversaire" << std::endl;
}
