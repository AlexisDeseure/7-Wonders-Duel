#ifndef CARD_H
#define CARD_H

#include <string>

#include "City/Ressource.h"
#include "City/City.h"
#include "Effects/Effect.h"

using namespace std; 

//void Ressource::add() {
//
//
//}

class Card {
	string name; 
	//City* owner; 
	//pas besoin de la class city car city contient deja 
	//la liste des cartes
	Card(string n, City o) : name(n) {};
};
#endif