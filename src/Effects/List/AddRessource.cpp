#include "AddRessource.h"
#include "Ressource.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

AddRessource::AddRessource() : ressource(RessourceType::LENGTH), quantity(0) {}

void AddRessource::effect(Game& game) {
    game.getTurnPlayer().getCity().getRessource(ressource) += quantity;
    game.getOtherPlayer().getCity().getRessource(ressource).updatePrice(quantity);// augmenter le prix pour l'adversaire de cette ressouce
}

void AddRessource::setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    quantity = int_parameters[0];
    ressource = StringToRessourceType(string_parameters[0]);
}

void AddRessource::inverseEffect(Game &game) {
    game.getOtherPlayer().getCity().getRessource(ressource) += -quantity;
    game.getTurnPlayer().getCity().getRessource(ressource).updatePrice(-quantity);
}

void AddRessource::print() {
    std::cout << "Obtenir " << quantity << " " << ressourceTypeToString(ressource) << std::endl;
}