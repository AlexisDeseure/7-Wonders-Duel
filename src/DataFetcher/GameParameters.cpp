#include "GameParameters.h"
#include "Effect.h"
#include "EffectFactory.h"

GameParameters::GameParameters(std::string file_path):cards_path(""), coins_start(0), number_age(0), wonders_max(0), number_selected_wonders(0), number_building_per_age(0), number_progress_token_board(0), number_card_guilds(0), length_conflict_pawn_board(0){
    readAndInstanciate(file_path);
}

GameParameters::~GameParameters(){
    for(auto it = conflict_pawn_board.begin(); it != conflict_pawn_board.end(); ++it){
        delete it->effect;
    }
}

void GameParameters::readAndInstanciate(std::string file_path){
    QFile file(QString::fromStdString(file_path));
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Error opening file";
        throw JsonReadException("Impossible de lire le fichier de paramètres, vérifier le chemin");
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    QJsonObject obj = doc.object();

    cards_path = obj["cards_path"].toString().toStdString();
    buildings_layout_path = obj["buildings_layout_path"].toString().toStdString();
    coins_start = obj["coin_start"].toInt();
    base_market_coins = obj["base_market_coins"].toInt();
    number_age = obj["number_age"].toInt();
    number_scientific_symbol_to_win = obj["number_scientific_symbol_to_win"].toInt();

    QJsonObject cards = obj["cards"].toObject();
    wonders_max = cards["wonders_max"].toInt();
    number_selected_wonders = cards["number_selected_wonders"].toInt();
    number_building_per_age = cards["number_building_per_age"].toInt();
    number_progress_token_board = cards["number_progress_token_board"].toInt();
    number_card_guilds = cards["number_card_guilds"].toInt();
    QJsonObject conflict_pawn = obj["conflict_pawn"].toObject();
    length_conflict_pawn_board = conflict_pawn["length"].toInt();
    QJsonArray disposition = conflict_pawn["disposition"].toArray();
    for(auto it = disposition.begin(); it != disposition.end(); ++it){
        QJsonObject element = it->toObject();
        ConflictPawnElement cpe;
        cpe.number = element["number"].toInt();

        cpe.victory_points = element["victory_points"].toInt();
        if(element["effect"].isNull()){
            cpe.effect = nullptr;
        }else{
            QJsonObject effect = element["effect"].toObject();
            cpe.effect = EffectFactory::instance().create(effect.begin().key().toStdString());
            //parcourir les paramètres de l'effet pour créer un vector de paramètres de int et de string
            QJsonArray params = effect.begin().value().toArray();
            std::vector<int> element_int;
            std::vector<std::string> element_str;
            for(auto it = params.begin(); it != params.end(); ++it){
                if(it->isString()){
                    element_str.push_back(it->toString().toStdString());
                }else{
                    element_int.push_back(it->toInt());
                }
            }
            cpe.effect->setParameters(element_int, element_str);
        }
        conflict_pawn_board.push_back(cpe);
    }
}

std::ostream &operator<<(std::ostream &os, const GameParameters &game_parameters){
    os << "cards_path: " << game_parameters.getCardsPath() << std::endl;
    os << "coins_start: " << game_parameters.getCoinsStart() << std::endl;
    os << "number_age: " << game_parameters.getNumberAge() << std::endl;
    os << "wonders_max: " << game_parameters.getWondersMax() << std::endl;
    os << "number_selected_wonders: " << game_parameters.getNumberSelectedWonders() << std::endl;
    os << "number_building_per_age: " << game_parameters.getNumberBuildingPerAge() << std::endl;
    os << "number_progress_token_board: " << game_parameters.getNumberProgressTokenBoard() << std::endl;
    os << "number_card_guilds: " << game_parameters.getNumberCardGuilds() << std::endl;
    os << "length_conflict_pawn_board: " << game_parameters.getLengthConflictPawnBoard() << std::endl;
    os << "conflict_pawn_board: " << std::endl;
    for(auto& el : game_parameters.getConflictPawnBoard()){
        os << "number: " << el.number << " victory_points: " << el.victory_points << std::endl;
    }
    return os;
}
