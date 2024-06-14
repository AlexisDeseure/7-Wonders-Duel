#include "EndGamePopUp.h"

EndGamePopUp::EndGamePopUp(QWidget *parent,Player* winner) : QWidget(parent) {
    QSize size = parent->size();
    QRect ALL_size = QRect({0,0},size);
    this->setGeometry(ALL_size);
    qDebug() << ALL_size;
    qDebug() << parent->size();
    QVBoxLayout* alignement = new QVBoxLayout(this);
    alignement->setGeometry(ALL_size);

    this->setStyleSheet("QLabel{font-size: 25pt; font-color: }");
    this->setStyleSheet("{background-color: #ea6346;}");
    QString winner_name;
    qDebug()<<alignement->geometry();
    if (winner != nullptr) {
        winner_name = QString::fromStdString(winner->getName());
        WINNER = new QLabel(winner_name+" won, CONGRATULATIONS");

    } else {
        winner_name = "EGALITE";
        WINNER = new QLabel(winner_name);
    }
    WINNER->setFixedSize(parent->size());
    time = new QLabel;
    time->setText("Il reste "+QString::number(i)+" secondes avant la fermeture.");
    alignement->addWidget(WINNER,Qt::AlignCenter);
    alignement->addWidget(time);
    QTimer* timer = new QTimer;
    timer->start(9000);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(quitting()));
}

void EndGamePopUp::quitting(){
    if (i>0){
        i--;
        time->setText(QString::number(i)+" secondes avant la fermeture.");
    } else if(i<=0){
    qDebug() << "CLOSING";
    this->close();
    emit endGame();
    delete this;
    }
}
