#include "game.h"
#include "ui_game.h"
#include <QRandomGenerator>

Game::Game(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game)
    , score(0)
    , count(0)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::updateHole);/*连接timeout sig到更新地鼠位置的slot函数*/

    holes.push_back(ui->pushButton);
    holes.push_back(ui->pushButton_2);
    holes.push_back(ui->pushButton_3);
    holes.push_back(ui->pushButton_4);
    holes.push_back(ui->pushButton_5);
    holes.push_back(ui->pushButton_6);
    holes.push_back(ui->pushButton_7);
    holes.push_back(ui->pushButton_8);
    holes.push_back(ui->pushButton_9);

    for (auto &hole : holes) {
        hole->setText("⭕");
        connect(hole, &QPushButton::clicked, this, &Game::on_pushButton_clicked);
    }
}

Game::~Game()
{
    delete ui;
}

void Game::startGameTimer() {
    count = 0;/*重置计数器*/
    timer->start(2000);/*启动timer，2s更新地鼠位置*/
}

void Game::updateHole() {
    if (count < 10) {
        int index = QRandomGenerator::global()->bounded(holes.size());
        holes[index]->setText("😊");
        QTimer::singleShot(2000, this, [this, index]() {
            holes[index]->setText("⭕");
        });
        count++;
    } else {
        timer->stop();
        QMessageBox::information(this, "游戏结束", "你的得分是: " + QString::number(score));
        emit gameFinished();
    }
}

void Game::on_pushButton_clicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton && clickedButton->text() == "😊") {
        score += 10;
        clickedButton->setText("⭕");
    }
}
