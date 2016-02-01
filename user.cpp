#include "user.h"

User::User(QString user, QString password) : _userName(user), _passWord(password)
{

}

QString User::GetUserName()
{
    return _userName;
}

void User::SetUserName(QString newName)
{
    _userName = newName;
}

int User::GetLoginFailCount()
{
    return _loginFailureCounter;
}

void User::ResetLoginFailCount()
{
    _loginFailureCounter = 3;
}

void User::AddFailedLoginAttempt()
{
    _loginFailureCounter--;
}

bool User::GetLockedStatus()
{
    return _locked;
}

void User::SetPassWord(QString password)
{
    _passWord = password;
}

QString User::GetPassWord()
{
    return _passWord;
}
