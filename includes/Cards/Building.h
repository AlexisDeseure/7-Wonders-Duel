#ifndef BUILDING_H
#define BUILDING_H

#include "Card.h"
#include <iostream>
#include <QString>

enum class BuildingType {
    Yellow,
    Brown,
    Gray,
    Purple,
    Green,
    Red,
    Blue,
    LENGTH
};

const std::array<std::string, static_cast<int>(BuildingType::LENGTH)> building_type_name { "Yellow", "Brown", "Gray", "Purple", "Green", "Red", "Blue"};

class Building : public Card{
    private:
        int age;
        std::vector<std::string> chainIn;
        std::vector<std::string> chainOut;
        BuildingType type;

    public:
        ~Building() = default;
        Building(const std::string& name, const QString img,const std::vector<RessourceCost>& cost, const std::vector<Effect*>& effects, unsigned int direct_cost, BuildingType t,
                 int a, const std::vector<std::string>& chainIn = {}, const std::vector<std::string>& chainOut = {})
            : Card(name, cost, effects, direct_cost,img),age(a), chainIn(chainIn), chainOut(chainOut), type(t) {};
        BuildingType getType() const {return type;}
        int getAge() const {return age;};
        QString getImage() const {return image;};
        void addChainOutToCity(City* city) const; // les symboles en possession
        bool isChainInInCity(const City* city) const override;  // les symboles pour faire le build
        void print() const override;

};

std::string buildingTypeToString(BuildingType type);
BuildingType StringToBuildingType(std::string nom);

std::ostream &operator<<(std::ostream& os, const Building& b);

#endif
