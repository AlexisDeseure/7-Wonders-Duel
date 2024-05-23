#ifndef NEWWONDERSHAVEINSTANTREPLAYING_H
#define NEWWONDERSHAVEINSTANTREPLAYING_H

#include "EffectFactory.h"

class NewWondersHaveInstantReplaying : public Effect {
public:
    NewWondersHaveInstantReplaying() = default;

    void effect(Game& game) override;
    void eachTurnEffect(Game& game, Card& card) override;

};


REGISTER_CLASS(NewWondersHaveInstantReplaying);

#endif
