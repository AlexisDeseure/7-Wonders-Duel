#ifndef DISCARDADVERSARYCARD_H
#define DISCARDADVERSARYCARD_H

#include "EffectFactory.h"

enum class BuildingType;

class DiscardAdversaryCard: public Effect{
public:
    DiscardAdversaryCard() = default;
    void effect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
    void print() override;
private:
    BuildingType type;
};

REGISTER_CLASS(DiscardAdversaryCard);

#endif
