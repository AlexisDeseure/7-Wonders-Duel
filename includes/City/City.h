#ifndef CITY_H
#define CITY_H

#define PROGRESS_TOKEN_LENGTH 10
#define WONDER_LENGTH 4

#include <iostream>

class Building;
class Wonder;
class ProgressToken;
class Ressource;
class ScientificSymbol;
class Card;
enum class RessourceType;
enum class SymboleType;

class City {

    int victory_points;
    int treasury;
    int number_of_shields;
    bool player_turn;

    Wonder** wonder; // 4 wonders
    ProgressToken** progress_tokens; // max of 10
    Ressource** ressources; //5 ressources
    ScientificSymbol** scientific_symbols; //avoir un tableau de 7

public:
    City(int victory = 0, int  treasury = 0, int shields = 0, bool turn = false);
    ~City() {
        delete[] wonder;
        delete[] progress_tokens;
        //A verifier le nombre de ressources pour
        //Creer le destructeur et pouvoir
        //Iterer sur le nombre de ressources

        delete[] scientific_symbols;
        delete[] ressources;
        /*  SI ON DÉCIDE QUE CE N'EST PAS UNE AGREGATION
         *
         *
        // Suppression des merveilles
        for (int i = 0; i < 4; ++i) {
            delete wonders[i];
        }
        delete[] wonders;

        // Suppression des jetons de progrès
        for (int i = 0; i < 10; ++i) {
            delete progress_tokens[i];
        }
        delete[] progress_tokens;
         *
         *
         */
    }
    Ressource& getRessource(RessourceType name) const;
    int getDistinctScientificSymbols() const{ return 0; };
    bool canAfford(int price) const { return treasury >= price; };
    void constructBuilding(Building* building);
    void constructWonder(Wonder* wonder);
    void discardCard(Card* card);
    bool checkScientificVictory();
    void addMoney(int money) { treasury += money; };
    void addVictoryPoints(int points) { victory_points += points; };

};
#endif
