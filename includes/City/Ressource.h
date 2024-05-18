#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <string>
#include <array>
#include <vector>

/*Une ressource n'a qu'un seul type, il faudra faire gaffe à la composition
avec City, bien faire une liste et que la fonction de rajout vérifie correctement qu'il n'y a pas déjà le type
*/


enum class RessourceType {
    Wood,
    Stone,
    Clay,
    Paper,
    Glass,
    LENGTH
};

extern const std::array<std::string, static_cast<int>(RessourceType::LENGTH)> ressource_name;

class Ressource {
    private:
        std::vector<RessourceType> types;
        unsigned int amount;
        unsigned int price;
        bool isTradable;
        bool isMarketRuleHasChanged;
        //amount = quantite de ressources
        // price = prix d'une seule ressource

    public:
        //friend std::ostream& operator<<(std::ostream& os, const Ressource& res);
        explicit Ressource(std::vector<RessourceType> t, unsigned int a=0, unsigned int p=2);

        unsigned int getPrice() const;

        void updatePrice(int sum); //baisser le prix = donner valeur négative

        unsigned int getAmount() const;

        void add(int sum); // à supprimer à terme
        void operator+=(unsigned int sum);
        bool getTradable() const { return isTradable; }

        void changeMarketRule(){isMarketRuleHasChanged=true;};
        RessourceType getType() const;

        std::vector<RessourceType> getTypes() const { return types; };

};

std::string ressourceTypeToString(RessourceType type);
RessourceType StringToRessourceType(std::string nom);
    

#endif
