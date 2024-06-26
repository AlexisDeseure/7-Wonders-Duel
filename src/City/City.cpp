#include"City.h"
#include"Wonder.h"
#include"Building.h"
#include"ProgressToken.h"
#include"Ressource.h"
#include"ScientificSymbol.h"
#include"Game.h"
#include"Effect.h"
#include"Card.h"
#include"Board.h"
#include"Instanciator.h"
#include"GameParameters.h"
#include"DeckPile.h"
#include <set>
#include <iostream>

City::City(int treasury)
        : victory_points(0), treasury(treasury), number_of_shields(0){
    // Parcourt de la liste des ressources de bases pour instancier correctement les ressources de la ville
    for (int i = 0; i < static_cast<int>(RessourceType::LENGTH); i++) {
        ressources.push_back(new Ressource({static_cast<RessourceType>(i)}));
    }
    for (int i = 0; i < static_cast<int>(SymboleType::LENGTH); i++) {
        scientific_symbols.push_back(new ScientificSymbol(static_cast<SymboleType>(i)));
    }
}

City::~City() {
    // City détuit les objets pour les quelle elle est responsable de la mémoire
    for (auto& w : wonders) {
        delete w;
    }
    for (auto& p : progress_tokens) {
        delete p;
    }
    for (auto& r : ressources){
            delete r;
    }
    for (auto& s : scientific_symbols) {
        delete s;
    }
    for (auto& b : buildings) {
        delete b;
    }
}

int City::getTreasury() const{
    return treasury;
}

int City::getNumberOfBuildingType(BuildingType type) const{
    int number = 0;
    for (auto& building : buildings){
        if (building->getType() == type) number++;
    }
    return number;
}

Ressource& City::getRessource(RessourceType name) {
    for (auto& ressource : ressources) {
        if (ressource->getTradable() and ressource->getType() == name) {
            return *ressource;
        }
    }
    throw std::invalid_argument("Ressource non trouvée.");
}

ScientificSymbol& City::getScientificSymbol(SymboleType name){
    for (auto& symbol : scientific_symbols) {
        if (symbol->getType() == name) {
            return *symbol;
        }
    }
    throw std::invalid_argument("Symbole Scientifique non trouvé.");
}

std::vector<Ressource*>& City::getRessources() {
    return ressources;
}

std::vector<ScientificSymbol*>& City::getScientificSymbols(){
    return scientific_symbols;
}

std::vector<Building*>& City::getBuildings(){
    return buildings;
}

void City::updateRemainingRessources(std::list<RessourceType>& remaining_ressources) {
    // Chercher si pour chaque ressource à choix possédée, les ressources interchangeable sont dans la liste des
    // ressources manquantes. Si c'est le cas, on supprime de remaining_ressources la ressource interchangeable qui
    // a le prix le plus élevé. Le programme s'arrete quand remaining_ressources est vide

    RessourceType type_intermediaire_prix_haut = RessourceType::LENGTH;

    for (auto& ressource : ressources) {
        if (remaining_ressources.empty()) {
            return;
        }
        if (!ressource->getTradable()) {
            for(auto& type : ressource->getTypes()){
                //pour chaque type du choix, on cherche si on manque de ressource de type type
                if (std::find(remaining_ressources.begin(), remaining_ressources.end(), type) != remaining_ressources.end()) {
                    if (type_intermediaire_prix_haut == RessourceType::LENGTH) {
                        type_intermediaire_prix_haut = type;
                    } else {
                        if (getRessource(type).getPrice() > getRessource(type_intermediaire_prix_haut).getPrice()) {
                            // on garde le type de ressource qui a le prix le plus élevé pour que le joueur paye le
                            // moins possible
                            type_intermediaire_prix_haut = type;
                        }
                    }
                }
            }
            if (type_intermediaire_prix_haut != RessourceType::LENGTH) {
                removeFirstElement(remaining_ressources,type_intermediaire_prix_haut);
                type_intermediaire_prix_haut = RessourceType::LENGTH;
            }
        }
    }

}

int City::getDistinctScientificSymbols() const {
    int number_distinct = 0;
    for (auto& symbol : scientific_symbols) {
        if (symbol->getCount() > 0) {
            number_distinct++;
        }
    }
    return number_distinct;
}

