#ifndef INSTANTREPLAYING_H
#define INSTANTREPLAYING_H

#include "EffectFactory.h"

class InstantReplaying : public Effect {
    public:
        InstantReplaying() = default;
        void effect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override {};
};

REGISTER_CLASS(InstantReplaying);

#endif
