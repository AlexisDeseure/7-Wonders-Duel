#ifndef CHOOSEPROGRESSTOKENDISCARDED_H
#define CHOOSEPROGRESSTOKENDISCARDED_H

#include "EffectFactory.h"

class ChooseProgressTokenDiscarded: public Effect{
public:
    ChooseProgressTokenDiscarded() = default;
    void effect(Game& game) override;
};

REGISTER_CLASS(ChooseProgressTokenDiscarded);
#endif
