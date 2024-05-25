#ifndef WONDERCOSTREDUCEDBYX_H
#define WONDERCOSTREDUCEDBYX_H

#include "EffectFactory.h"

class WonderCostReducedByX : public Effect {
public:
    WonderCostReducedByX() : reduction(0) {};

    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void eachTurnEffect(Game& game, Card& card) override;
private:
    int reduction;

};


REGISTER_CLASS(WonderCostReducedByX);

#endif


