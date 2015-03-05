#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent),
        m_DockTab(nullptr),
        m_Filters(nullptr),
        m_Favorites(nullptr),
        m_MainWidget(this),
        m_Menu(this),
        m_MenuFile(nullptr),
        m_MenuEdit(nullptr),
        m_MenuAbout(nullptr),
        m_ActionFileNew(nullptr),
        m_ActionFileSave(nullptr),
        m_ActionFileExit(nullptr),
        m_ActionAboutAbout(nullptr),
        m_ActionDockHouses(nullptr),
        m_ActionDockPriests(nullptr),
        m_ActionDockLanguages(nullptr),
        m_ActionDockCounties(nullptr),
        m_ActionDockDeaneries(nullptr),
        m_ActionDockLocalities(nullptr),
        m_ActionDockImages(nullptr),
        m_ActionDockTaxes(nullptr)

{
    setMenuBar(&m_Menu);

    createMenus();
    createDockBar();
    createGlobalShortcuts();

    setCentralWidget(&m_MainWidget);
}

MainWindow::~MainWindow()
{
}

void
MainWindow::createDockBar()
{
    m_DockTab = new QToolBar(this);
    m_DockTab->setFloatable(false);
    m_DockTab->setAllowedAreas(Qt::LeftToolBarArea);
    m_DockTab->setFloatable(false);
    m_DockTab->setOrientation(Qt::Vertical);
    m_DockTab->setMovable(false);
    m_DockTab->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    m_ActionDockHouses = new QAction(m_DockTab);
    m_ActionDockHouses->setText("Houses");
    QIcon iconHouse(":/images/icon-house.png");
    m_ActionDockHouses->setIcon(iconHouse);
    m_DockTab->addAction(m_ActionDockHouses);

    m_ActionDockPriests = new QAction(m_DockTab);
    QIcon iconPriest(":/images/icon-priest.png");
    m_ActionDockPriests->setText("Priests");
    m_ActionDockPriests->setIcon(iconPriest);
    m_DockTab->addAction(m_ActionDockPriests);

    m_ActionDockLanguages = new QAction(m_DockTab);
    QIcon iconLanguage(":/images/icon-language.png");
    m_ActionDockLanguages->setText("Languages");
    m_ActionDockLanguages->setIcon(iconLanguage);
    m_DockTab->addAction(m_ActionDockLanguages);

    m_ActionDockCounties = new QAction(m_DockTab);
    QIcon iconRegion(":/images/icon-region.png");
    m_ActionDockCounties->setText("Counties");
    m_ActionDockCounties->setIcon(iconRegion);
    m_DockTab->addAction(m_ActionDockCounties);

    m_ActionDockDeaneries = new QAction(m_DockTab);
    QIcon iconDeanery(":/images/icon-deanery.png");
    m_ActionDockDeaneries->setText("Deaneries");
    m_ActionDockDeaneries->setIcon(iconDeanery);
    m_DockTab->addAction(m_ActionDockDeaneries);

    m_ActionDockLocalities = new QAction(m_DockTab);
    QIcon iconLocality(":/images/icon-locality.png");
    m_ActionDockLocalities->setText("Localities");
    m_ActionDockLocalities->setIcon(iconLocality);
    m_DockTab->addAction(m_ActionDockLocalities);

    m_ActionDockImages = new QAction(m_DockTab);
    QIcon iconGallery(":/images/icon-gallery.png");
    m_ActionDockImages->setText("Images");
    m_ActionDockImages->setIcon(iconGallery);
    m_DockTab->addAction(m_ActionDockImages);

    m_ActionDockTaxes = new QAction(m_DockTab);
    QIcon iconTaxes(":/images/icon-money.png");
    m_ActionDockTaxes->setText("Taxes");
    m_ActionDockTaxes->setIcon(iconTaxes);
    m_DockTab->addAction(m_ActionDockTaxes);

    addToolBar(Qt::LeftToolBarArea, m_DockTab);
}

void
MainWindow::createMenus()
{
    createFileMenu();
    createEditMenu();
    createAboutMenu();
}

void
MainWindow::createFileMenu()
{
    m_MenuFile = new QMenu();
    m_MenuFile->setTitle("File");

    m_ActionFileNew = new QAction(m_MenuFile);
    m_ActionFileNew->setText("New");

    m_ActionFileSave = new QAction(m_MenuFile);
    m_ActionFileSave->setText("Save");

    m_ActionFileExit = new QAction(m_MenuFile);
    m_ActionFileExit->setText("Exit");

    m_MenuFile->addAction(m_ActionFileNew);
    m_MenuFile->addAction(m_ActionFileSave);
    m_MenuFile->addSeparator();
    m_MenuFile->addAction(m_ActionFileExit);

    m_Menu.addMenu(m_MenuFile);
}

void
MainWindow::createEditMenu()
{
    m_MenuEdit = new QMenu();
    m_MenuEdit->setTitle("Edit");

    m_Menu.addMenu(m_MenuEdit);
}

void
MainWindow::createAboutMenu()
{
    m_MenuAbout = new QMenu();
    m_MenuAbout->setTitle("About");
    m_MenuAbout->addAction("LCP...");

    m_Menu.addMenu(m_MenuAbout);
}

void
MainWindow::createGlobalShortcuts()
{
    // TODO
}
