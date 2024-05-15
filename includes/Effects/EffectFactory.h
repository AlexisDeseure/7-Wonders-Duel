#ifndef EFFECTFACTORY_H
#define EFFECTFACTORY_H

#include <iostream>
#include <map>
#include <functional>
#include <utility>

#include "Effect.h"

#define REGISTER_CLASS(NAME) \
    static bool dummy_##NAME = []() { \
        EffectFactory::instance().registerClass(#NAME, []() -> Effect* { return new NAME(); }); \
        return true; \
    }() // macro pour enregistrer une classe dans la factory

/* Exemple d'instanciation d'une classe à partir de son nom :
 * Effect* effect = EffectFactory::instance().create("AddMoney");
 */

class EffectFactory {
    // classe imporante pour instancier les effets à partir de leur nom en les enregistrant dans la factory
    public:
        using CreatorFunc = std::function<Effect*()>;

        static EffectFactory& instance() {
            static EffectFactory instance;
            return instance;
        }

        void registerClass(const std::string& className, CreatorFunc creator) {
            creators[className] = std::move(creator);
        }

        Effect* create(const std::string& className) {
            auto it = creators.find(className);
            if (it != creators.end()) {
                return it->second();
            }
            return nullptr;
        }

    private:
        std::map<std::string, CreatorFunc> creators;
};

#endif
