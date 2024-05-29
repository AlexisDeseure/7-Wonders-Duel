#include "ChangeMarketRule.h"
#include "Ressource.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

ChangeMarketRule::ChangeMarketRule() : ressource(RessourceType::LENGTH) {}

void ChangeMarketRule::effect(Game& game) {
    game.getTurnPlayer().getCity().getRessource(ressource).changeMarketRule();
}

void ChangeMarketRule::setParameters([[maybe_unused]] std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    ressource = StringToRessourceType(string_parameters[0]);
}

void ChangeMarketRule::print() {
    std::cout << "Changer la règle du marché de la ressource " << ressourceTypeToString(ressource)<<" (prix fixé à 1 pièce)" << std::endl;
}
