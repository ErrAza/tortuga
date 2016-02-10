#include "scene.h"

Scene::Scene(QString name, int frameCount, double duration) : _name(name), _frameCount(frameCount), _duration(duration)
{

}

QString Scene::GetName()
{
    return _name;
}

void Scene::SetName(QString name)
{
    _name = name;
}

int Scene::GetFrameCount()
{
    return _frameCount;
}

void Scene::SetFrameCount(int frameCount)
{
    _frameCount = frameCount;
}

double Scene::GetDuration()
{
    return _duration;
}

void Scene::SetDuration(double duration)
{
    _duration = duration;
}

User Scene::GetKFAnimator()
{
    return *_keyFrameAnimator;
}

void Scene::SetKFAnimator(User *kfAnimator)
{
    _keyFrameAnimator = kfAnimator;
}

User Scene::GetTWAnimator()
{
    return *_TweenAnimator;
}

void Scene::SetTWAnimator(User *twAnimator)
{
    _TweenAnimator = twAnimator;
}

bool Scene::IsHalfResRendered()
{
    return _isHalfResRendered;
}

void Scene::SetHalfResRendered(bool yes)
{
    _isHalfResRendered = yes;
}

bool Scene::IsFullResRendered()
{
    return _isFullResRendered;
}

void Scene::SetFullResRendered(bool yes)
{
    _isFullResRendered = yes;
}

QString Scene::GetNote()
{
    return _note;
}

void Scene::SetNote(QString note)
{
    _note = note;
}
