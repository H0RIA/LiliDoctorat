#include "MainWindow.h"
#include "CentralWindow.h"

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
        m_ActionDockComunes(nullptr),
        m_ActionDockCounties(nullptr),
        m_ActionDockDeaneries(nullptr),
        m_ActionDockLocalities(nullptr),
        m_ActionDockImages(nullptr),
        m_ActionDockTaxes(nullptr)

{
    setMinimumSize(640, 480);
    setMenuBar(&m_Menu);

    createMenus();
    createDockBar();
    createGlobalShortcuts();

    setCentralWidget(&m_MainWidget);

    connect(this, SIGNAL(dockSelectWindow(WindowType)), &m_MainWidget, SLOT(onDockSelectWindow(WindowType)));
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
    m_ActionDockHouses->setCheckable(true);
    m_ActionDockHouses->setData((int)WindowType::Houses);
    m_ActionDockHouses->setText("Houses");
    QIcon iconHouse(":/images/icon-house.png");
    m_ActionDockHouses->setIcon(iconHouse);
    m_ActionDockHouses->setChecked(true);
    connect(m_ActionDockHouses, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
    m_DockTab->addAction(m_ActionDockHouses);

    m_ActionDockPriests = new QAction(m_DockTab);
    m_ActionDockPriests->setCheckable(true);
    m_ActionDockPriests->setData((int)WindowType::Priests);
    QIcon iconPriest(":/images/icon-priest.png");
    m_ActionDockPriests->setText("Priests");
    m_ActionDockPriests->setIcon(iconPriest);
    connect(m_ActionDockPriests, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
    m_DockTab->addAction(m_ActionDockPriests);

    m_ActionDockLanguages = new QAction(m_DockTab);
    m_ActionDockLanguages->setCheckable(true);
    m_ActionDockLanguages->setData((int)WindowType::Languages);
    QIcon iconLanguage(":/images/icon-language.png");
    m_ActionDockLanguages->setText("Languages");
    m_ActionDockLanguages->setIcon(iconLanguage);
    connect(m_ActionDockLanguages, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
    m_DockTab->addAction(m_ActionDockLanguages);

    m_ActionDockComunes = new QAction(m_DockTab);
    m_ActionDockComunes->setCheckable(true);
    m_ActionDockComunes->setData((int)WindowType::Comunes);
    QIcon iconComunes(":/images/icon-region.png");
    m_ActionDockComunes->setText("Comunes");
    m_ActionDockComunes->setIcon(iconComunes);
    connect(m_ActionDockComunes, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
    m_DockTab->addAction(m_ActionDockComunes);

    m_ActionDockCounties = new QAction(m_DockTab);
    m_ActionDockCounties->setCheckable(true);
    m_ActionDockCounties->setData((int)WindowType::Counties);
    QIcon iconRegion(":/images/icon-region.png");
    m_ActionDockCounties->setText("Counties");
    m_ActionDockCounties->setIcon(iconRegion);
    connect(m_ActionDockCounties, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
    m_DockTab->addAction(m_ActionDockCounties);

    m_ActionDockDeaneries = new QAction(m_DockTab);
    m_ActionDockDeaneries->setCheckable(true);
    m_ActionDockDeaneries->setData((int)WindowType::Deaneries);
    QIcon iconDeanery(":/images/icon-deanery.png");
    m_ActionDockDeaneries->setText("Deaneries");
    m_ActionDockDeaneries->setIcon(iconDeanery);
    connect(m_ActionDockDeaneries, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
    m_DockTab->addAction(m_ActionDockDeaneries);

    m_ActionDockLocalities = new QAction(m_DockTab);
    m_ActionDockLocalities->setCheckable(true);
    m_ActionDockLocalities->setData((int)WindowType::Localities);
    QIcon iconLocality(":/images/icon-locality.png");
    m_ActionDockLocalities->setText("Localities");
    m_ActionDockLocalities->setIcon(iconLocality);
    connect(m_ActionDockLocalities, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
    m_DockTab->addAction(m_ActionDockLocalities);

    m_ActionDockImages = new QAction(m_DockTab);
    m_ActionDockImages->setCheckable(true);
    m_ActionDockImages->setData((int)WindowType::Images);
    QIcon iconGallery(":/images/icon-gallery.png");
    m_ActionDockImages->setText("Images");
    m_ActionDockImages->setIcon(iconGallery);
    connect(m_ActionDockImages, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
    m_DockTab->addAction(m_ActionDockImages);

    m_ActionDockTaxes = new QAction(m_DockTab);
    m_ActionDockTaxes->setCheckable(true);
    m_ActionDockTaxes->setData((int)WindowType::Taxes);
    QIcon iconTaxes(":/images/icon-money.png");
    m_ActionDockTaxes->setText("Taxes");
    m_ActionDockTaxes->setIcon(iconTaxes);
    connect(m_ActionDockTaxes, SIGNAL(triggered(bool)), SLOT(onDockItemTriggered(bool)));
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
    connect(m_ActionFileNew, SIGNAL(triggered()), SLOT(onNewItem()));

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
MainWindow::onDockItemTriggered(bool checked)
{
    QAction* action = qobject_cast<QAction*>(sender());
    if(action == nullptr)
        return;

    if(checked == false){
        action->blockSignals(true);
        action->setChecked(true);
        action->blockSignals(false);
        return;
    }

    WindowType wndType = (WindowType)(action->data().toInt());

    uncheckAllDockItems((WindowType)wndType);

    emit dockSelectWindow(wndType);
}

void
MainWindow::onNewItem()
{
    m_MainWidget.onNewItem();
}

void
MainWindow::createGlobalShortcuts()
{
    // New item
    {
        QShortcut* newItem = new QShortcut(this);
        newItem->setContext(Qt::ApplicationShortcut);
        newItem->setEnabled(true);
        QKeySequence sequence(Qt::CTRL + Qt::Key_N);
        newItem->setKey(sequence);

        connect(newItem, SIGNAL(activated()), SLOT(onNewItem()));
    }
}

void
MainWindow::uncheckAllDockItems(WindowType wndException)
{
    if(wndException != WindowType::Houses)
        m_ActionDockHouses->setChecked(false);

    if(wndException != WindowType::Priests)
        m_ActionDockPriests->setChecked(false);

    if(wndException != WindowType::Languages)
        m_ActionDockLanguages->setChecked(false);

    if(wndException != WindowType::Comunes)
        m_ActionDockComunes->setChecked(false);

    if(wndException != WindowType::Counties)
        m_ActionDockCounties->setChecked(false);

    if(wndException != WindowType::Deaneries)
        m_ActionDockDeaneries->setChecked(false);

    if(wndException != WindowType::Localities)
        m_ActionDockLocalities->setChecked(false);

    if(wndException != WindowType::Images)
        m_ActionDockImages->setChecked(false);

    if(wndException != WindowType::Taxes)
        m_ActionDockTaxes->setChecked(false);
}
