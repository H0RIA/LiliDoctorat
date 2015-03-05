#include "MainWindow.h"
#include "DBManager.h"
#include <QMessageBox>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBManager::instance();

    MainWindow w;
    w.show();

    return a.exec();
}
