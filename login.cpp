#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
    , db(Database())
{
    ui->setupUi(this);
    connect(ui->LoginButton, &QPushButton::clicked, this, &Login::on_LoginButton_clicked);
    connect(ui->SignUpButton, &QPushButton::clicked, this, &Login::on_SignUpButton_clicked);
}

Login::~Login()
{
    delete ui;
}

void Login::on_SignUpButton_clicked() {
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if (db.registerUser(username, password)) {
        QMessageBox::information(this, "注册成功", "您已成功注册！");
    } else {
        QMessageBox::warning(this, "注册失败", "注册失败，请重试！");
    }
}

void Login::on_LoginButton_clicked() {
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if (db.loginUser(username, password)) {
        emit loginSuccess();
    } else {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误，请重试！");
    }
}

void Login::on_CancelButton_clicked()
{
    qApp->quit();
}

