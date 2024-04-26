#ifndef CITY_H
#define CITY_H
#include <iostream>
#include"includes/Cards/Wonder.h"
#include"Ressource.h"
#include"ScientificSymbol.h"
#include"includes/Cards/ProgressToken.h"

class City {

	int victory_points; 
	int treasury; 
	int number_of_shields; 
	bool player_turn;
    int taille_ressources ;
    int taille_scientific_symbols;

    Wonder** wonder; // 4 wonders
	ProgressToken** progress_tokens; // max of 10
	Ressource** ressources;
	ScientificSymbol** scientific_symbols; //avoir un tableau de 7

    public:
        City(int victory = 0, int  treasury = 0, int shields = 0, bool turn = false);

        ~City() {
            delete[] wonder;
            delete[] progress_tokens;
            //A verifier le nombre de ressources pour
            //Creer le destructeur et pouvoir
            //Iterer sur le nombre de ressources
            for (int i = 0; i++; i < taille_scientific_symbols) {
                delete scientific_symbols[i];
            }
            delete scientific_symbols;
            for (int i = 0; i++; i < taille_ressources) {
                delete ressources[i];
            }
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

        void constructBuilding(Building* building)
        void constructWonder(Wonder* wonder)
        void discardCard(Card* card);
        bool checkMilitaryVictory();
        bool checkScientificVictory();

};
#endif

