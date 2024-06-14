#include "EndGamePopUp.h"

EndGamePopUp::EndGamePopUp(QWidget *parent,Player* winner) : QWidget(parent) {

    QSize size = parent->size();
    QRect ALL_size = QRect({0,0},size);
    this->setGeometry(ALL_size);
    this->setStyleSheet("background-color: #ea6346;");
    QVBoxLayout* alignement = new QVBoxLayout(this);
    alignement->setGeometry(ALL_size);
    QString winner_name;
    if (winner != nullptr) {
        winner_name = QString::fromStdString(winner->getName());
        WINNER = new QLabel(winner_name+" won, CONGRATULATIONS");
    } else {
        winner_name = "EGALITE";
        WINNER = new QLabel(winner_name);
    }

    WINNER->setStyleSheet("font-size: 50pt");
    time = new QLabel;
    time->setText(QString::number(i)+" secondes avant la fermeture.");
    time->setAlignment(Qt::AlignCenter);
    time->setStyleSheet("font-size:20pt");
    time->setFont(QFont("Open Sans"));
    WINNER->setAlignment(Qt::AlignCenter);
    QTimer* timer = new QTimer;
    timer->start(9000);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(quitting()));
    alignement->addWidget(WINNER,Qt::AlignCenter);
    alignement->addWidget(time);
}

void EndGamePopUp::quitting(){
    if (i>1){
        i--;
        time->setText(QString::number(i)+" secondes avant la fermeture.");
    } else if(i<=1){
    qDebug() << "CLOSING";
    this->close();
    emit endGame();
    delete this;
    }
}
