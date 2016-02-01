#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "loginmanager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnLogin_clicked();

    void on_btnRegister_clicked();

private:
    Ui::MainWindow *ui;
    LoginManager *loginManager;

};

#endif // MAINWINDOW_H
