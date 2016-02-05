#include "dbinterface.h"

dbinterface::dbinterface()
{
    _db = QSqlDatabase::database();
}

const void dbinterface::Insert(QString tableName, QString values[])
{
    QSqlQuery query;
    QString div = "'";
    QString command = QString("INSERT INTO %1 VALUES (%2, %3, %4")



    for (int i = 0; i < values[].size(); i++)
    {

    }

    query.exec("INSERT INTO " + tableName + " VALUES (" + div + values[0] + div + ", " + div + values[1] + div + ", " + div + values[2] + div + ");");
}


