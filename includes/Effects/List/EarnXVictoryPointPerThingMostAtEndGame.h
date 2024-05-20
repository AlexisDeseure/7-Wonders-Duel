#ifndef EARNXVICTORYPOINTPERTHINGMOSTATENDGAME_H
#define EARNXVICTORYPOINTPERTHINGMOSTATENDGAME_H

#include "EffectFactory.h"
#include <vector>
enum class BuildingType;
class City;

class EarnXVictoryPointPerThingMostAtEndGame : public Effect {
    public:
        EarnXVictoryPointPerThingMostAtEndGame() = default;

        void effect(Game& game) override;
        void endEffect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
        int processTotalNumberForCity(City& city);

    private:
        int number;
        std::vector<BuildingType> types;

};


REGISTER_CLASS(EarnXVictoryPointPerThingMostAtEndGame);

#endif
