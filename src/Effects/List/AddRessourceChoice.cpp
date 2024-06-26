#include "AddRessourceChoice.h"
#include"Ressource.h"
#include "Game.h"
#include "Player.h"
#include "City.h"

void AddRessourceChoice::effect(Game& game) {
    game.getTurnPlayer().getCity().addRessource(ressources);
}


void AddRessourceChoice::setParameters([[maybe_unused]] std::vector<int> int_parameters, std::vector<std::string> string_parameters) {
    for (const std::string& ressource : string_parameters) {
        ressources.push_back(StringToRessourceType(ressource));
    }
}

void AddRessourceChoice::print() {
    std::cout << "Obtenir ";
    for (const RessourceType& ressource : ressources) {
        if (ressource != ressources[0]) {
            std::cout << " ou ";
        }
        std::cout << ressourceTypeToString(ressource);
    }
}