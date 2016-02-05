#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QMap>
#include <QMessageBox>
#include <QSqlQuery>
#include "user.h"
#include <cstdlib>
#include <string>

class LoginManager : public QMap<QString, User*>
{
public:
    LoginManager();
    void RegisterUser(QString username, QString password);
    void Login(QString username, QString password);
    int GetListSize();
    const User* retrieveProfile(QString username);
    QString Hash(QString results);
    QString ReverseHash(QString results);
    void AddUserToDB(User *user);

private:
    QMap<QString, User*> *userDB;
};

#endif // LOGINMANAGER_H
