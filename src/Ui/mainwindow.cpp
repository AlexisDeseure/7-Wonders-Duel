// #include "mainwindow.h"
// #include "ui_mainwindow.h"

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
//     , gameWindow(nullptr)
// {
//     ui->setupUi(this);

//     connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startNewGame);
//     connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadGame);
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
//     if (gameWindow) {
//         delete gameWindow;
//     }
// }

// void MainWindow::startNewGame()
// {
//     gameWindow = new GameWindow(this);
//     gameWindow->show();
//     this->hide();
// }

// void MainWindow::loadGame()
// {
//     // TODO:  load an existing game with the fonction game
// }

///NOT COMPILING
