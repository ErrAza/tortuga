#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <loginmanager.h>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include "newprojectdialog.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    explicit MainMenu(QWidget *parent, LoginManager *loginManager);
    ~MainMenu();
    void CreateAndShowAddProjectWidget();

private:
    Ui::MainMenu *ui;
    LoginManager *m_loginManager;
    QWidget *widget;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QLineEdit *txtTitle;
    QLineEdit *txtPassword;

private slots:
    void on_actionAdd_Project_triggered();
    void projectSaveClicked();
};

#endif // MAINMENU_H
