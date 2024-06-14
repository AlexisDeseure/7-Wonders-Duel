#ifndef INSTANCIATOR_H
#define INSTANCIATOR_H



#include "File.h"
#include "Game.h"
#include "GameParameters.h"
#include "BuildingsLayout.h"

class Building;
class Wonder;
class Card;
class ProgressToken;


class Instanciator
{
private:
    // structure de données à revoir en fonction de votre implémentation.
    std::vector<Building*> buildings_instanciator;
    std::vector<Wonder*> wonders_instanciator;
    std::vector<ProgressToken*> progress_tokens_instanciator;
    File* cards_file;
    BuildingsLayout* buildings_layout;
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
        cards_file = new File(game_parameters.getCardsPath());
        buildings_layout = new BuildingsLayout(game_parameters.getBuildingsLayoutPath(), game_parameters.getNumberAge());
        names = cards_file->getNames();
        constructBuilding();
        constructWonder();
        constructPT();
    };

public:

    ~Instanciator();
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
    BuildingsLayout& getBuildingsLayout() const {return *buildings_layout;}
};

#endif // INSTANCIATOR_H
