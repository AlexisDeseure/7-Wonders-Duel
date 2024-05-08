#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>

#include "Card.h"

class Building : public Card{
private:
    int age;
    ~Building() = default;
public:
    Building(const std::string& n, int a) : Card(n), age(a) {};
    int getAge() const {return age;};

};

#endif
