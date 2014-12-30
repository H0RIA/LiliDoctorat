#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent),
        m_DockTab(nullptr),
        m_Filters(nullptr),
        m_Favorites(nullptr),
        m_MainWidget(this),
        m_Menu(this)
{
    m_Menu.addAction("LiliRulz");
    setMenuBar(&m_Menu);
    setCentralWidget(&m_MainWidget);
}

MainWindow::~MainWindow()
{

}
