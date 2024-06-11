#include "File.h"
#include "RessourceCost.h"
#include "Game.h"
#include "Ressource.h"
#include"GameParameters.h"

File::File(std::string name) : file_path(QString::fromStdString(name)), file(readFile()) {};

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
            throw JsonReadException("Error in Json Data: " + JsonError.errorString());
        }
        else {
            // qDebug() << "No error in Json";
            return Document;
        }
    }
    qDebug() << "Lecture Impossible";
    throw JsonReadException("Lecture Impossible");
    // return QJsonDocument();
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
    throw JsonReadException("Lecture Impossible");
    // return QJsonArray();
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
    throw JsonReadException("Lecture Impossible");
    // return QJsonArray();
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
    throw JsonReadException("Lecture Impossible");
    // return QJsonArray();
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
    for(std::string& element : effet.getResType())
    {
        os<<" "<<element<<" ";
    }
    for(int element : effet.getAmount())
    {
        os<<" "<<element<<" ";
    }
    return os;
}

std::vector<RessourceCost> File::getCost(QString name){

    QJsonObject building = getBuildingsProperties(name);
    QJsonObject Wonder = getWonderProperties(name);
    QJsonObject PT = getProgressTokenProperties(name);

    std::vector<RessourceCost> cost;
    if (!building.empty()) {
        QJsonObject LCost = building.value("cost").toObject();
        for (auto& points:LCost.keys()){
            cost.insert(cost.end(),1,RessourceCost(LCost.value(points).toInt(),StringToRessourceType(points.toStdString())));
        }
        //RessourceCost(int number, RessourceType t) : amount(static_cast<unsigned int>(number)), type(t){};
        //RessourceType StringToRessourceType(std::string nom);
    }
    else if (!Wonder.empty()){
        QJsonObject LCost = Wonder.value("cost").toObject();
        for (auto& points:LCost.keys()){
            cost.insert(cost.end(),1,RessourceCost(LCost.value(points).toInt(),StringToRessourceType(points.toStdString())));
        }
    }
    else if (!PT.empty()){
        qDebug() << "Un Progress Token n'a pas d'attribut 'cost'";
    }

    return cost;
}

std::vector<std::pair<QString,QString>> File::getNames(){
    QJsonArray Lbuilding = listeBuildings();
    QJsonArray LWonder = listeWonder();
    QJsonArray LPT = listeProgressToken();

    std::vector<std::pair<QString,QString>> names ;

    for (auto points:Lbuilding){
        QString bname = points.toObject().value("name").toString();
        names.insert(names.end(),1,std::make_pair("Building",bname));
    }

    for (auto points:LWonder){
        QString Wname = points.toObject().value("name").toString();
        names.insert(names.end(),1,std::make_pair("Wonder",Wname));
    }

    for (auto points:LPT){
        QString PTname = points.toObject().value("name").toString();
        names.insert(names.end(),1,std::make_pair("Progress Token",PTname));
    }

    return names;
}

std::pair<QString,QString> File::getChaining(QString name){
    QJsonArray LBuilding = listeBuildings();
    for (auto points: LBuilding) {
        QString Bname = points.toObject().value("name").toString();
        if (Bname==name) {
            std::pair<QString,QString> chaining = std::make_pair(
                points.toObject().value("chainage_send").toString(),
                points.toObject().value("chainage_receive").toString()
            );
            return chaining;
        }
    }
    qDebug() << "Pas de bâtiments avec ce nom!";
    return std::make_pair(QString(), QString());
}

// QString File::getScientificSymbol(QString name){
//     QString Symbol;
//     QJsonArray LBuilding = listeBuildings();
//     for (auto points: LBuilding) {
//         QString Bname = points.toObject().value("name").toString();
//         if (Bname==name) {
//             Symbol = points.toObject().value("scientific_symbol").toString();
//             return Symbol;
//         }
//     }
//     qDebug() << "Pas de bâtiments avec ce nom!";
//     return QString();
// }

QString File::getColor(QString name){
    QString couleur;
    QJsonArray LBuilding = listeBuildings();
    for (auto points: LBuilding) {
        QString Bname = points.toObject().value("name").toString();
        if (Bname==name) {
            couleur = points.toObject().value("color").toString();
            return couleur;
        }
    }
    qDebug() << "Pas de bâtiments avec ce nom!";
    return QString();
}

int File::getAge(QString name){
    int age;
    QJsonArray LBuilding = listeBuildings();
    for (auto points: LBuilding) {
        QString Bname = points.toObject().value("name").toString();
        if (Bname==name) {
            age = points.toObject().value("age").toInt();
            return age;
        }
    }
    qDebug() << "Pas de bâtiments avec ce nom!";
    return 0;
}

int File::getDirectCost(QString name){
    int dc;
    QJsonArray LBuilding = listeBuildings();
    QJsonArray LWonder = listeWonder();
    for (auto points: LBuilding) {
        QString Bname = points.toObject().value("name").toString();
        if (Bname==name) {
            dc = points.toObject().value("direct_cost").toInt();

            return dc;
        }
    }
    for (auto points: LWonder) {
        QString Wname = points.toObject().value("name").toString();
        if (Wname==name) {
            dc = points.toObject().value("direct_cost").toInt();

            return dc;
        }
    }
    qDebug() << "Pas de bâtiments avec ce nom";
    return 0;
}
