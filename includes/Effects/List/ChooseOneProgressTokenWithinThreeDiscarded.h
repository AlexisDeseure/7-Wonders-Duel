#ifndef CHOOSEONEPROGRESSTOKENWITHINTHREEDISCARDED_H
#define CHOOSEONEPROGRESSTOKENWITHINTHREEDISCARDED_H

#include "EffectFactory.h"

class ChooseOneProgressTokenWithinThreeDiscarded: public Effect{
public:
    ChooseOneProgressTokenWithinThreeDiscarded() = default;
    void effect(Game& game) override;
};

REGISTER_CLASS(ChooseOneProgressTokenWithinThreeDiscarded);
#endif
