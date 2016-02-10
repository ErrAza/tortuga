#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include "loginmanager.h"
#include "ui_mainmenu.h"

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    explicit NewProjectDialog(QWidget *parent, LoginManager *loginManager);
    ~NewProjectDialog();
    LoginManager *m_loginManager;
    bool RetrieveProject(QString title, QString password);

private:
    Ui::NewProjectDialog *ui;

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();
};

#endif // NEWPROJECTDIALOG_H
