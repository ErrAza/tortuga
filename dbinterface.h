#ifndef DBINTERFACE_H
#define DBINTERFACE_H
#include <QSql>
#include <QSqlDatabase>

class dbinterface
{
public:
    dbinterface();
    const void Insert(QString tableName, QString values[]);
    const void Remove(QString tableName);
private:
    QSqlDatabase *_db;
};

#endif // DBINTERFACE_H
