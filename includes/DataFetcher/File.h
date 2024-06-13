#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>
#include <vector>

class RessourceCost;

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
        QString effect_name;
        std::vector<std::string> string_param;
        std::vector<int> int_param;
    public:
        QString getEffect(){return effect_name;}
        std::vector<std::string> getResType(){return string_param;}
        std::vector<int> getAmount() {return int_param;}

        void addResType(QString resType){string_param.insert(string_param.end(),1,resType.toStdString());}
        void addAmount(int amount){int_param.insert(int_param.end(),1,amount);}
        void setEffectName(QString name){effect_name = name;}

        EffectTransfer() = default;
    };

    File(std::string name);
    QString getFilePath(){return file_path;}
    QJsonDocument getFile() {return file;}

    QJsonArray listeBuildings();
    QJsonArray listeProgressToken();
    QJsonArray listeWonder();
    std::vector<std::pair<QString,QString>> getNames();

    QJsonObject getBuildingsProperties(QString name);
    QJsonObject getProgressTokenProperties(QString name);
    QJsonObject getWonderProperties(QString name);

    std::vector<EffectTransfer> getBuildingEffects(QString name);
    std::vector<File::EffectTransfer> getProgressTokenEffects(QString name);
    std::vector<File::EffectTransfer> getWonderEffects(QString name);

    std::vector<RessourceCost> getCost(QString name);

    std::pair<QString,QString> getChaining(QString name);

    QString getScientificSymbol(QString name);

    QString getColor(QString name);

    QString getImage(QString name);

    int getAge(QString name);

    int getDirectCost(QString name);
};

std::ostream& operator<<(std::ostream& os, File::EffectTransfer& effet);

#endif
