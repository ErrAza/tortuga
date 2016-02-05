#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    dbHandler = new DBConnect("Sean", "jpxfkmse2-");
    dbHandler->createConnections();

    loginManager = new LoginManager();
    ui->setupUi(this);\

    connect(ui->actionTest_Connection, SIGNAL(triggered()), this, SLOT(on_actionTest_Connection_triggered()));
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

void MainWindow::on_actionTest_Connection_triggered()
{
    if (dbHandler->connectionStatus() == true)
    {
       QMessageBox::information(0, "Tortuga Connection Active", "Connected");
    }
}
