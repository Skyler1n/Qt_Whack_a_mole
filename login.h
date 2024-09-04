#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void loginSuccess();

private slots:
    void on_LoginButton_clicked();
    void on_SignUpButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::Login *ui;
    Database db;
};

#endif
