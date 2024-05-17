#include "SevenWonderUI.h"
#include "ui_SevenWonderUI.h"


SevenWonderUI::SevenWonderUI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SevenWonderUI)
{
    ui->setupUi(this);

}

SevenWonderUI::~SevenWonderUI()
{
    delete ui;
}
