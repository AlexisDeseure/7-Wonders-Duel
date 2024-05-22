#ifndef INSTANCIATOR_H
#define INSTANCIATOR_H

#include "../../Cards/Building.h"
#include "../../Cards/Wonder.h"
#include "../../Cards/ProgressToken.h"
#include "../../DataFetcher/File.h"

class Instanciator
{
private:
    // structure de données à revoir en fonction de votre implémentation.
    std::vector<Building> buildings_instanciator;
    std::vector<Wonder> wonders_instanciator;
    std::vector<ProgressToken> progress_tokens_instanciator;
    File json;
    std::vector<std::pair<QString,QString>> names;

    // On souhaite instancier une seule fois, on met en privé les méthodes qui permettent de créer les instances.
    void addBuildingToInstanciator(Building building);
    void addPTtoInstanciator(ProgressToken PT);
    void addWonderToInstanciator(Wonder wonder);

    // Créateur des instances en privé pour la même raison.
    void constructBuilding();
    void constructWonder();
    void constructPT();
    const std::vector<Ressource*> jsonToRessource(std::vector<std::pair<QString,int>> jsonRes);

public:
    //Instanciation directement dans le constructeur.
    Instanciator(): buildings_instanciator(),wonders_instanciator(),progress_tokens_instanciator() {
        names = json.getNames();
        constructBuilding();
        constructWonder();
        constructPT();
    };

    //Interdiction de la recopie à défaut de faire un singleton pour l'instant.
    Instanciator& operator=(const Instanciator& x) = delete;

    //L'Utilisateur pourra seulement avoir accès aux vecteurs des cartes plus haut.
    std::vector<Building>& getBuildings() {return buildings_instanciator;};
    std::vector<Wonder>& getWonders() {return wonders_instanciator;};
    std::vector<ProgressToken>& getPTInstanciator() {return progress_tokens_instanciator;};
    //On peut laisser la possibilité de donner la liste des cartes si besoin.
    std::vector<std::pair<QString,QString>>& getNames() {return names;}

    //Pioche

    //Extraction des cartes d'un âge:
    std::vector<Building> getCardFromXAge(int age);
};

#endif // INSTANCIATOR_H
