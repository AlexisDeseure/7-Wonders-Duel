#ifndef PROJET_SCIENTIFICSYMBOL_H
#define PROJET_SCIENTIFICSYMBOL_H
#include "includes/City/City.h"

/*Un symbole n'a qu'un seul type, il faudra faire gaffe à la composition de la classe ScientificSymbol
avec City, bien faire une liste et que la fonction de rajout vérifie correctement qu'il n'y a pas déjà le type
*/
enum class SciSymbols {gyro, scale, sundial, pestle, triangle, wheel, quill}; //jsp ce que représente le triangle lol

class ScientificSymbol{
private:
    int count; //Nombre de symboles d'un seul type
    SciSymbols symbol_type;
    const City::City* city;


public:
    void add(){ //Add ne se déclenche que lorsque l'on truove un symbole scientifique identique dans la même ville
        count++; //Incrémentation du nombre de symboles
    }
};

#endif //PROJET_SCIENTIFICSYMBOL_H
