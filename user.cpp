#include "user.h"

User::User(QString user, QString password) : _userName(user), _passWord(password)
{
    projects = new QVector<Project*>();
}

QString User::GetUserName()
{
    return _userName;
}

void User::SetUserName(QString newName)
{
    _userName = newName;
}

void User::SetPassWord(QString password)
{
    _passWord = password;
}

QString User::GetPassWord()
{
    return _passWord;
}

QString User::GetAuthType()
{
    return _type;
}

void User::SetAuthType(QString authType)
{
    _type = authType;
}
