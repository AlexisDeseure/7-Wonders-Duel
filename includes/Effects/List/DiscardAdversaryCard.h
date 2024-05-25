#ifndef DISCARDADVERSARYCARD_H
#define DISCARDADVERSARYCARD_H

#include "EffectFactory.h"

class DiscardAdversaryCard: public Effect{
public:
    DiscardAdversaryCard() = default;
    void effect(Game& game) override{};
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override{};
};

REGISTER_CLASS(DiscardAdversaryCard);

#endif
