#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QVector>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

public slots:
    void startGameTimer();
    void updateHole();
    void on_pushButton_clicked();

signals:
    void gameFinished();

private:
    Ui::Game *ui;
    QTimer *timer;
    int score;
    int count;
    QVector<QPushButton*> holes;
};

#endif
