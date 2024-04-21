#pragma once
#include"wonder.h"
#include"Ressource.h"
#include"ScientificSymbol.h"
#include"ProgressToken.h"
class city {

	int victory_points; 
	int treasury; 
	int number_of_shields; 
	bool player_turn;
	Wonder** wonder; // 4 wonders
	ProgressToken** PT; // max of 10  
	Ressource** ressources; 
	//int nbressources; 
	ScientificSymbol** scientificsymbol; //avoir un tableau de 7
	city(int victory = 0, int  treasury = 0, int shields = 0, bool turn = false); 
	void constructBuilding(); 
	void constructWonder(); 
	void discardCard(); 
	bool checkMilitaryVictory(); 
	bool checkScientificVictory(); 
	~city() {
		delete wonder;
		delete PT;
		// a verifier le nombre de ressources pour 
		//creer le destructeur et pouvoir 
		// iterer sur le nombre de ressources 
		for (int i = 0; i++; i < 7) {
			delete scientificsymbol[i]; 
			delete scientificsymbol; 
		}
	}

};