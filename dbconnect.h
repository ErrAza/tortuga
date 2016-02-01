#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QString>
#include <QtSql/QSqlDatabase>

///
/// \brief The DBConnect class that handles the SqlDatabase Connections
///

class DBConnect
{
public:
    DBConnect(QString user, QString pass);
    void createConnections();
    const bool connectionStatus();

private:
    QString _user;
    QString _pass;
    const QString _dbURL;
    QSqlDatabase *_tortugaDB;
    bool connected;
};

#endif // DBCONNECT_H
