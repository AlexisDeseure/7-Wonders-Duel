cmake_minimum_required(VERSION 3.24)
project(7_Wonders_Duel)

set(CMAKE_CXX_STANDARD 17)

include_directories(.
        ./includes)

add_executable(7_Wonders_Duel
        src/SevenWonders.cpp

        includes/City/Ressource.h
        includes/City/ScientificSymbol.h
        includes/Cards/ProgressToken.h
        includes/DeckManager/DeckElement.h
        includes/DeckManager/MarketDeck.h
        includes/Cards/Wonder.h
        includes/City/City.h
        includes/Cards/Card.h
        includes/BoardManager/ConflictPawn.h
        includes/Effects/List/ChangeMarketRule.h
        includes/Cards/Building.h
        includes/Effects/Effect.h
        includes/Effects/List/EarnXVictoryPointPerThingMostAtEndGame.h
        includes/Effects/List/EarnXVictoryPointPerGoldAndBrownMostAtEndGame.h
        includes/Effects/List/EarnXVictoryPointPerMostWonderAtEndGame.h
        includes/Effects/List/EarnXMoneyPerWonderAtConstruct.h
        includes/Effects/List/EarnXMoneyPerMostAtConstruct.h
        includes/Effects/List/WonderCostReducedByX.h
        includes/Effects/List/TakeAdversaryTradeMoney.h
        includes/Effects/List/TakeScientificSymbol.h
        includes/Effects/List/EarnThreeVictoryPointsPerProgressTokenAtEndGame.h
        includes/Effects/List/MoveConflictPawnOneMorePerNewRed.h
        includes/Effects/List/NewWondersHaveInstantReplaying.h
        includes/Effects/List/EarnFourMoneyPerBuildingChaining.h
        includes/Effects/List/ChooseOneProgressTokenWithinThreeDiscarded.h
        includes/Effects/List/BuildOneDiscardedBuilding.h
        includes/Effects/List/AddRessourceChoice.h
        includes/Effects/List/DiscardAdversaryBrownCard.h
        includes/Effects/List/AddRessource.h
        includes/Effects/List/MoveConflictPawn.h
        includes/Effects/List/AddVictoryPoint.h
        includes/Effects/List/AdversaryPaysMoneyToBank.h
        includes/Effects/List/InstantReplaying.h
        includes/Effects/List/AddMoney.h
        includes/BoardManager/Board.h
        includes/Game/Game.h
        includes/Game/Player.h
        includes/Effects/EffectFactory.h

        src/DeckManager/DeckElement.cpp
        src/Cards/Wonder.cpp
        src/City/City.cpp
        src/BoardManager/ConflictPawn.cpp
        src/Effects/Effect.cpp
        src/City/Ressources.cpp
        src/Effects/List/EarnXVictoryPointPerThingMostAtEndGame.cpp
        src/Effects/List/EarnXVictoryPointPerGoldAndBrownMostAtEndGame.cpp
        src/Effects/List/EarnXVictoryPointPerMostWonderAtEndGame.cpp
        src/Effects/List/EarnXMoneyPerWonderAtConstruct.cpp
        src/Effects/List/EarnXMoneyPerMostAtConstruct.cpp
        src/Effects/List/WonderCostReducedByX.cpp
        src/Effects/List/TakeAdversaryTradeMoney.cpp
        src/Effects/List/TakeScientificSymbol.cpp
        src/Effects/List/EarnThreeVictoryPointsPerProgressTokenAtEndGame.cpp
        src/Effects/List/MoveConflictPawnOneMorePerNewRed.cpp
        src/Effects/List/NewWondersHaveInstantReplaying.cpp
        src/Effects/List/EarnFourMoneyPerBuildingChaining.cpp
        src/Effects/List/ChooseOneProgressTokenWithinThreeDiscarded.cpp
        src/Effects/List/BuildOneDiscardedBuilding.cpp
        src/Effects/List/AddRessourceChoice.cpp
        src/Effects/List/DiscardAdversaryBrownCard.cpp
        src/Effects/List/AddRessource.cpp
        src/Effects/List/MoveConflictPawn.cpp
        src/Effects/List/AddVictoryPoint.cpp
        src/Effects/List/AdversaryPaysMoneyToBank.cpp
        src/Effects/List/InstantReplaying.cpp
        src/Effects/List/AddMoney.cpp
        src/Cards/ProgressToken.cpp
        src/DeckManager/MarketDeck.cpp
        src/Cards/Building.cpp
        src/Game/Game.cpp
        src/Game/Player.cpp
        src/BoardManager/Board.cpp
        src/Cards/Card.cpp

        test/test_effects.cpp
        test/example_test_feature_2.cpp)


