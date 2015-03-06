#include "HouseModel.h"
#include "ThumbnailDelegate.h"
#include "WndEditHouse.h"
#include "WndHouses.h"

using namespace UI;

WndHouses::WndHouses(QWidget* parent)
    :   QWidget(parent),
        m_View(this)
{
    initializeData();
}

WndHouses::~WndHouses()
{
}

void
WndHouses::onNewItem()
{
    // TODO
}

void
WndHouses::initializeData()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(&m_View);

    HouseModel* model = new HouseModel();
    m_View.setItemDelegateForColumn((int)HouseModelColumn::Thumbnail, new ThumbnailDelegate());
    m_View.setModel(model);
    m_View.verticalHeader()->hide();
    m_View.setSelectionBehavior(QAbstractItemView::SelectRows);
    m_View.setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_View.setSelectionMode(QAbstractItemView::SingleSelection);
    m_View.horizontalHeader()->setStretchLastSection(false);

    setLayout(mainLayout);

    connect(&m_View, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)));
}

void
WndHouses::onDoubleClicked(const QModelIndex& index)
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

