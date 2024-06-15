#include "WonderCostReducedByX.h"
#include "Game.h"
#include "Player.h"
#include "City.h"
#include "Card.h"
#include "Wonder.h"
#include "Ressource.h"

#include <list>

void WonderCostReducedByX::effect(Game& game) {
    game.getTurnPlayer().getCity().addEachTurnEffects(this);
}

void WonderCostReducedByX::setParameters(std::vector<int> int_parameters, [[maybe_unused]] std::vector<std::string> string_parameters) {
    reduction = int_parameters[0];
}

void WonderCostReducedByX::eachTurnEffect(Game& game, Card& card){
    if (dynamic_cast<Wonder*>(&card)){
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
