#ifndef DECKPILE_H
#define DECKPILE_H

#include <vector>
#include <utility>

class Building;
class Wonder;
class ProgressToken;

class DeckPile{
private:

    std::pair<std::vector<Building*>, std::vector<Building*>> buildings;
    std::vector<Wonder*> wonders;
    std::pair<std::vector<ProgressToken*>,std::vector<ProgressToken*>> progress_tokens;
    std::vector<std::vector<Building*>> all_buildings;
    int nb_buildings;

public:
    DeckPile(int nb_buildings, int nb_token, int nb_wonder);

    void addDiscardedBuilding(Building* build);
    std::vector<Wonder*>& getAllWonders() { return wonders; }
//    Wonder* selectNextWonder();
//    Building* selectNextBuilding();
//    ProgressToken* selectNextProgressToken();

    std::vector<Building*>& getDiscardedBuildings() {return buildings.second;};
    std::vector<ProgressToken*>& getOtherProgressTokens() {return progress_tokens.second;};
    std::vector<Building*>& getBuildings() {return buildings.first;};
    std::vector<ProgressToken*>& getProgressTokens() {return progress_tokens.first;};
    std::vector<std::vector<Building*>> getAllBuildings() {return all_buildings;};
    void advanceAge(int age);
};

#endif // DECKPILE_H
