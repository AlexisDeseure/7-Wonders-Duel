#ifndef BUILDONEDISCARDEDBUILDING_H
#define BUILDONEDISCARDEDBUILDING_H

#include "EffectFactory.h"

class BuildOneDiscardedBuilding: public Effect{
public:
    BuildOneDiscardedBuilding() = default;
    void effect(Game& game) override;
};

REGISTER_CLASS(BuildOneDiscardedBuilding);

#endif
