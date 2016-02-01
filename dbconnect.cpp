#include "dbconnect.h"
#include <QtSql/QSql>
DBConnect::DBConnect(QString user, QString pass) : _user(user), _pass(pass)
{
    _dbURL = "tortuga.database.windows.net";
}

void DBConnect::createConnections()
{
    connected = false;
    _tortugaDB = new QSqlDatabase();
    _tortugaDB->addDatabase("QODBC");
    _tortugaDB->setHostName(_dbURL);
    _tortugaDB->setDatabaseName(_dbURL);
    _tortugaDB->setUserName(_user);
    _tortugaDB->setPassword(_pass);
    connected = _tortugaDB->open();
}

bool DBConnect::connectionStatus()
{
    connected = _tortugaDB->open();
    return connected;
}
