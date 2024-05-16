#include "File.h"

QJsonDocument File::readFile() {
    QString JsonFilePath = getFilePath();
    QFile File(JsonFilePath);
    if (File.open(QIODevice::ReadOnly)){
        QByteArray Bytes = File.readAll();
        File.close();
        QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson(Bytes, &JsonError);
        if (JsonError.error!=QJsonParseError::NoError) {
            qDebug() << "Error in Json Data: " << JsonError.errorString();
        }
        else {
            qDebug() << "No error in Json";
            return Document;
        }
    }
    qDebug() << "Lecture Impossible";
}

QJsonArray File::listeBuildings() {
    QJsonDocument Document = getFile();
    if (Document.isObject()){
            QJsonObject Data = Document.object();
            QJsonObject LCartes = Data.value("Cards").toObject();
            QJsonArray LBuildings = LCartes.value("BuildingsList").toArray();
            return LBuildings;
        }
    qDebug() << "Erreur de lecture";
}


QJsonArray File::listeProgressToken() {
    QJsonDocument Document = getFile();
    if (Document.isObject()){
        QJsonObject Data = Document.object();
        QJsonObject LCartes = Data.value("Cards").toObject();
        QJsonArray LProgressToken = LCartes.value("ProgressTokenList").toArray();
        return LProgressToken;
    }
    qDebug() << "Erreur de lecture";
}

QJsonArray File::listeWonder(){
    QJsonDocument Document = getFile();
    if (Document.isObject()){
        QJsonObject Data = Document.object();
        QJsonObject LCartes = Data.value("Cards").toObject();
        QJsonArray LWonder = LCartes.value("WondersList").toArray();
        return LWonder;
    }
    qDebug() << "Erreur de lecture";
}

QJsonObject File::getBuildingsProperties(QString name){
    QJsonArray LBuildings = listeBuildings();
    for (auto points: LBuildings) {
        QJsonObject Building = points.toObject();
        QString Bname = Building.value("name").toString();
        if (name == Bname) {
            return Building;
        }
    }
    return {};
}

QJsonObject File::getProgressTokenProperties(QString name){
    QJsonArray LPG = listeProgressToken();
    for (auto points: LPG) {
        QJsonObject PG = points.toObject();
        QString PGname = PG.value("name").toString();
        if (name == PGname) {
            return PG;
        }
    }
    return {};
}
QJsonObject File::getWonderProperties(QString name){
    QJsonArray LWonder = listeWonder();
    for (auto points: LWonder) {
        QJsonObject Wonder = points.toObject();
        QString Wname = Wonder.value("name").toString();
        if (name == Wname) {
            return Wonder;
        }
    }
    return {};
}

std::vector<File::EffectTransfer> File::getBuildingEffects(QString name) {
    QJsonObject prop = getBuildingsProperties(name);
    QList<QString> effect = prop.value("effects").toObject().keys();
    std::vector<File::EffectTransfer> effets;
    for(qsizetype i = 0; i<effect.size();i++){
        EffectTransfer effetunique;
        effetunique.setEffectName(effect[i]);
        QJsonObject jsonEffect = prop.value("effects").toObject();
        QJsonArray param = jsonEffect.value(effect[i]).toArray();
        for (auto points: param){
            if (points.toInt()){
                effetunique.addAmount(points.toInt());
            }
            else{
                effetunique.addResType(points.toString());
            }
        }
        effets.insert(effets.end(),1,effetunique);
    }
    return effets;
}

std::vector<File::EffectTransfer> File::getProgressTokenEffects(QString name) {
    QJsonObject prop = getProgressTokenProperties(name);
    QList<QString> effect = prop.value("effects").toObject().keys();
    std::vector<File::EffectTransfer> effets;
    for(qsizetype i = 0; i<effect.size();i++){
        File::EffectTransfer effetunique;
        effetunique.setEffectName(effect[i]);
        QJsonObject jsonEffect = prop.value("effects").toObject();
        QJsonArray param = jsonEffect.value(effect[i]).toArray();
        for (auto points: param){
            if (points.toInt()){
                effetunique.addAmount(points.toInt());
            }
            else{
                effetunique.addResType(points.toString());
            }
        }
        effets.insert(effets.end(),1,effetunique);
    }
    return effets;
}

std::vector<File::EffectTransfer> File::getWonderEffects(QString name){
    QJsonObject prop = getWonderProperties(name);
    QList<QString> effect = prop.value("effects").toObject().keys();
    std::vector<File::EffectTransfer> effets;
    for(qsizetype i = 0; i<effect.size();i++){
        EffectTransfer effetunique;
        effetunique.setEffectName(effect[i]);
        QJsonObject jsonEffect = prop.value("effects").toObject();
        QJsonArray param = jsonEffect.value(effect[i]).toArray();
        for (auto points: param){
            if (points.toInt()){
                effetunique.addAmount(points.toInt());
            }
            else{
                effetunique.addResType(points.toString());
            }
        }
        effets.insert(effets.end(),1,effetunique);
    }
    return effets;
}

std::ostream& operator<<(std::ostream& os, File::EffectTransfer& effet){
    os << "Effet: " << effet.getEffect().toStdString() << "| Parametres: ";
    for(QString element : effet.getResType())
    {
        os<<" "<<element.toStdString()<<" ";
    }
    for(int element : effet.getAmount())
    {
        os<<" "<<element<<" ";
    }
    return os;
}

std::vector<std::pair<QString,int>> File::getCost(QString name){

    QJsonObject building = getBuildingsProperties(name);
    QJsonObject Wonder = getWonderProperties(name);
    QJsonObject PT = getProgressTokenProperties(name);

    std::vector<std::pair<QString,int>> cost;

    if (!building.empty()) {
        QJsonObject LCost = building.value("cost").toObject();
        for (auto points:LCost.keys()){
            cost.insert(cost.end(),1,std::make_pair(points,LCost.value(points).toInt()));
        }
    }
    else if (!Wonder.empty()){
        QJsonObject LCost = Wonder.value("cost").toObject();
        for (auto points:LCost.keys()){
            cost.insert(cost.end(),1,std::make_pair(points,LCost.value(points).toInt()));
        }
    }
    else if (!PT.empty()){
        QJsonObject LCost = PT.value("cost").toObject();
        for (auto points:LCost.keys()){
            cost.insert(cost.end(),1,std::make_pair(points,LCost.value(points).toInt()));
        }
    }
    return cost;
}
