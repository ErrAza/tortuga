#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>
#include "project.h"

class Project;

class User
{
public:
    User(QString name, QString password);
    QString GetUserName();
    void SetUserName(QString newName);
    QString GetPassWord();
    void SetPassWord(QString password);
    void SetAuthType(QString authType);
    QString GetAuthType();
    bool _loggedIn;
    QVector<Project*> *projects;

private:
    QString _userName;
    QString _passWord;
    QString _type;




};

#endif // USER_H
