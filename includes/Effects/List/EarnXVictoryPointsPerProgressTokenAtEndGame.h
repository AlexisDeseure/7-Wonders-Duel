#ifndef EARNXVICTORYPOINTSPERPROGRESSTOKENATENDGAME_H
#define EARNXVICTORYPOINTSPERPROGRESSTOKENATENDGAME_H

#include "EffectFactory.h"
#include <vector>

class City;

class EarnXVictoryPointsPerProgressTokenAtEndGame : public Effect {
public:
    EarnXVictoryPointsPerProgressTokenAtEndGame() = default;

    void effect(Game& game) override;
    void endEffect(Game& game) override;
    void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;

private:
    int number;
};


REGISTER_CLASS(EarnXVictoryPointsPerProgressTokenAtEndGame);

#endif
