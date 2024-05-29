#include "MoveConflictPawnMorePerNew.h"
#include "Game.h"
#include "Player.h"
#include "City.h"
#include "Card.h"
#include "Building.h"
#include "Wonder.h"
#include "Ressource.h"

#include <list>

void MoveConflictPawnMorePerNew::effect(Game& game) {
    game.getTurnPlayer().getCity().addEachTurnEffects(this);
}

void MoveConflictPawnMorePerNew::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    shields = int_parameters[0];
    type = StringToBuildingType(string_parameters[0]);
}

void MoveConflictPawnMorePerNew::eachTurnEffect(Game& game, Card& card){
    if (!dynamic_cast<Wonder*>(&card) && dynamic_cast<Building*>(&card)->getType()==type){
        City& city = game.getTurnPlayer().getCity();
        city.addShields(shields);
    }
}

void MoveConflictPawnMorePerNew::print() {
    std::cout << "Gagner " << shields << " boucliers par carte de type " << buildingTypeToString(type) << " construite" << std::endl;
}
