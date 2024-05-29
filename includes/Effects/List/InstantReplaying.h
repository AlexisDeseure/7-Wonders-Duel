#ifndef INSTANTREPLAYING_H
#define INSTANTREPLAYING_H

#include "EffectFactory.h"

class InstantReplaying : public Effect {
    public:
        InstantReplaying() = default;
        void effect(Game& game) override;
        void print() override {std::cout << "Rejouer immédiatement" << std::endl;};
};

REGISTER_CLASS(InstantReplaying);

#endif
