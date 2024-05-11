#ifndef CITY_H
#define CITY_H

// peut-on gerer les includes comme ça Alexis ?
#include <iostream>
#include <vector>
#include "../../includes/Cards/Wonder.h"
#include "../../includes/Cards/Building.h"
#include "../../includes/Cards/ProgressToken.h"
#include "../../includes/City/Ressource.h"
#include "../../includes/City/ScientificSymbol.h"
#include "../../includes/Cards/Card.h"

enum class RessourceType;
enum class SymboleType;

class City {
private:
    int victory_points;
    int treasury;
    int number_of_shields;
    bool player_turn;

    std::vector<Wonder*> wonders;
    std::vector<ProgressToken*> progress_tokens;
    std::vector<Ressource*> ressources;
    std::vector<ScientificSymbol*> scientific_symbols;
    std::vector<Building*> buildings;

public:
    City(int victory = 0, int treasury = 0, int shields = 0, bool turn = false);
    ~City();
    Ressource& getRessource(RessourceType name) const;
    int getDistinctScientificSymbols() const;
    bool canAfford(int price) const;
    void constructBuilding(Building* building);
    void constructWonder(Wonder* wonder);
    void discardCard(Card* card);
    bool checkScientificVictory();
    void addMoney(int money);
    void addVictoryPoints(int points);
};

#endif // CITY_H
