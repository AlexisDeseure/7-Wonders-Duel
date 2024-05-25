#ifndef INSTANCIATOR_H
#define INSTANCIATOR_H


#include "Building.h"
#include "Wonder.h"
#include "Card.h"
#include "ProgressToken.h"
#include "File.h"
#include "Game.h"
#include "GameParameters.h"

class Instanciator
{
private:
    // structure de données à revoir en fonction de votre implémentation.
    std::vector<Building*> buildings_instanciator;
    std::vector<Wonder*> wonders_instanciator;
    std::vector<ProgressToken*> progress_tokens_instanciator;
    File* cards_file;
    GameParameters& game_parameters;
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

    Instanciator() : game_parameters(*new GameParameters(GAME_PARAMETERS_PATH)){
        std::cout << "test1";
        cards_file = new File(game_parameters.getCardsPath());
        names = cards_file->getNames();
        constructBuilding();
        constructWonder();
        constructPT();
    };

public:

    static Instanciator* getInstanciator(){
        if (!instance){
            instance = new Instanciator;
        }
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
    std::pair<std::vector<Building*>,std::vector<Building*>> extractXRandomBuildingsFrom(std::vector<Building*> cartes,unsigned int X);
    std::vector<Wonder*> extractXRandomWondersFrom(std::vector<Wonder*> cartes,unsigned int X);
    std::pair<std::vector<ProgressToken*>,std::vector<ProgressToken*>> extractXRandomProgressTokensFrom(std::vector<ProgressToken*> cartes,unsigned int X);

    //Extraction des cartes d'un âge:
    std::vector<Building*> getCardFromXAge(int age);

    const GameParameters& getGameParameters() const {return game_parameters;}
};

#endif // INSTANCIATOR_H
