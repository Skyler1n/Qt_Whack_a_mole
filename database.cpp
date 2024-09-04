#include "database.h"

Database::Database() {
    createConnection();
    createTable();
}

bool Database::createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("game.db");
    return db.open();
}

bool Database::createTable() {
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT)");
    return query.isActive();
}

bool Database::registerUser(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    return query.exec();
}

bool Database::loginUser(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);
    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}
