#include "loginmanager.h"


LoginManager::LoginManager()
{
    userDB = new QMap<QString, User*>;
    projectDB = new QMap<QString, Project*>;

    QSqlQuery userQuery("SELECT * FROM users");
    QSqlQuery projectQuery("SELECT * FROM projects");

    while (userQuery.next())
    {
        QString name = userQuery.value(0).toString();
        QString pw = userQuery.value(1).toString();
        QString type = userQuery.value(2).toString();

        User *user = new User(name, pw);
        user->SetAuthType(type);

        userDB->insert(name, user);
    }

    while (projectQuery.next())
    {
        QString title = projectQuery.value(0).toString();
        QString desc = projectQuery.value(1).toString();
        int frameRate = projectQuery.value(2).toInt();
        int sceneCount = projectQuery.value(3).toInt();
        QString client = projectQuery.value(4).toString();
        QString password = projectQuery.value(5).toString();

        Project *project = new Project(title, desc, frameRate);
        project->SetClient(client);
        project->SetPassword(password);
        project->_sceneCount = sceneCount;

        projectDB->insert(title, project);
        QString div = "'";
        QSqlQuery projectTable("CREATE TABLE " + title + "_animators" +  " (" + div + "user" + div + "varchar PRIMARY KEY  NOT NULL);");
        projectTable.exec();
    }

    UpdateProjectUserTables();
}

void LoginManager::UpdateProjectUserTables()
{
        QMap<QString, User*>::iterator i;
        for (i = userDB->begin(); i != userDB->end(); i++)
        {
            for (int j = 0; j < userDB->value(i.key())->projects->size(); j++)
            {
                QString command = "INSERT INTO " + userDB->value(i.key())->projects->at(j)->GetTitle() + "_animators" + "VALUES (" + "'" + i.key() + "');";
                QSqlQuery query;
                query.exec(command);
            }
        }
}

void LoginManager::RetrieveUserProjects(QString name)
{
     QSqlQuery projQuery("SELECT * FROM " + name + "_projects");
     while (projQuery.next())
     {
         QString title = projQuery.value(0).toString();
         currentUser->projects->append(projectDB->value(title));
     }
}


bool LoginManager::PasswordCheck(QString username, QString password)
{
    bool success = false;

    if(userDB->contains(username))
    {
        if(userDB->value(username)->GetPassWord() == password)
        {
            success = true;
        }
    }

    return success;

}

void LoginManager::SetUserLoggedIn(User *user)
{
    user->_loggedIn = true;
    QString date = QDate::currentDate().toString();
    QString time = QTime::currentTime().toString();
    QString div = "'";
    QString command = "UPDATE users SET lastlogin=" + div + date + " / " + time + div + "WHERE name=" + div + user->GetUserName() + div;
    QSqlQuery query;
    query.exec(command);
    currentUser = user;
}

void LoginManager::SetUserLoggedOut(User *user)
{
    user->_loggedIn = false;
    QString date = QDate::currentDate().toString();
    QString time = QTime::currentTime().toString();
    QString div = "'";
    QString command = "UPDATE users SET lastlogin=" + div + date + " / " + time + div + "WHERE name=" + div + user->GetUserName() + div;
    QSqlQuery query;
    query.exec(command);
}

bool LoginManager::Login(QString username, QString password)
{
        bool success = false;

        if(PasswordCheck(username, password))
        {
            //Login Procedure Success
            QMessageBox::information(0, "Login Success", "User: " + username + " logged in successfully");
            SetUserLoggedIn(userDB->value(username));
            RetrieveUserProjects(username);
            success = true;
        }
        else
        {
            //Login Procedure Failed
             QMessageBox::warning(0, username, "Login password incorrect.");
        }

    return success;
}

void LoginManager::RegisterUser(QString username, QString password)
{
    if (retrieveProfile(username) == NULL)
    {
        User *  newUser = new User(username, password);
        userDB->insert(username, newUser);
        AddUserToDB(newUser);
        QString div = "'";
        QSqlQuery createUserTable("CREATE TABLE " + div + username.toLower() + "_projects" + div + " (" + div + "project_name" + div + "varchar PRIMARY KEY  NOT NULL);");
        createUserTable.exec();
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
    QString div = "'";
    name = user->GetUserName();
    password = user->GetPassWord();
    type = "animator";
    int projectCount = 0;

    QSqlQuery query;
    QString command = "INSERT INTO users VALUES (" + div + name + div + ", " + div + password + div + ", " + div + type + div + ", "  + div + QDate::currentDate().toString() + div + ", " + div + QString::number(projectCount) + div + ");";
    query.exec(command);
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
