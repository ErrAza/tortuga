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
                QMessageBox::warning(0, "Login Failure", "Login password incorrect. " + QString::number(count) + " attempts remaining.");

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
        User *  newUser = new User(username, password);
        userDB->insert(username, newUser);
        newUser->ResetLoginFailCount();
        QMessageBox::information(0, "Success", "User: " + username + " created successfully.");
    }
    else
    {
        QMessageBox::warning(0, "Failed", "User: " + username + " already exists.");
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
