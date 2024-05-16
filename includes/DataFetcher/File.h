#ifndef FILE_H
#define FILE_H

#define FILE_PATH "../../data/data.json"

#include <iostream>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>
#include <vector>


class File
{
private:
    QString file_path;
    QJsonDocument readFile();
    QJsonDocument file;

public:
    class EffectTransfer
    {
    private:
        QString effect_name = "";
        std::vector<QString> string_param = {};
        std::vector<int> int_param = {};
    public:
        QString getEffect(){return effect_name;}
        std::vector<QString> getResType(){return string_param;}
        std::vector<int> getAmount() {return int_param;}
        void addResType(QString resType){string_param.insert(string_param.end(),1,resType);}
        void addAmount(int amount){int_param.insert(int_param.end(),1,amount);}
        void setEffectName(QString name){effect_name = name;}
        EffectTransfer() = default;
    };

    File() : file_path(FILE_PATH), file(readFile()) {};
    QString getFilePath(){return file_path;}
    QJsonDocument getFile() {return file;}

    QJsonArray listeBuildings();
    QJsonArray listeProgressToken();
    QJsonArray listeWonder();

    QJsonObject getBuildingsProperties(QString name);
    QJsonObject getProgressTokenProperties(QString name);
    QJsonObject getWonderProperties(QString name);

    std::vector<EffectTransfer> getBuildingEffects(QString name);
    std::vector<File::EffectTransfer> getProgressTokenEffects(QString name);
    std::vector<File::EffectTransfer> getWonderEffects(QString name);

    std::vector<std::pair<QString,QString>> getNames();

    std::vector<std::pair<QString,int>> getCost(QString name);


};

std::ostream& operator<<(std::ostream& os, File::EffectTransfer& effet);

#endif
