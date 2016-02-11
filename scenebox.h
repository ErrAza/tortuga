#ifndef SCENEBOX_H
#define SCENEBOX_H

#include <QObject>
#include <QWidget>
#include <QGroupBox>

class SceneBox : public QWidget
{
    Q_OBJECT
public:
    explicit SceneBox(QWidget *parent = 0);

private:
    QGroupBox *sceneBox;

signals:

public slots:
};

#endif // SCENEBOX_H
