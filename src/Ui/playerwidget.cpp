// #include "playerwidget.h"
// #include <QVBoxLayout>

// PlayerWidget::PlayerWidget(QWidget *parent) :
//     QWidget(parent)
// {
//     QVBoxLayout *layout = new QVBoxLayout(this);
    
//     resourcesLabel = new QLabel("Resources: 0", this);
//     victoryPointsLabel = new QLabel("Victory Points: 0", this);

//     layout->addWidget(resourcesLabel);
//     layout->addWidget(victoryPointsLabel);
// }

// void PlayerWidget::updateResources(const QMap<QString, int> &resources)
// {
//     QString resourcesText = "Resources: ";
//     for (auto it = resources.begin(); it != resources.end(); ++it) {
//         resourcesText += QString("%1: %2 ").arg(it.key()).arg(it.value());
//     }
//     resourcesLabel->setText(resourcesText);
// }

// void PlayerWidget::updateVictoryPoints(int points)
// {
//     victoryPointsLabel->setText(QString("Victory Points: %1").arg(points));
// }
