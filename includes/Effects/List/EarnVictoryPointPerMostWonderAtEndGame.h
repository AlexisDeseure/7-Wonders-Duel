#ifndef EARNVICTORYPOINTPERMOSTWONDERATENDGAME_H
#define EARNVICTORYPOINTPERMOSTWONDERATENDGAME_H

#include "EffectFactory.h"
#include <vector>

class City;

class EarnVictoryPointPerMostWonderAtEndGame : public Effect {
    public:
        EarnVictoryPointPerMostWonderAtEndGame() = default;

        void effect(Game& game) override;
        void endEffect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
        void print() override {std::cout << "Gagner " << number << " points de victoire par merveille de la cité qui en contient le plus à la fin de la partie" << std::endl;};
    private:
        int number;

};


REGISTER_CLASS(EarnVictoryPointPerMostWonderAtEndGame);

#endif
