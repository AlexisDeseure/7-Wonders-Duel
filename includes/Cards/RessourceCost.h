#ifndef RESSOURCECOST_H
#define RESSOURCECOST_H

#include <iostream>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>
#include "Ressource.h"

class RessourceCost {
private:
    std::vector<std::pair<RessourceType,int>> cost;
public:
    std::vector<std::pair<RessourceType,int>> getCost(){return cost;};
    void addResType(std::pair<RessourceType,int> Res);
};

#endif // RESSOURCECOST_H
