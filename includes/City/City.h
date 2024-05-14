#ifndef CITY_H
#define CITY_H

#define PROGRESS_TOKEN_LENGTH 10
#define WONDER_LENGTH 4

#include <iostream>
#include <vector>
#include <set>

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
    std::vector<std::string> chain_symbols;

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
    void addShields(int shields);
    void addChainSymbol(const std::string& symbol); //permet d'ajouter le nom d'un symbole de chainage à la ville
    bool hasChainSymbol(const std::string& symbol) const; //permet de vérifier si un symbole de chainage est présent dans la ville
};

#endif // CITY_H
