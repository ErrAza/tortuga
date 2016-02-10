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
    connect(ui->txtPassWord, SIGNAL(returnPressed()), this, SLOT(on_btnLogin_clicked())); 

    ui->txtUserName->setFocus();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Tortuga", tr("Are you sure?\n"), QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes)
    {
        event->ignore();
    } else
    {
        if (loginManager->currentUser == NULL || loginManager->currentUser->_loggedIn == false)
        {
            event->accept();
        }
        else
        {
            loginManager->SetUserLoggedOut(loginManager->currentUser);
            event->accept();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM users");
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(0, Qt::Horizontal, tr("Password"));
    model->setHeaderData(0, Qt::Horizontal, tr("Type"));

    QString username = ui->txtUserName->text();
    QString password = ui->txtPassWord->text();

    bool success = loginManager->Login(username, password);

    if (success)
    {
        MainMenu *menu = new MainMenu(0, loginManager);
        menu->show();
        this->destroy();
        //QTableView *view = new QTableView;
        //view->setWindowTitle("Users");
        //view->resizeColumnsToContents();
        //view->resizeRowsToContents();
        //view->setModel(model);
        //view->show();
        //view->resize(640, 480);
    }
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

void MainWindow::on_txtPassWord_returnPressed()
{

}
