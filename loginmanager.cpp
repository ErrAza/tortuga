#include "loginmanager.h"
#include <QMessageBox>


LoginManager::LoginManager()
{
    userDB = new QMap<QString, User*>;
}

void LoginManager::Login(QString username, QString password)
{
    if(retrieveProfile(username) != NULL)
    {
        int count = userDB->value(username)->GetLoginFailCount();
        if(userDB->value(username)->GetPassWord() == password)
        {
            //Login Procedure Success
            QMessageBox::information(0, "Login Success", "User: " + username + " logged in successfully");
            userDB->value(username)->ResetLoginFailCount();
        }
        else
        {
            //Login Procedure Failure
            if (userDB->value(username)->GetLoginFailCount() == 0)
            {
                //Incorrect Password Entered too many times
                QMessageBox::warning(0, "Account Locked", "Incorrect password entered too many times. Account is now soft-locked");
            }
            else
            {
                userDB->value(username)->AddFailedLoginAttempt();
                QMessageBox::warning(0, userDB->value(username)->GetPassWord(), "Login password incorrect. " + QString::number(count) + " attempts remaining.");

            }
        }
    }
    else
    {
        QMessageBox::warning(0, "User Not Found", "The user: " + username + " does not exist.");
    }
}

void LoginManager::RegisterUser(QString username, QString password)
{
    if (retrieveProfile(username) == NULL)
    {
        User *  newUser = new User(username, Hash(password));
        userDB->insert(username, newUser);
        newUser->ResetLoginFailCount();
        AddUserToDB(newUser);
        QMessageBox::information(0, "Success", "User: " + username + " created successfully.");
    }
    else
    {
        QMessageBox::warning(0, "Failed", "User: " + username + " already exists.");
    }
}

void LoginManager::AddUserToDB(User *user)
{
    QString name, password, type;
    QString divider = "'";
    name = user->GetUserName();
    password = user->GetPassWord();
    type = "animator";


    bool success;
    QSqlQuery query;
    QString command = "INSERT INTO users VALUES (" + divider + name + divider + ", " + divider + password + divider + ", " + divider + type + divider + ");";
    if (success = query.exec(command))
    {
        QMessageBox::warning(0, "Yes", "Yes");
    }
}

int LoginManager::GetListSize()
{
    return userDB->size();
}

const User* LoginManager::retrieveProfile(QString username)
{
    if (userDB->contains(username) && userDB->size() > 0)
    {
        return userDB->value(username);
    }
    else
    {
        return NULL;
    }
}

QString LoginManager::Hash(QString results)
{
    QString result;
    result.append(QString::fromLatin1(results.toLatin1().toHex()));

    std::string hashSwap;
    hashSwap = result.toStdString();

    std::rotate(hashSwap.begin(), hashSwap.begin() + 4, hashSwap.end());
    results = QString::fromStdString(hashSwap);
    return results;
}

QString LoginManager::ReverseHash(QString results)
{
    std::string hashSwap;
    hashSwap = results.toStdString();

    std::rotate(hashSwap.begin(), hashSwap.begin() - 4, hashSwap.end());
    results = QString::fromStdString(hashSwap);
    QByteArray text = QByteArray::fromHex(results.toLatin1());

    results = text.data();
    return results;
}
