#ifndef BUILDONEDISCARDEDBUILDING_H
#define BUILDONEDISCARDEDBUILDING_H

#include "EffectFactory.h"

class BuildOneDiscardedBuilding: public Effect{
public:
    BuildOneDiscardedBuilding() = default;
    void effect(Game& game) override{};
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override{};
};

REGISTER_CLASS(BuildOneDiscardedBuilding);

#endif
