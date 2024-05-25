#ifndef CHOOSEONEPROGRESSTOKENWITHINTHREEDISCARDED_H
#define CHOOSEONEPROGRESSTOKENWITHINTHREEDISCARDED_H

#include "EffectFactory.h"

class ChooseOneProgressTokenWithinThreeDiscarded: public Effect{
public:
    ChooseOneProgressTokenWithinThreeDiscarded() = default;
    void effect(Game& game) override{};
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override{};
};

REGISTER_CLASS(ChooseOneProgressTokenWithinThreeDiscarded);
#endif
