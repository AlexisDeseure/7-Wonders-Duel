//Crée par Mateo
#ifndef PROJET_RESSOURCE_H
#define PROJET_RESSOURCE_H

/*Une ressource n'a qu'un seul type, il faudra faire gaffe à la composition
avec City, bien faire une liste et que la fonction de rajout vérifie correctement qu'il n'y a pas déjà le type
*/
    enum class RessourceType {
        Wood,
        Stone,
        Clay,
        Paper,
        Glass
    };

    class Ressource {
    private:
        RessourceType type;
        int amount;
        int price;
        const City* city; //est-ce que la classe city est vraiment nécessaire ici ? On peut bien accéder aux ressources depuis une ville, faire le contraire n'est pas nécessaire
    public:
        void add(int sum) { amount += sum; }; //Rajoute sum matériaux
        int getPrice() const { return price; };
        
        void updatePrice(int sum) { price += sum; }; //Soustraire des ressources = donner valeur négative
    };

#endif //PROJET_RESSOURCE_H

















