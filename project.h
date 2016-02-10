#ifndef PROJECT_H
#define PROJECT_H
#include <QString>
#include <scene.h>
#include <QVector>
#include <QVariant>

class Scene;

class Project
{
public:
    Project(QString title, QString description, int fps);
    QString GetTitle();
    void SetTitle(QString title);
    QString GetDesc();
    void SetDesc(QString desc);
    int GetFrameRate();
    void SetFrameRate(int fps);
    QVector<Scene> * scenes;
    QString GetPassword();
    void SetPassword(QString password);
    void SetClient(QString client);
    QString GetClient();
    int _sceneCount;

private:
    QString _title;
    QString _description;
    int _fps;
    QString _password;
    QString _client;
    QString _status;


};

#endif // PROJECT_H
