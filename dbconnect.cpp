#include "dbconnect.h"
#include <QtSql/QSql>
DBConnect::DBConnect(QString user, QString pass)
{
    _user = user;
    _pass = pass;


}

void DBConnect::createConnections()
{
    connected = false;
    _tortugaDB = new QSqlDatabase();
    _tortugaDB->addDatabase("QMYSQL");
    _tortugaDB->setHostName(_user);
    _tortugaDB->setDatabaseName(_dbURL);
    _tortugaDB->setUserName(_user);
    _tortugaDB->setPassword(_pass);
    connected = _tortugaDB->open();
}

bool DBConnect::connectionStatus()
{
    connected = _tortugaDB.open();
    return connected;
}
