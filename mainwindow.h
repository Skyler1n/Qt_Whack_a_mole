#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "login.h"
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onLoginSuccess();
    void onGameFinished();
    void onWindowSizeChanged(int width, int height);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    Login *loginWidget;
    Game *gameWidget;
};

#endif
