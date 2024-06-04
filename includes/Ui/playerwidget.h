#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H
#include <QWidget>
#include <vector>

/*
Make fake widgets to show when selecting a card from another player ?
Also considering switching player widgets between each turn
*/

class PlayerWidget : public QWidget{
public:
    PlayerWidget(QWidget *parent = nullptr);
    ~PlayerWidget() = default;

    //Player& getplayer const(){return player;};
private:
    PlayerWidget(const PlayerWidget& widget) = delete;
    //Player player;
    //vector<BuildingWidgets*> buildings;
    //std::vector<ProgressTokenWidgets*> progress_Tokens;
    //std::vector<RessourceWidgets> ressources;
    //MoneyWidget *money;

};

#endif // PLAYERWIDGET_H
