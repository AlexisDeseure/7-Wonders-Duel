#ifndef SEVENWONDERUI_H
#define SEVENWONDERUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SevenWonderUI;
}
QT_END_NAMESPACE

class SevenWonderUI : public QMainWindow
{
    Q_OBJECT

public:
    SevenWonderUI(QWidget *parent = nullptr);
    ~SevenWonderUI();

private:
    Ui::SevenWonderUI *ui;
};
#endif // SEVENWONDERUI_H
