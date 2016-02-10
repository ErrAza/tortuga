#include "project.h"

Project::Project(QString title, QString description, int fps ) : _title(title), _description(description), _fps(fps)
{
       scenes = new QVector<Scene>();
}

QString Project::GetClient()
{
    return _client;
}

void Project::SetClient(QString client)
{
    _client = client;
}

QString Project::GetPassword()
{
    return _password;
}

void Project::SetPassword(QString password)
{
    _password = password;
}

QString Project::GetDesc()
{
    return _description;
}

void Project::SetDesc(QString desc)
{
    _description = desc;
}

QString Project::GetTitle()
{
    return _title;
}

void Project::SetTitle(QString title)
{
    _title = title;
}

int Project::GetFrameRate()
{
    return _fps;
}

void Project::SetFrameRate(int fps)
{
    _fps = fps;
}
