#pragma once
#include "city.h"

city::city(int victory, int  treasury, int shields, bool turn = false) : victory_points(victory), treasury(treasury), number_of_shields(shields), player_turn(turn), wonder(new Wonder* [4]), 
PT(new ProgressToken* [10]), ressources(new Ressource* [30]), scientificsymbol(new ScientificSymbol* [7]) {


}