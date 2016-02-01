#include "mainwindow.h"
#include <QApplication>
#include "dbconnect.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    DBConnect dbHandler("Sean", "jpxfkmse2-");
    dbHandler.createConnections();

    if (dbHandler.connectionStatus() == true)
    {
       QMessageBox::information(0, "Tortuga Connection", "Connected");
    }

    return a.exec();
}
