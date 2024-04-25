#pragma once
#include"Wonder.h"
#include"Ressource.h"
#include"Scientificsymbol.h"
#include"ProgressToken.h"

class City {
    Private:
	int victory_points;
	int treasury; 
	int number_of_shields; 
	bool player_turn;
	Wonder** wonder; // 4 wonders
	ProgressToken** progress_token; // max of 10
	Ressource** ressources;
	int taille_ressources ;
	int taille_scientific_symbol;
	ScientificSymbol** scientific_symbol; //avoir un tableau de 7

    Public:
    //Contructeur
	City(int victory = 0, int  treasury = 0, int shields = 0, bool turn = false);
    //Destructeur
    ~City() {
        delete[] wonders; //delete wonder;
        delete[] progress_tokens; //delete progress_token;

        //A verifier le nombre de ressources pour
        //Creer le destructeur et pouvoir
        //Iterer sur le nombre de ressources

        // Suppression des symboles scientifiques
        for (int i = 0; i < taille_scientific_symbols; ++i) {
            delete scientific_symbols[i];
        }
        delete[] scientific_symbols;
        // Suppression des ressources
        for (int i = 0; i < taille_ressources; ++i) {
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

    // Méthodes de la classe
	void constructBuilding(); 
	void constructWonder(); 
	void discardCard(); 
	bool checkMilitaryVictory(); 
	bool checkScientificVictory();
};


