#include "mainwindow.h"
#include <QApplication>
#include "dbconnect.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DBConnect dbHandler("Sean", "password");
    dbHandler.createConnections();
    if (dbHandler.connectionStatus())
    {
       QMessageBox::information(0, "Tortuga Connection", "true");
    }

    return a.exec();
}
