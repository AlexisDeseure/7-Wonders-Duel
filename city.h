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
<<<<<<< HEAD
	int tailleressources ; 
	int tailless; 
=======
	//int nbressources; 
>>>>>>> 2342842dcea19896e8e7c6fa55daebf881628bda
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
<<<<<<< HEAD
		//A verifier le nombre de ressources pour 
		//Creer le destructeur et pouvoir 
		//Iterer sur le nombre de ressources 
		for (int i = 0; i++; i < tailless) {
			delete scientificsymbol[i]; 
		}
		delete scientificsymbol;
		for (int i = 0; i++; i < tailleressources) {
			delete ressources[i];
		}
		delete ressources; 
	}

};


=======
		// a verifier le nombre de ressources pour 
		//creer le destructeur et pouvoir 
		// iterer sur le nombre de ressources 
		for (int i = 0; i++; i < 7) {
			delete scientificsymbol[i]; 
			delete scientificsymbol; 
		}
	}

};
>>>>>>> 2342842dcea19896e8e7c6fa55daebf881628bda