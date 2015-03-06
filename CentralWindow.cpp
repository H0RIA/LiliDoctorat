#include "CentralWindow.h"
#include "WndEditHouse.h"
#include "ThumbnailDelegate.h"
#include "WndHouses.h"
#include "WndPriests.h"
#include "WndLanguages.h"
#include "WndCounties.h"
#include "WndDeaneries.h"
#include "WndLocalities.h"
#include "WndImages.h"
#include "WndTaxes.h"
#include "HouseModel.h"

CentralWindow::CentralWindow(QWidget* parent)
    :   QWidget(parent),
        m_WidgetContainer(this),
        m_Windows(),
        m_View(this),
        m_pManager(HouseManager::instance())
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(&m_WidgetContainer);

//    HouseModel* model = new HouseModel();
//    m_View.setItemDelegateForColumn((int)HouseModelColumn::Thumbnail, new ThumbnailDelegate());
//    m_View.setModel(model);
//    m_View.verticalHeader()->hide();
//    m_View.setSelectionBehavior(QAbstractItemView::SelectRows);
//    m_View.setEditTriggers(QAbstractItemView::NoEditTriggers);
//    m_View.setSelectionMode(QAbstractItemView::SingleSelection);
//    m_View.horizontalHeader()->setStretchLastSection(false);

    setLayout(mainLayout);

//    connect(&m_View, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)));
}

CentralWindow::~CentralWindow()
{
}


void
CentralWindow::onDoubleClicked(const QModelIndex& index)
{
    if(!index.isValid())
        return;

    int row = index.row();
    House* ptrHouse = qobject_cast<HouseModel*>(m_View.model())->getHouseManager()->getHouses().at(row);
    if(ptrHouse != nullptr)
    {
        WndEditHouse dialog(this, ptrHouse->Id());
        dialog.exec();
    }
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
}
