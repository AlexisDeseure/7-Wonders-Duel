#ifndef TAKEADVERSARYTRADEMONEY_H
#define TAKEADVERSARYTRADEMONEY_H

#include "EffectFactory.h"

class TakeAdversaryTradeMoney : public Effect {
public:
    TakeAdversaryTradeMoney() = default;

    void effect(Game& game) override;
    void eachTurnEffect(Game& game, Card& card) override;
    void print() override {std::cout << "Prendre l'argent investi par l'adversaire pour acheter des ressources" << std::endl;};

};


REGISTER_CLASS(TakeAdversaryTradeMoney);

#endif
