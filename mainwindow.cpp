#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loginManager = new LoginManager();
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    QString username = ui->txtUserName->text();
    QString password = ui->txtPassWord->text();

    loginManager->Login(username, password);

}

void MainWindow::on_btnRegister_clicked()
{
    QString username = ui->txtUserName->text();
    QString password = ui->txtPassWord->text();

    loginManager->RegisterUser(username, password);
}
