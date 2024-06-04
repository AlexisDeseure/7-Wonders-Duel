#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H
#include <QWidget>
#include <vector>
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
