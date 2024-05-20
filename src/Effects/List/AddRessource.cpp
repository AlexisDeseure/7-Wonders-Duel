#include "AddRessource.h"
#include "Ressource.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

AddRessource::AddRessource() : ressource(RessourceType::LENGTH), quantity(0) {}

void AddRessource::effect(Game& game) {
    game.getTurnPlayer().getCity().getRessource(ressource) += quantity;
    if (impactOtherPlayerPrice) game.getOtherPlayer().getCity().getRessource(ressource).updatePrice(quantity);// augmenter le prix pour l'adversaire de cette ressouce
}

void AddRessource::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
    ressource = StringToRessourceType(string_parameters[0]);
    impactOtherPlayerPrice = static_cast<bool>(int_parameters[0]);
}
