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
         src/Cards/Card.cpp 
         src/City/Ressources.cpp  
        test/test_effects.cpp
        test/example_test_feature_2.cpp
 "test/example_test_feature_1.cpp")

