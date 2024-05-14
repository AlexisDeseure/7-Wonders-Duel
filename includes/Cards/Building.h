#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>

#include "Card.h"

class Building : public Card{
private:
    int age;
    std::vector<std::string> chainIn;
    std::vector<std::string> chainOut;

public:
    ~Building() = default;
    Building(const std::string& name, const std::vector<Ressource*>& cost, const std::vector<Effect*>& effects,
             int a, const std::vector<std::string>& chainIn, const std::vector<std::string>& chainOut)
             : Card(name, cost, effects), age(a), chainIn(chainIn), chainOut(chainOut) {};

    int getAge() const {return age;};
    void addChainOutToCity(City* city) const;
    bool isChainInInCity(const City* city) const override;

};

#endif
