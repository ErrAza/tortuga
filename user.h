#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(QString name, QString password);
    QString GetUserName();
    void SetUserName(QString newName);
    QString GetPassWord();
    void SetPassWord(QString password);
    int GetLoginFailCount();
    void ResetLoginFailCount();
    void AddFailedLoginAttempt();
    bool GetLockedStatus();

private:
    QString _userName;
    QString _passWord;
    int _loginFailureCounter;
    bool _locked;
};

#endif // USER_H
