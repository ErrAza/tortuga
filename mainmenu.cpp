#include "mainmenu.h"
#include <QGroupBox>


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::MainMenu(QWidget *parent, LoginManager *loginManager) : QMainWindow(parent), ui(new Ui::MainMenu), m_loginManager(loginManager)
{
    ui->setupUi(this);

    if (m_loginManager->currentUser->projects->size() > 0)
    {
        if (m_loginManager->currentUser->projects->size() == 1)
        {
                ui->tabWidget->setTabText(0, m_loginManager->currentUser->projects->at(0)->GetTitle());
        }
        else
        {
            ui->tabWidget->setTabText(0, m_loginManager->currentUser->projects->at(0)->GetTitle());
            for (int i = 0; i < m_loginManager->currentUser->projects->size() - 1; i++)
            {
                QString title = m_loginManager->currentUser->projects->at(i + 1)->GetTitle();
                QWidget *newTab = new QWidget(ui->tabWidget);
                ui->tabWidget->addTab(newTab, tr(title.toLatin1()));
            }
        }
        PopulateProjects();
    }
}

void MainMenu::PopulateProjects()
{
    for (int i = 0; i < m_loginManager->currentUser->projects->size(); i++)
    {
        for (int j = 0; j < m_loginManager->currentUser->projects->at(i)->_sceneCount; j++)
        {
            QWidget *newWidget = new QWidget();

        }
    }
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

