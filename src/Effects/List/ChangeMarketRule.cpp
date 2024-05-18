#include "ChangeMarketRule.h"
#include "Ressource.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

ChangeMarketRule::ChangeMarketRule() : ressource(RessourceType::LENGTH) {}

void ChangeMarketRule::effect(Game& game) {
    game.getTurnPlayer().getCity().getRessource(ressource).changeMarketRule();
}

void ChangeMarketRule::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    ressource = StringToRessourceType(string_parameters[0]);
}
