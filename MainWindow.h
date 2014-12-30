#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CentralWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    protected:
        QToolBar* m_DockTab;
        QDockWidget* m_Filters;
        QDockWidget* m_Favorites;
        CentralWindow m_MainWidget;
        QMenuBar m_Menu;
};

#endif // MAINWINDOW_H
