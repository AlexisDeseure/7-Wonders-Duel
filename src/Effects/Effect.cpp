#include "Effect.h"
#include "Game.h"
#include "Card.h"
#include "City.h"
#include "Building.h"

void Effect::apply(Game& game) {
    /*Comportement de base*/
    //std::cout << "Effet : " << getName() << "appliqué à la ville." << std::endl;

    /*Application de l'effet*/
    effect(game);
}
