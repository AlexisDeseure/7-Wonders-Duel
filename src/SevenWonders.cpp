#include"C:\Users\ismat\Documents\UTC - GI02\LO21\git\7_Wonders_Duel\includes\City\Ressource.h"
#include"C:\Users\ismat\Documents\UTC - GI02\LO21\git\7_Wonders_Duel\includes\Cards\Card.h"

using namespace std; 
    
int main() {
    Ressource* R1 = new Ressource(RessourceType::Stone, 2, 4);
    Ressource* R2 = new Ressource(RessourceType::Stone, 2, 4); 
    Ressource* R3 = new Ressource(RessourceType::Stone, 2, 4);

    // int a = static_cast<int>(R.getType());
    Card * Carte =  new Card("Card_Essai");
    Carte->ajouteRessources(*R1); 
    Carte->ajouteRessources(*R2);
    Carte->ajouteRessources(*R3);

   Carte->getPriceRessources(); 
    return 0;
}   
    














