#ifndef INSTANTREPLAYING_H
#define INSTANTREPLAYING_H

#include "EffectFactory.h"

class InstantReplaying : public Effect {
    public:
        InstantReplaying() = default;
        void effect(Game& game) override;
};

REGISTER_CLASS(InstantReplaying);

#endif
