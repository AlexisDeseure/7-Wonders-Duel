#include "../../includes/City/City.h"
#include"../../includes/Cards/Wonder.h"
#include"../../includes/Cards/Building.h"
#include"../../includes/Cards/ProgressToken.h"
#include"../../includes/City/Ressource.h"
#include"../../includes/City/ScientificSymbol.h"


City::City(int victory, int treasury, int shields, bool turn)
        : victory_points(victory), treasury(treasury), number_of_shields(shields), player_turn(turn) {}

City::~City() {
    // City détuit les objets pour les quelle elle est responsable de la mémoire
    for (auto& w : wonders) {
        delete w;
    }
    for (auto& p : progress_tokens) {
        delete p;
    }
    for (auto& r : ressources) {
        delete r;
    }
    for (auto& s : scientific_symbols) {
        delete s;
    }
    for (auto& b : buildings) {
        delete b;
    }
}

Ressource& City::getRessource(RessourceType name) const {
    for (auto& ressource : ressources) {
        if (ressource->getType() == name) {
            return *ressource;
        }
    }
    throw std::invalid_argument("Ressource non trouvée.");
}

int City::getDistinctScientificSymbols() const {
    std::set<SymboleType> symbols;
    for (const auto& symbol : scientific_symbols) {
        symbols.insert(symbol->getType());
    }
    return symbols.size();
}

bool City::canAfford(int price) const {
    return treasury >= price;
}

void City::constructBuilding(Building* building) {
    int cost = building->getCost(this);
    if (canAfford(cost)) {
        treasury -= cost;
        buildings.push_back(building);
        std::cout << "Building construit: " << building->getName() << std::endl;
    } else {
        std::cout << "Ressources insuffisantes." << std::endl;
    }
}

void City::constructWonder(Wonder* wonder) {
    int cost = wonder->getCost(this);
    if (canAfford(cost) && !wonder->isBuilt()) {
        treasury -= cost;
        wonder->setBuilt(true);
        wonders.push_back(wonder);
        std::cout << "Wonder consuite: " << wonder->getName() << std::endl;
    } else {
        std::cout << "Conditions non accomples pour constuire la wonder." << std::endl;
    }
}

void City::discardCard(Card* card) {
    int coinsReceived = 2; // Base amount for discarding a card

     // TODO Ajoute des pièces supplémentaires +1  coint par carte jaune (batiment commerical)
    coinsReceived += 0;//calculer coins from commercialBuildings();

    treasury += coinsReceived;
    std::cout << "Card discarded for " << coinsReceived << " coins." << std::endl;
    // Handle card removal or placement into a discard pile if necessary
}

bool City::checkScientificVictory() {
    return getDistinctScientificSymbols() >= 6; // Il y a 6 symboles distinct dans le jeu
}

void City::addMoney(int money) {
    treasury += money;
}

void City::addVictoryPoints(int points) {
    victory_points += points;
}

void City::addShields(int shields) {
    number_of_shields += shields;
}

void City::addChainSymbol(const std::string& symbol) {
    chain_symbols.push_back(symbol);
}

bool City::hasChainSymbol(const std::string& symbol) const {
    for (const auto& s : chain_symbols) {
        if (s == symbol) {
            return true;
        }
    }
    return false;
}

