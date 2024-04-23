#pragma once
#include "city.h"

city::city(int victory, int  treasury, int shields, bool turn = false) : victory_points(victory), treasury(treasury), number_of_shields(shields), player_turn(turn), wonder(new Wonder* [4]), 
<<<<<<< HEAD
PT(new ProgressToken* [10]), ressources(new Ressource* [30]), scientificsymbol(new ScientificSymbol* [7]),tailless(0),tailleressources(0) {
}











=======
PT(new ProgressToken* [10]), ressources(new Ressource* [30]), scientificsymbol(new ScientificSymbol* [7]) {


}
>>>>>>> 2342842dcea19896e8e7c6fa55daebf881628bda
