#include "dbconnect.h"
#include <QtSql/QSql>
#include <QSqlQuery>

DBConnect::DBConnect(QString user, QString pass) : _user(user), _pass(pass)
{
    _dbURL = "/home/sean/Documents/Qt Projects/Project Tortuga/tortuga/tortugaDB.sqlite";
}

void DBConnect::createConnections()
{
    connected = false;
    _tortugaDB = QSqlDatabase::addDatabase("QSQLITE");
    _tortugaDB.setHostName("localhost");
    _tortugaDB.setDatabaseName(_dbURL);
    _tortugaDB.open();
    connected = _tortugaDB.open();
}

bool DBConnect::connectionStatus()
{
    connected = _tortugaDB.open();
    return connected;
}
