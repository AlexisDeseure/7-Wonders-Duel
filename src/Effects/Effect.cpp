#include "../../includes/Effects/Effect.h"
#include "../../includes/City/City.h"

void Effect::apply(City* city) const{
    /*Comportement de base*/
    std::cout << "Effet : " << getName() << "appliqué à la ville." << std::endl;

    /*Application de l'effet*/
    effect(city);
}
