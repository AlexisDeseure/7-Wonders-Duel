#ifndef ADDRESSOURCE_H
#define ADDRESSOURCE_H

#include "EffectFactory.h"

enum class RessourceType;

class AddRessource : public Effect {
    public:
        AddRessource();
        void effect(Game& game) override;
        void setParameters(std::vector<int> int_parameters, std::vector<std::string> string_parameters) override;
        void inverseEffect(Game& game) override;

    private:
        RessourceType ressource;
        int quantity;
        // obsolete correspond au 2ème paramètres dans le vecteur de int, permet de décider si oui
        //ou non le fait d'ajouter cette ressource augmente le prix pour l'adversaire (seulemment les cartes marrons et grises
        //selon les règles) par exemple les ressources produites par des wonder devrait avoir 0 pour cet attribut

};

REGISTER_CLASS(AddRessource);

#endif
