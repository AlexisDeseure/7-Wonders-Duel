#pragma once

#include "Ressource.h"
#include "City.h"
#include<string>
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