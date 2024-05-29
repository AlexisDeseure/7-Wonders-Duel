#ifndef CHOOSEPROGRESSTOKENDISCARDED_H
#define CHOOSEPROGRESSTOKENDISCARDED_H

#include "EffectFactory.h"

class ChooseProgressTokenDiscarded: public Effect{
public:
    ChooseProgressTokenDiscarded() = default;
    void effect(Game& game) override;
    void print() override { std::cout << "Choisir un jeton progrès parmis 3 hors du plateau" << std::endl; };
};

REGISTER_CLASS(ChooseProgressTokenDiscarded);
#endif
