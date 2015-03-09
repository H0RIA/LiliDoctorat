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
        void createDockBar();
        void createMenus();
        void createFileMenu();
        void createEditMenu();
        void createAboutMenu();

        void createGlobalShortcuts();

    protected slots:
        void onDockItemTriggered(bool checked = false);

    protected:
        void uncheckAllDockItems(WindowType wndException);

    signals:
        void dockSelectWindow(WindowType wndType);

    protected:
        QToolBar* m_DockTab;
        QDockWidget* m_Filters;
        QDockWidget* m_Favorites;
        CentralWindow m_MainWidget;
        QMenuBar m_Menu;

        QMenu* m_MenuFile;
        QMenu* m_MenuEdit;
        QMenu* m_MenuAbout;

        QAction* m_ActionFileNew;
        QAction* m_ActionFileSave;
        QAction* m_ActionFileExit;
        QAction* m_ActionAboutAbout;

        QAction* m_ActionDockHouses;
        QAction* m_ActionDockPriests;
        QAction* m_ActionDockLanguages;
        QAction* m_ActionDockComunes;
        QAction* m_ActionDockCounties;
        QAction* m_ActionDockDeaneries;
        QAction* m_ActionDockLocalities;
        QAction* m_ActionDockImages;
        QAction* m_ActionDockTaxes;
};

#endif // MAINWINDOW_H
