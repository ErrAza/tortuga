#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "loginmanager.h"
#include "dbconnect.h"
#include <QTableView>
#include <QSqlQueryModel>
#include <QCloseEvent>
#include <mainmenu.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);


private slots:
    void on_btnLogin_clicked();
    void on_btnRegister_clicked();
    void on_actionTest_Connection_triggered();
    void on_txtPassWord_returnPressed();

private:
    Ui::MainWindow *ui;
    LoginManager *loginManager;
    QAction *testConnection_action;
    DBConnect *dbHandler;

};

#endif // MAINWINDOW_H
