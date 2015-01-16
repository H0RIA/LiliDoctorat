#include "CentralWindow.h"
#include "WndEditHouse.h"
#include "ThumbnailDelegate.h"
#include "HouseModel.h"

CentralWindow::CentralWindow(QWidget* parent)
    :   QWidget(parent),
        m_View(this),
        m_pManager(HouseManager::instance())
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
