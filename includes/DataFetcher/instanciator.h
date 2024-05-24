#ifndef INSTANCIATOR_H
#define INSTANCIATOR_H

#include <ctime>
#include <cstdlib>
#include "Building.h"
#include "Wonder.h"
#include "Card.h"
#include "ProgressToken.h"
#include "File.h"
#include "Ressource.h"
#include "RessourceCost.h"
#include "EffectFactory.h"
#include "IncludeEffects.h"

class Instanciator
{
private:
    // structure de données à revoir en fonction de votre implémentation.
    std::vector<Building*> buildings_instanciator;
    std::vector<Wonder*> wonders_instanciator;
    std::vector<ProgressToken*> progress_tokens_instanciator;
    File json;
    std::vector<std::pair<QString,QString>> names;

    // On souhaite instancier une seule fois, on met en privé les méthodes qui permettent de créer les instances.
    void addBuildingToInstanciator(Building* building);
    void addPTtoInstanciator(ProgressToken* PT);
    void addWonderToInstanciator(Wonder* wonder);

    // Créateur des instances en privé pour la même raison.
    void constructBuilding();
    void constructWonder();
    void constructPT();

    std::vector<Effect*> effTransToEffect(std::vector<File::EffectTransfer> vecTransfer);

    static Instanciator* instance;

    Instanciator(): buildings_instanciator(),wonders_instanciator(),progress_tokens_instanciator() {
        names = json.getNames();
        constructBuilding();
        constructWonder();
        constructPT();
    };

public:

    static Instanciator* getInstanciator(){
        if (!instance)
            instance = new Instanciator;
        return instance;
    }

    //Interdiction de la recopie.
    Instanciator& operator=(const Instanciator& x) = delete;
    Instanciator(const Instanciator&)= delete;

    //L'Utilisateur pourra seulement avoir accès aux vecteurs des cartes plus haut.
    std::vector<Building*> getBuildings() {return buildings_instanciator;};
    std::vector<Wonder*> getWonders() {return wonders_instanciator;};
    std::vector<ProgressToken*> getPTInstanciator() {return progress_tokens_instanciator;};

    //On peut laisser la possibilité de donner la liste des cartes si besoin.
    std::vector<std::pair<QString,QString>>& getNames() {return names;}

    //Extraction de X cartes aléatoires depuis un certain paquet de cartes.
    std::vector<Building*> extractXRandomBuildingsFrom(std::vector<Building*> cartes,unsigned int X);
    std::vector<Wonder*> extractXRandomWondersFrom(std::vector<Wonder*> cartes,unsigned int X);
    std::vector<ProgressToken*> extractXRandomProgressTokensFrom(std::vector<ProgressToken*> cartes,unsigned int X);

    //Extraction des cartes d'un âge:
    std::vector<Building*> getCardFromXAge(int age);
};

#endif // INSTANCIATOR_H
