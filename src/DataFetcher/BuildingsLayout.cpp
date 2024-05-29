#include"BuildingsLayout.h"
#include"DeckElement.h"
#include"Building.h"


BuildingsLayout::BuildingsLayout(std::string file_path, int number_age){
    readAndInstanciate(file_path, number_age);
}

void BuildingsLayout::readAndInstanciate(std::string file_path, int number_age){
    QFile file(QString::fromStdString(file_path));
    if (!file.open(QIODevice::ReadOnly)){
        qDebug() << "Error opening file";
        return;
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    QJsonArray obj = doc.array();

    if(obj.size() != number_age){
        qDebug() << "Error in the number of age";
        return;
    }

    for (auto it : obj){
        QJsonArray age = it.toArray();
        std::vector<std::vector<DeckElement*>> age_layout;
        // parcourir les lignes à l'envers pour faciliter la création des liens
        for (auto it2 = age.end()-1; it2 != age.begin()-1; --it2){
            QJsonArray ligne = it2->toObject()["ligne"].toArray();
            std::vector<DeckElement*> ligne_layout;

            for (auto it3 : ligne){
                QJsonObject element = it3.toObject();
                DeckElement* de = new DeckElement();

                if (it2 != age.begin())
                    de->setVisible(element["display"].toBool());

                if (!element["left_son"].isNull()){
                    de->setLeftSon(age_layout[0][element["left_son"].toInt()-1]);
                    de->getLeftSon()->setRightFather(de);
                }

                if (!element["right_son"].isNull()){
                    de->setRightSon(age_layout[0][element["right_son"].toInt()-1]);
                    de->getRightSon()->setLeftFather(de);
                }
                ligne_layout.push_back(de);
            }
            //insérer en position 0 les éléments de la ligne
            age_layout.insert(age_layout.begin(), ligne_layout);
        }
        layout_each_age.push_back(age_layout);
    }
}

std::vector<std::vector<DeckElement*>>& BuildingsLayout::getAgeWithBuildings(int age, std::vector<Building*> buildings){
    std::vector<std::vector<DeckElement*>>& age_layout = layout_each_age[age-1];
    //iterator sur buildings
    std::vector<Building*>::iterator building = buildings.begin();
    for (auto ligne : age_layout){
        for (auto element : ligne){
            if (building == buildings.end()) {
                qDebug() << "Error in the number of buildings";
                return age_layout;
            }
            element->setBuilding(*building);
            building++;
        }
    }
    return age_layout;
}