bool City::canAfford(int price) const {
    return treasury >= price;
}

bool City::constructBuilding(Building* building, Game& game) {
    int cost = static_cast<int>(building->getCost(this));
    if (canAfford(cost)) {
        treasury -= cost;
        buildings.push_back(building);
        building->applyEffects(game);
        std::cout << "Building construit: " << building->getName() << std::endl;
        return true;
    } else {
        std::cout << "Ressources insuffisantes." << std::endl;
        return false;
    }
}

bool City::constructWonder(Wonder* wonder, Game& game) {
    int cost = static_cast<int>(wonder->getCost(this));
    if (game.getBoard().canConstructWonder() && canAfford(cost) && !wonder->isBuilt()) {
        treasury -= cost;
        wonder->setBuilt(true);
        wonder->applyEffects(game);
        game.getBoard().constructWonder();
        std::cout << "Wonder construite: " << wonder->getName() << std::endl;
        return true;
    } else {
        std::cout << "Conditions non accomplies pour construire la wonder." << std::endl;
        return false;
    }
}

void City::discardBuilding(Building* building, Game& game) {
    int coinsReceived = Instanciator::getInstanciator()->getGameParameters().getBaseMarketCoins(); // Base amount for discarding a card

     //  Ajoute des pièces supplémentaires +1  coint par carte jaune (batiment commerical)
    coinsReceived += getNumberOfBuildingType(BuildingType::Yellow);

    treasury += coinsReceived;
    std::cout << "Bâtiment jetée pour " << coinsReceived << " pièces." << std::endl;

    // placer la carte dans la défausse
    game.getDeck().addDiscardedBuilding(building);
}

void City::addProgressToken(ProgressToken *PT, Game& game) {
    progress_tokens.push_back(PT);
    PT->applyEffects(game);
}

void City::addScientificSymbol(SymboleType type, int quantity, Game& game) {
    ScientificSymbol& symbol = getScientificSymbol(type);
    if (symbol.getCount()%2 == 1){
        addProgressToken(game.getBoard().getProgressToken(game, game.getTurnPlayer()), game);
    }
    symbol += quantity;
}

bool City::checkScientificVictory() {
    return getDistinctScientificSymbols() >= Instanciator::getInstanciator()->getGameParameters().getNumberScientificSymbolToWin(); // Il y a 6 symboles distinct dans le jeu
}

void City::addMoney(int money) {
    treasury += money;
    treasury = std::max(treasury, 0);
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

void City::addRessource(std::vector<RessourceType> types) {
    Ressource* r = new Ressource(std::move(types));
    ressources.push_back(r);
    //ressources.emplace_back(types);
}

bool City::hasChainSymbol(const std::string& symbol) const {
    for (const auto& s : chain_symbols) {
        if (s == symbol) {
            return true;
        }
    }
    return false;
}

void City::addEachTurnEffects(Effect* effect){
    eachTurnEffects.push_back(effect);
}

void City::addEndGameEffects(Effect* effect){
    endGameEffects.push_back(effect);
}

std::vector<Wonder*>& City::getWonders(){
    return wonders;
}

std::vector<ProgressToken*>& City::getProgressTokens(){
    return progress_tokens;
}

void City::applyEndEffects(Game& game){
    for (auto& effect : endGameEffects) {
        effect->endEffect(game);
    }
}

void City::applyEachTurnEffects(Game& game, Card& card){
    for (auto& effect : eachTurnEffects) {
        effect->eachTurnEffect(game, card);
    }
}

void City::addCard(Card& card){
    if (dynamic_cast<Wonder*>(&card)){
        wonders.push_back(dynamic_cast<Wonder*>(&card));
    }
    else if (dynamic_cast<Building*>(&card)){
        buildings.push_back(dynamic_cast<Building*>(&card));
    }
    else if (dynamic_cast<ProgressToken*>(&card)){
        progress_tokens.push_back(dynamic_cast<ProgressToken*>(&card));
    }
}

void City::addWonder(Wonder* wonder) {
    wonders.push_back(wonder);
}

void City::removeBuilding(Building* building) {
    buildings.erase(std::remove(buildings.begin(), buildings.end(), building), buildings.end());
}



