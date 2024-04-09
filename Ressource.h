// Created by mateo on 09/04/2024.
#ifndef PROJET_RESSOURCE_H
#define PROJET_RESSOURCE_H

/*Une ressource n'a qu'un seul type, il faudra faire gaffe à la composition
avec City, bien faire une liste et que la fonction de rajout vérifie correctement qu'il n'y a pas déjà le type
*/
namespace Ressource{
    enum class RessourceType {
    };

    class Ressource {
    private:
        RessourceType Type;
        int amount;
        int price;
    public:
        void add(int sum) { amount += sum; }; //Rajoute sum matériaux
        int getPrice() const { return price; };

        void updatePrice(int sum) { price += sum; }; //Soustraire des ressources = donner valeur négative
    };

}
#endif //PROJET_RESSOURCE_H