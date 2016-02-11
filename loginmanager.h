#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QMap>
#include <QMessageBox>
#include <QSqlQuery>
#include "user.h"
#include <cstdlib>
#include <string>
#include <QMessageBox>
#include <QVariant>
#include <QDate>
#include "project.h"

class LoginManager
{

public:
    LoginManager();
    void RegisterUser(QString username, QString password);
    bool Login(QString username, QString password);
    int GetListSize();
    const User* retrieveProfile(QString username);
    QString Hash(QString results);
    QString ReverseHash(QString results);
    void AddUserToDB(User *user);
    bool PasswordCheck(QString username, QString password);
    void SetUserLoggedIn(User *user);
    void SetUserLoggedOut(User *user);
    User *currentUser;
    QMap<QString, User*> *userDB;
    QMap<QString, Project*> *projectDB;
    void RetrieveUserProjects(QString name);
    void UpdateProjectUserTables();

private:

};

#endif // LOGINMANAGER_H
