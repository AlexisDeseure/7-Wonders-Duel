#ifndef BUILDING_H
#define BUILDING_H
#include "Card.h"

class Building : public Card{
private:
    int age;
    ~Building() = default;
public:
    Building(int a):age(a){};
};

#endif
