//Crée par Mateo
#ifndef SCIENTIFICSYMBOL_H
#define SCIENTIFICSYMBOL_H

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

class ScientificSymbol{
private:
    int count; //Nombre de symboles d'un seul type
    SymboleType symbol_type;


public:
    void add(){ //Add ne se déclenche que lorsque l'on truove un symbole scientifique identique dans la même ville
        count++; //Incrémentation du nombre de symboles
    }
    void operator++(int){ //Surcharge de l'opérateur ++ pour incrémenter le nombre de symboles
        count++;
    }
    SymboleType getType() const { return symbol_type; }; //Renvoie le type de symbole
};

#endif
