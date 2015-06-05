#include "UI/MainWindow.h"
#include "DBWrapper/DBManager.h"
#include <QMessageBox>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBWrapper::DBManager::instance();

    UI::MainWindow w;
    w.show();

    return a.exec();
}
