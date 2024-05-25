#ifndef TAKEADVERSARYTRADEMONEY_H
#define TAKEADVERSARYTRADEMONEY_H

#include "EffectFactory.h"

class TakeAdversaryTradeMoney : public Effect {
public:
    TakeAdversaryTradeMoney() = default;

    void effect(Game& game) override;
    void eachTurnEffect(Game& game, Card& card) override;

};


REGISTER_CLASS(TakeAdversaryTradeMoney);

#endif
