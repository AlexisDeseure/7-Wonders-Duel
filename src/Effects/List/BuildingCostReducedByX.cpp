#include "BuildingCostReducedByX.h"
#include "Game.h"
#include "Player.h"
#include "City.h"
#include "Card.h"
#include "Building.h"
#include "Ressource.h"

#include <list>

void BuildingCostReducedByX::effect(Game& game) {
    game.getTurnPlayer().getCity().addEachTurnEffects(this);
}

void BuildingCostReducedByX::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    reduction = int_parameters[0];
    type = StringToBuildingType(string_parameters[0]);
}

void BuildingCostReducedByX::eachTurnEffect(Game& game, Card& card){
    // on donne l'argent correspondant aux ressources à l'achat avant celui-ci
    //TODO gérer avec effet économie
    if (dynamic_cast<Building*>(&card) && dynamic_cast<Building*>(&card)->getType()==type){
        City& city = game.getTurnPlayer().getCity();
        RessourceType max = RessourceType::LENGTH;
        std::list<RessourceType> ressources = card.getLackingRessources(&city);
        int money_to_refund = 0;

        for (int i = 0; i<reduction; i++){
            for (auto& type : ressources){
                if (max == RessourceType::LENGTH) max = type;
                else{
                    if (city.getRessource(type).getPrice()>city.getRessource(max).getPrice()){
                        max = type;
                    }
                }
            }
            removeFirstElement(ressources, max);
            money_to_refund += city.getRessource(max).getPrice();
            max = RessourceType::LENGTH;
        }

        city.addMoney(money_to_refund);
    }
}

void BuildingCostReducedByX::print() {
    std::cout << "Réduction du coût de construction de " << reduction << " ressources pour les bâtiments de type " << buildingTypeToString(type) << std::endl;
}