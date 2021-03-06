#include "CentralWindow.h"
#include "UI/SideMenu/WndHouses.h"
#include "UI/SideMenu/WndPriests.h"
#include "UI/SideMenu/WndComunes.h"
#include "UI/SideMenu/WndLanguages.h"
#include "UI/SideMenu/WndCounties.h"
#include "UI/SideMenu/WndDeaneries.h"
#include "UI/SideMenu/WndLocalities.h"
#include "UI/SideMenu/WndImages.h"
#include "UI/SideMenu/WndTaxes.h"

using namespace UI;

CentralWindow::CentralWindow(QWidget* parent)
    :   QWidget(parent),
        m_WidgetContainer(this),
        m_Windows(),
        m_pManager(DBWrapper::HouseManager::instance())
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(&m_WidgetContainer);

    setLayout(mainLayout);

    initializeData();
}

CentralWindow::~CentralWindow()
{
}

void
CentralWindow::onDockSelectWindow(WindowType wndType)
{
    m_WidgetContainer.setCurrentIndex((int)wndType);
}

void
CentralWindow::onNewItem()
{
    WindowType wndType = (WindowType)m_WidgetContainer.currentIndex();
    if(m_Windows[wndType] != nullptr)
        callOnNewItem(wndType, m_Windows[wndType]);
}

void
CentralWindow::initializeData()
{
    m_Windows[WindowType::Houses] = new UI::SideMenu::WndHouses();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Houses]);

    m_Windows[WindowType::Priests] = new UI::SideMenu::WndPriests();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Priests]);

    m_Windows[WindowType::Languages] = new UI::SideMenu::WndLanguages();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Languages]);

    m_Windows[WindowType::Comunes] = new UI::SideMenu::WndComunes();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Comunes]);

    m_Windows[WindowType::Counties] = new UI::SideMenu::WndCounties();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Counties]);

    m_Windows[WindowType::Deaneries] = new UI::SideMenu::WndDeaneries();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Deaneries]);

    m_Windows[WindowType::Localities] = new UI::SideMenu::WndLocalities();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Localities]);

    m_Windows[WindowType::Images] = new UI::SideMenu::WndImages();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Images]);

    m_Windows[WindowType::Taxes] = new UI::SideMenu::WndTaxes();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Taxes]);

    m_WidgetContainer.setCurrentIndex((int)WindowType::Houses);

    // Shortcut NEW ITEM
//    {
//        QShortcut* newItem = new QShortcut(this);
//        newItem->setContext(Qt::ApplicationShortcut);
//        newItem->setEnabled(true);
//        QKeySequence sequence(Qt::CTRL + Qt::Key_N);
//        newItem->setKey(sequence);
//        m_Shortcuts.push_back(newItem);

//        connect(newItem, SIGNAL(activated()), SLOT(onNewItem()));
//    }
}
