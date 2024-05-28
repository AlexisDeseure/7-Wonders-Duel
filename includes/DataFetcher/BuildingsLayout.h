#ifndef BUILDINGSLAYOUT_H
#define BUILDINGSLAYOUT_H

#include <vector>
#include <string>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QMainWindow>

class DeckElement;
class Building;

class BuildingsLayout{
private:
    std::vector<std::vector<std::vector<DeckElement*>>> layout_each_age;
public:
    BuildingsLayout(std::string file_path, int number_age);
    ~BuildingsLayout() = default;
    BuildingsLayout& operator=(const BuildingsLayout& b) = delete;
    BuildingsLayout(const BuildingsLayout& b) = delete;

    void readAndInstanciate(std::string file_path, int number_age);
    std::vector<std::vector<DeckElement*>>& getAgeWithBuildings(int age, std::vector<Building*>);

};
#endif // BUILDINGSLAYOUT_H
