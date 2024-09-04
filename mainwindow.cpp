#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    loginWidget = new Login(this);
    gameWidget = new Game(this);

    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(gameWidget);

    connect(loginWidget, &Login::loginSuccess, this, &MainWindow::onLoginSuccess);/*启动游戏窗口*/
    connect(loginWidget, &Login::loginSuccess, gameWidget, &Game::startGameTimer); /*启动计时器*/
    connect(gameWidget, &Game::gameFinished, this, &MainWindow::onGameFinished);/*返回登录UI*/

    stackedWidget->setCurrentWidget(loginWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginSuccess() {
    stackedWidget->setCurrentWidget(gameWidget);
    onWindowSizeChanged(640, 480);
}

void MainWindow::onGameFinished() {
    stackedWidget->setCurrentWidget(loginWidget);
    onWindowSizeChanged(400, 260);
}

void MainWindow::onWindowSizeChanged(int width, int height) {
    setFixedSize(width, height);
}
