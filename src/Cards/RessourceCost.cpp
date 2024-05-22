#include "RessourceCost.h"

void RessourceCost::addResType(std::pair<RessourceType,int> Res){
    cost.insert(cost.end(),1,Res);
}
