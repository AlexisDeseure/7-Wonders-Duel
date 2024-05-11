#ifndef CITY_H
#define CITY_H

#define PROGRESS_TOKEN_LENGTH 10
#define WONDER_LENGTH 4

#include <iostream>
#include <vector>

class Building;
class Wonder;
class ProgressToken;
class Ressource;
class ScientificSymbol;
class Card;
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
