#include "Effect.h"
#include "City.h"

void Effect::apply(City* city) {
    /*Comportement de base*/
    //std::cout << "Effet : " << getName() << "appliqué à la ville." << std::endl;

    /*Application de l'effet*/
    effect(city);
}

