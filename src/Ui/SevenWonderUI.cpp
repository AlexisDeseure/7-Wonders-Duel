#include "SevenWonderUI.h"
// #include "ui_sevenwonderui.h"
#include "ui_SevenWonderUI.h"
#include "File.h"

SevenWonderUI::SevenWonderUI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SevenWonderUI)
{
    ui->setupUi(this);
    File json;
    std::vector<File::EffectTransfer> effetB = json.getBuildingEffects("Port");
    std::vector<File::EffectTransfer> effetW = json.getWonderEffects("La Via Appia");
    std::vector<File::EffectTransfer> effetPT = json.getProgressTokenEffects("Agriculture");
    std::cout << "\n";
    for (size_t i = 0; i < effetB.size(); i++)
    {
        std::cout << effetB[i] << "\n";
    }
    std::cout << "\n";
    for (size_t i = 0; i < effetW.size(); i++)
    {
        std::cout << effetW[i] << "\n";
    }
    std::cout << "\n";
    for (size_t i = 0; i < effetPT.size(); i++)
    {
        std::cout << effetPT[i] << "\n";
    }
    std::cout << "\n";
    // std::vector<std::pair<QString,int>> cout = json.getCost("Chantier");
    // for (size_t i = 0; i<cout.size();i++){
    //     std::cout << cout[i].first.toStdString() << " " << cout[i].second << "\n";
}

SevenWonderUI::~SevenWonderUI()
{
    delete ui;
}
