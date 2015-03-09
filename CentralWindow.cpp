#include "CentralWindow.h"
#include "WndHouses.h"
#include "WndPriests.h"
#include "WndComunes.h"
#include "WndLanguages.h"
#include "WndCounties.h"
#include "WndDeaneries.h"
#include "WndLocalities.h"
#include "WndImages.h"
#include "WndTaxes.h"


CentralWindow::CentralWindow(QWidget* parent)
    :   QWidget(parent),
        m_WidgetContainer(this),
        m_Windows(),
        m_pManager(HouseManager::instance())
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
    m_Windows[WindowType::Houses] = new UI::WndHouses();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Houses]);

    m_Windows[WindowType::Priests] = new UI::WndPriests();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Priests]);

    m_Windows[WindowType::Languages] = new UI::WndLanguages();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Languages]);

    m_Windows[WindowType::Comunes] = new UI::WndComunes();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Comunes]);

    m_Windows[WindowType::Counties] = new UI::WndCounties();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Counties]);

    m_Windows[WindowType::Deaneries] = new UI::WndDeaneries();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Deaneries]);

    m_Windows[WindowType::Localities] = new UI::WndLocalities();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Localities]);

    m_Windows[WindowType::Images] = new UI::WndImages();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Images]);

    m_Windows[WindowType::Taxes] = new UI::WndTaxes();
    m_WidgetContainer.addWidget(m_Windows[WindowType::Taxes]);

    m_WidgetContainer.setCurrentIndex((int)WindowType::Houses);

    // Shortcut NEW ITEM
    {
        QShortcut* newItem = new QShortcut(this);
        newItem->setContext(Qt::ApplicationShortcut);
        newItem->setEnabled(true);
        QKeySequence sequence(Qt::CTRL + Qt::Key_N);
        newItem->setKey(sequence);
        m_Shortcuts.push_back(newItem);

        connect(newItem, SIGNAL(activated()), SLOT(onNewItem()));
    }
}
