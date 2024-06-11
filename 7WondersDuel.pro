# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = 7WondersDuel

QT       += core gui
#QT = core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DISTFILES += \
    data/cards.json \
    data/game_parameters.json \
    data/buildings_layout.json


HEADERS = \
   includes/BoardManager/Board.h \
   includes/BoardManager/ConflictPawn.h \
   includes/Cards/Building.h \
   includes/Cards/Card.h \
   includes/Cards/ProgressToken.h \
   includes/Cards/RessourceCost.h \
   includes/Cards/Wonder.h \
   includes/City/City.h \
   includes/City/Ressource.h \
   includes/City/ScientificSymbol.h \
   includes/DataFetcher/GameParameters.h \
   includes/DeckManager/DeckElement.h \
   includes/DeckManager/MarketDeck.h \
   includes/Effects/IncludeEffects.h \
   includes/Effects/List/AddMoney.h \
   includes/Effects/List/AddRessource.h \
   includes/Effects/List/AddRessourceChoice.h \
   includes/Effects/List/AddScientificSymbol.h \
   includes/Effects/List/AddVictoryPoint.h \
   includes/Effects/List/AdversaryPaysMoneyToBank.h \
   includes/Effects/List/BuildOneDiscardedBuilding.h \
   includes/Effects/List/ChangeMarketRule.h \
   includes/Effects/List/ChooseProgressTokenDiscarded.h \
   includes/Effects/List/DiscardAdversaryCard.h \
   includes/Effects/List/EarnMoneyPerBuildingChaining.h \
   includes/Effects/List/EarnMoneyPerMostAtConstruct.h \
   includes/Effects/List/EarnMoneyPerWonderAtConstruct.h \
   includes/Effects/List/EarnVictoryPointPerLotOfMoneyMostAtEndGame.h \
   includes/Effects/List/EarnVictoryPointPerMostWonderAtEndGame.h \
   includes/Effects/List/EarnVictoryPointPerThingMostAtEndGame.h \
   includes/Effects/List/EarnVictoryPointsPerProgressTokenAtEndGame.h \
   includes/Effects/List/InstantReplaying.h \
   includes/Effects/List/MoveConflictPawn.h \
   includes/Effects/List/MoveConflictPawnMorePerNew.h \
   includes/Effects/List/NewWondersHaveInstantReplaying.h \
   includes/Effects/List/TakeAdversaryTradeMoney.h \
   includes/Effects/List/WonderCostReducedByX.h \
   includes/Effects/Effect.h \
   includes/Effects/EffectFactory.h \
   includes/Effects/List/BuildingCostReducedByX.h \
   includes/Game/DeckPile.h \
   includes/Game/Game.h \
   includes/Game/GameUI.h \
   includes/Game/Player.h \
   includes/DataFetcher/File.h \
   includes/Ui/ChooseWondersUI.h \
   includes/Ui/Connector.h \
   includes/Ui/SevenWonderUI.h \
   includes/DataFetcher/Instanciator.h \
   includes/DataFetcher/BuildingsLayout.h \
   includes/Ui/StartMenu.h \
   includes/Ui/game_window.h \
   includes/Ui/marketdeckwidget.h \
   includes/Ui/militarydeck.h \
   includes/Ui/playerwidget.h \
   includes/Ui/Subject.h

SOURCES = \
   src/BoardManager/Board.cpp \
   src/BoardManager/ConflictPawn.cpp \
   src/Cards/Building.cpp \
   src/Cards/Card.cpp \
   src/Cards/RessourceCost.cpp \
   src/City/City.cpp \
   src/City/Ressource.cpp \
   src/City/ScientificSymbol.cpp \
   src/DataFetcher/BuildingsLayout.cpp \
   src/DataFetcher/GameParameters.cpp \
   src/DataFetcher/Instanciator.cpp \
   src/DeckManager/DeckElement.cpp \
   src/DeckManager/MarketDeck.cpp \
   src/Effects/List/AddMoney.cpp \
   src/Effects/List/AddRessource.cpp \
   src/Effects/List/AddRessourceChoice.cpp \
   src/Effects/List/AddScientificSymbol.cpp \
   src/Effects/List/AddVictoryPoint.cpp \
   src/Effects/List/AdversaryPaysMoneyToBank.cpp \
   src/Effects/List/BuildOneDiscardedBuilding.cpp \
   src/Effects/List/BuildingCostReducedByX.cpp \
   src/Effects/List/ChangeMarketRule.cpp \
   src/Effects/List/ChooseProgressTokenDiscarded.cpp \
   src/Effects/List/DiscardAdversaryCard.cpp \
   src/Effects/List/EarnMoneyPerBuildingChaining.cpp \
   src/Effects/List/EarnMoneyPerMostAtConstruct.cpp \
   src/Effects/List/EarnMoneyPerWonderAtConstruct.cpp \
   src/Effects/List/EarnVictoryPointPerLotOfMoneyMostAtEndGame.cpp \
   src/Effects/List/EarnVictoryPointPerMostWonderAtEndGame.cpp \
   src/Effects/List/EarnVictoryPointPerThingMostAtEndGame.cpp \
   src/Effects/List/EarnVictoryPointsPerProgressTokenAtEndGame.cpp \
   src/Effects/List/InstantReplaying.cpp \
   src/Effects/List/MoveConflictPawn.cpp \
   src/Effects/List/MoveConflictPawnMorePerNew.cpp \
   src/Effects/List/NewWondersHaveInstantReplaying.cpp \
   src/Effects/List/TakeAdversaryTradeMoney.cpp \
   src/Effects/List/WonderCostReducedByX.cpp \
   src/Effects/Effect.cpp \
   src/Game/DeckPile.cpp \
   src/Game/Game.cpp \
   src/Game/GameUI.cpp \
   src/Game/Player.cpp \
   src/DataFetcher/File.cpp \
   src/SevenWonders.cpp \
   src/Ui/Connector.cpp \
   src/Ui/SevenWonderUI.cpp \
   src/Ui/StartMenu.cpp \
   src/Ui/game_window.cpp \
   src/Ui/marketdeckwidget.cpp \
   src/Ui/militarydeck.cpp \
   src/Ui/playerwidget.cpp \
   src/Ui/uitest.cpp

INCLUDEPATH = \
    includes/BoardManager \
    includes/Cards \
    includes/City \
    includes/DeckManager \
    includes/Effects \
    includes/Effects/List \
    includes/Game \
    includes/DataFetcher \
    includes/Ui

FORMS += \
    SevenWonderUI.ui

RESOURCES += ressources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
