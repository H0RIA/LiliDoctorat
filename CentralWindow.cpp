#include "CentralWindow.h"
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

    setLayout(mainLayout);
}

CentralWindow::~CentralWindow()
{
}
