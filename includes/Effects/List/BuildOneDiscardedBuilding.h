#ifndef BUILDONEDISCARDEDBUILDING_H
#define BUILDONEDISCARDEDBUILDING_H

#include "EffectFactory.h"

class BuildOneDiscardedBuilding: public Effect{
public:
    BuildOneDiscardedBuilding() = default;
    void effect(Game& game) override;
    void print() override { std::cout << "Construire un batiment défaussé" << std::endl; };
};

REGISTER_CLASS(BuildOneDiscardedBuilding);

#endif
