#ifndef EARNXVICTORYPOINTPERMOSTWONDERATENDGAME_H
#define EARNXVICTORYPOINTPERMOSTWONDERATENDGAME_H

#include "EffectFactory.h"
#include <vector>

class City;

class EarnXVictoryPointPerMostWonderAtEndGame : public Effect {
    public:
        EarnXVictoryPointPerMostWonderAtEndGame() = default;

        void effect(Game& game) override;
        void endEffect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

    private:
        int number;

};


REGISTER_CLASS(EarnXVictoryPointPerMostWonderAtEndGame);

#endif
