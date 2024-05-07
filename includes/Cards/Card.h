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
	Ressource ** ressources; 
	//City* owner; 
	//pas besoin de la class city car city contient deja 
	//la liste des cartes
	int taille_ressources; 
	//cet attribut contient le nombre 
	Card(string n) : name(n), ressources(new Ressource* [taille_ressources]) {};
	~Card() {
		for (int i = 0; i++; i < taille_ressources) {
			delete ressources[i];
		}
		delete[] ressources; 

	 }
public : 
	string getName() const {
		return name;
	};
	Ressource* get_price_ressources() const; 

};


#endif