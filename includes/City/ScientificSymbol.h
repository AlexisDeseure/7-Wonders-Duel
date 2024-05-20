#ifndef SCIENTIFICSYMBOL_H
#define SCIENTIFICSYMBOL_H

#include <array>
#include <string>

/*Un symbole n'a qu'un seul type, il faudra faire gaffe à la composition de la classe ScientificSymbol
avec City, bien faire une liste et que la fonction de rajout vérifie correctement qu'il n'y a pas déjà le type
*/
enum class SymboleType {
    armillary_sphere,
    scale,
    sundial,
    pestle,
    archipendulum,
    wheel,
    quill,
    LENGTH
};

const std::array<std::string, static_cast<int>(SymboleType::LENGTH)> symbole_name { "armillary_sphere", "scale", "sundial", "pestle", "archipendulum", "wheel", "quill"};

class ScientificSymbol{
    private:
        int count; //Nombre de symboles d'un seul type
        SymboleType symbol_type;


    public:
        ScientificSymbol(SymboleType type, int number = 0) : count(number), symbol_type(type){};
        void add(){ //Add ne se déclenche que lorsque l'on truove un symbole scientifique identique dans la même ville
            count++; //Incrémentation du nombre de symboles
        }
        void operator++(int){ //Surcharge de l'opérateur ++ pour incrémenter le nombre de symboles
            count++;
        }
        void operator+=(int sum){
            count+=sum;
        };
        SymboleType getType() const { return symbol_type; }; //Renvoie le type de symbole
};

std::string symboleTypeToString(SymboleType type);
SymboleType StringToSymboleType(std::string nom);


#endif
