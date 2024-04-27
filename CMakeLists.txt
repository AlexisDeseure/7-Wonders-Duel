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
        src/BoardManager/ConflictPawn.cpp test/example_test_feature_1.cpp test/example_test_feature_2.cpp includes/Cards/Building.h includes/Effects/Effect.h src/Effects/Effect.cpp)

