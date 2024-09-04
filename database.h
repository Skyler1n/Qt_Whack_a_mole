#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class Database {
public:
    Database();
    bool createConnection();
    bool createTable();
    bool registerUser(const QString &username, const QString &password);
    bool loginUser(const QString &username, const QString &password);
};

#endif
