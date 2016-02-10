#include "mainmenu.h"


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::MainMenu(QWidget *parent, LoginManager *loginManager) : QMainWindow(parent), ui(new Ui::MainMenu), m_loginManager(loginManager)
{
    ui->setupUi(this);

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_actionAdd_Project_triggered()
{
    if (m_loginManager->currentUser == NULL || m_loginManager->currentUser->projects == NULL)
    {
        QMessageBox::warning(0, "Error", "No User!");
    }
    else
    {
        CreateAndShowAddProjectWidget();
    }
}

void MainMenu::CreateAndShowAddProjectWidget()
{
    NewProjectDialog *dialog = new NewProjectDialog(0, m_loginManager);
    dialog->show();
}

void MainMenu::projectSaveClicked()
{

}

