#ifndef RESSOURCECOST_H
#define RESSOURCECOST_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>
#include "Ressource.h"
enum class RessourceType;

class RessourceCost {
private:
    unsigned int amount;
    RessourceType type;
public:
    RessourceCost(int number, RessourceType t) : amount(static_cast<unsigned int>(number)), type(t){};
    unsigned int getAmount() const;
    RessourceType getType() const;

};


#endif // RESSOURCECOST_H
