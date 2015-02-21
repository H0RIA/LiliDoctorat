#include "MainWindow.h"
#include "DBManager.h"
#include <QMessageBox>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBManager::instance();

    QMessageBox msg;

    msg.setIcon(QMessageBox::Critical);
    msg.setText("Error:\nPrea multa valoare!");
    msg.exec();

    MainWindow w;
    w.show();

    return a.exec();
}
