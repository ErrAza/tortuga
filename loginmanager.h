#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QMap>
#include <QMessageBox>
#include "user.h"

class LoginManager : public QMap<QString, User*>
{
public:
    LoginManager();
    void RegisterUser(QString username, QString password);
    void Login(QString username, QString password);
    int GetListSize();
    const User* retrieveProfile(QString username);

private:
    QMap<QString, User*> *userDB;
};

#endif // LOGINMANAGER_H
