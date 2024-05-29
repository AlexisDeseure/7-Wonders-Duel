#ifndef EARNVICTORYPOINTPERTHINGMOSTATENDGAME_H
#define EARNVICTORYPOINTPERTHINGMOSTATENDGAME_H

#include "EffectFactory.h"
#include <vector>
enum class BuildingType;
class City;

class EarnVictoryPointPerThingMostAtEndGame : public Effect {
    public:
        EarnVictoryPointPerThingMostAtEndGame() = default;

        void effect(Game& game) override;
        void endEffect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
        int processTotalNumberForCity(City& city);
        void print() override;

    private:
        int number;
        std::vector<BuildingType> types;

};


REGISTER_CLASS(EarnVictoryPointPerThingMostAtEndGame);

#endif
