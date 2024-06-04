#ifndef MILITARYDECK_H
#define MILITARYDECK_H
#include <string>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

class MilitaryDeck : public QWidget //meant to be a singleton ?
{
public:
    MilitaryDeck(QWidget* Parent = nullptr,int p = 0);
    ~MilitaryDeck() = default;

    int getPawnPosition() const{return pawn_pos;};


private:
    int pawn_pos; //[-9;9], maybe make this the final pawn position for the entire game ?
    static std::string pawn_image_path;
    static std::string const deck_image_path;
    QLabel* pawn; //widget containing the image of the pawn, as to make it movable
    QLabel* deck;
    QGridLayout* pawn_grid; //contains 19 or 21 columns, can't remember which lol
    MilitaryDeck(const MilitaryDeck& widget) = delete;

    //button for military pawn
    QPushButton* b;
};

#endif // MILITARYDECK_H
