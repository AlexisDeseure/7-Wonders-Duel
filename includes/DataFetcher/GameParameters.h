#ifndef GAMEPARAMETERS_H
#define GAMEPARAMETERS_H


#include <QException>
#include <QString>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>
#include <vector>
#include <string>
#include <iostream>

class Effect;

class GameParameters{
private:
    struct ConflictPawnElement{
        int number;
        int victory_points;
        Effect* effect;
    };

    std::string cards_path;
    std::string cards_image_path;
    std::string cards_image_back_age1;
    std::string cards_image_back_age2;
    std::string cards_image_back_age3;
    std::string buildings_layout_path;

    int coins_start;
    int base_market_coins;
    int number_age;
    int number_scientific_symbol_to_win;

    int wonders_max;
    int number_selected_wonders;
    int number_building_per_age;
    int number_progress_token_board;
    int number_card_guilds;

    int length_conflict_pawn_board;
    std::vector<ConflictPawnElement> conflict_pawn_board;

public:
    GameParameters(std::string file_path);
    ~GameParameters();

    void readAndInstanciate(std::string file_path);

    std::string getCardsPath() const { return cards_path; }
    std::string getBuildingsLayoutPath() const { return buildings_layout_path; }
    std::string getCardsImagePath() const { return cards_image_path; }
    std::string getCardsImageBackAge1() const { return cards_image_back_age1; }
    std::string getCardsImageBackAge2() const { return cards_image_back_age2; }
    std::string getCardsImageBackAge3() const { return cards_image_back_age3; }
    int getCoinsStart() const { return coins_start; }
    int getBaseMarketCoins() const { return base_market_coins; }
    int getNumberAge() const { return number_age; }
    int getWondersMax() const { return wonders_max; }
    int getNumberSelectedWonders() const { return number_selected_wonders; }
    int getNumberBuildingPerAge() const { return number_building_per_age; }
    int getNumberProgressTokenBoard() const { return number_progress_token_board; }
    int getNumberCardGuilds() const { return number_card_guilds; }
    int getLengthConflictPawnBoard() const { return length_conflict_pawn_board; }
    int getNumberScientificSymbolToWin() const { return number_scientific_symbol_to_win; }
    std::vector<ConflictPawnElement> getConflictPawnBoard() const { return conflict_pawn_board; }


};


class JsonReadException : public std::runtime_error {
public:
    // Constructeur avec un message d'erreur
    explicit JsonReadException(const QString& message)
        : std::runtime_error(message.toStdString()), message(message.toStdString()) {}

    // Méthode what() pour obtenir le message d'erreur
    const char* what() const noexcept override {
        return message.c_str();
    }

    // Accesseur pour obtenir le message d'erreur
    QString getMessage() const {
        return QString::fromStdString(message);
    }

private:
    std::string message;
};


std::ostream &operator<<(std::ostream &os, const GameParameters &game_parameters);


#endif // GAMEPARAMETERS_H
