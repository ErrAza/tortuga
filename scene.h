#ifndef SCENE_H
#define SCENE_H
#include <user.h>
#include <project.h>

class User;

class Scene
{
public:
    Scene(QString name, int frameCount, double duration);
    QString GetName();
    void SetName(QString name);
    int GetFrameCount();
    void SetFrameCount(int frameCount);
    double GetDuration();
    void SetDuration(double duration);
    User GetKFAnimator();
    void SetKFAnimator(User *kfAnimator);
    User GetTWAnimator();
    void SetTWAnimator(User *twAnimator);
    bool IsHalfResRendered();
    void SetHalfResRendered(bool yes);
    bool IsFullResRendered();
    void SetFullResRendered(bool yes);
    QString GetNote();
    void SetNote(QString note);

private:
    QString _name;
    int _frameCount;
    double _duration;
    User *_keyFrameAnimator;
    User *_TweenAnimator;
    bool _isHalfResRendered;
    bool _isFullResRendered;
    QString _note;
};

#endif // SCENE_H
