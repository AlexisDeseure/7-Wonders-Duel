#ifndef CITY_H
#define CITY_H
#include"Wonder.h"
#include"Ressource.h"
#include"ScientificSymbol.h"
#include"ProgressToken.h"

class City {

	int victory_points; 
	int treasury; 
	int number_of_shields; 
	bool player_turn;
    int taille_ressources ;
    int taille_scientific_symbol;

    Wonder** wonder; // 4 wonders
	ProgressToken** progress_token; // max of 10
	Ressource** ressources;
	ScientificSymbol** scientific_symbol; //avoir un tableau de 7

public:
	City(int victory = 0, int  treasury = 0, int shields = 0, bool turn = false); 
	void constructBuilding(); 
	void constructWonder(); 
	void discardCard(); 
	bool checkMilitaryVictory(); 
	bool checkScientificVictory(); 
	~City() {
		delete wonder;
		delete progress_token;
		//A verifier le nombre de ressources pour 
		//Creer le destructeur et pouvoir 
		//Iterer sur le nombre de ressources 
		for (int i = 0; i++; i < taille_scientific_symbol) {
			delete scientific_symbol[i];
		}
		delete scientific_symbol;
		for (int i = 0; i++; i < taille_ressources) {
			delete ressources[i];
		}
		delete ressources; 
	}

};
#endif

