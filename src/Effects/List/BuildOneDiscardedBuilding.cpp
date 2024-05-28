#include "BuildOneDiscardedBuilding.h"
#include "Game.h"
#include "Player.h"
#include "DeckPile.h"
#include "City.h"
#include "Building.h"
#include <iostream>
#include <vector>

void BuildOneDiscardedBuilding::effect(Game& game) {
    Player& player = game.getTurnPlayer();
    std::cout << "Choisissez un bâtiment parmi les bâtiments défaussés (défaut = 1) : " << std::endl;
    int index = 1;
    std::vector<Building*>& discardedBuildings = game.getDeck().getDiscardedBuildings();
    for (auto& card : discardedBuildings) {
        std::cout << index << " : " << card->getName() << std::endl;
        index++;
    }
    int choice = getIntInput();
    if (choice < 1 || static_cast<size_t>(choice) > game.getDeck().getDiscardedBuildings().size()){
        std::cout << "Choix invalide, choix par défaut" << std::endl;
        choice = 1;
    }
    Building* selected = discardedBuildings[choice-1];
    discardedBuildings.erase(discardedBuildings.begin() + choice-1);
    game.getTurnPlayer().getCity().addCard(*selected);
    selected->applyEffects(game);
}
