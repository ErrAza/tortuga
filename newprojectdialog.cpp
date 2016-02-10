#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include <QMessageBox>
#include <QDebug>

NewProjectDialog::NewProjectDialog(QWidget *parent, LoginManager *loginManager) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog), m_loginManager(loginManager)
{
    ui->setupUi(this);
    ui->txtTitle->setFocus();
}

NewProjectDialog::NewProjectDialog(QWidget *parent) : QDialog(parent), ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

bool NewProjectDialog::RetrieveProject(QString title, QString password)
{
        bool success = false;

        if (m_loginManager->projectDB->contains(title))
        {
             if (m_loginManager->projectDB->value(title)->GetPassword() == password)
             {
                    success = true;
             }
        }
        return success;
}

void NewProjectDialog::on_btnSave_clicked()
{
    QString title = ui->txtTitle->text();
    QString password = ui->txtPassword->text();

    if (RetrieveProject(title, password))
    {
        m_loginManager->currentUser->projects->append(m_loginManager->projectDB->value(title));
        QMessageBox::information(0, "Success", "Project: " + title + " added.");
    }
    else if (!m_loginManager->projectDB->contains(title))
    {
        QMessageBox::warning(0, "Failed", "Project Does Not Exist");
    }
    else
    {
        QMessageBox::warning(0, "Failed", "Incorrect Password Entered");
    }
}

void NewProjectDialog::on_btnCancel_clicked()
{
    this->close();
}
