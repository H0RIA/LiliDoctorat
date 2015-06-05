#include "WndEditHouse_TabPositioning.h"

using namespace UI::Editors::House;

WndEditHouse_TabPositioning::WndEditHouse_TabPositioning(DBWrapper::House* pHouse, bool newItem, QWidget* parent)
    :   QWidget(parent),
        m_Positioning()
{
    initializeData();

    if(newItem){
        if(pHouse != nullptr)
            pHouse->setHousePositioningId(m_Positioning.Id());
    }else{
        if(!pHouse->HousePositioningId().isNull()){
            loadFromDB(pHouse->HousePositioningId());
        }
        else
            pHouse->setHousePositioningId(m_Positioning.Id());
    }
}

bool
WndEditHouse_TabPositioning::saveToDB()
{
    m_Positioning.setDeclivity(m_edDeclivity.toPlainText());
    m_Positioning.setFromChurch(m_edFromChurch.toPlainText());
    m_Positioning.setFromGarden(m_edFromGarden.toPlainText());
    m_Positioning.setFromRoad(m_edFromStreet.toPlainText());

    return m_Positioning.saveToDB();
}

bool
WndEditHouse_TabPositioning::loadFromDB(const QUuid& idPositioning)
{
    bool result = m_Positioning.loadFromDB(idPositioning);

    if(result){
        m_edDeclivity.setPlainText(m_Positioning.Declivity());
        m_edFromChurch.setPlainText(m_Positioning.FromChurch());
        m_edFromGarden.setPlainText(m_Positioning.FromGarden());
        m_edFromStreet.setPlainText(m_Positioning.FromRoad());
    }

    return result;
}

void
WndEditHouse_TabPositioning::initializeData()
{
    m_lblFromChurch.setText(tr("From church:"));
    m_lblFromStreet.setText(tr("From street:"));
    m_lblFromGarden.setText(tr("From garden:"));
    m_lblDeclivity.setText(tr("Declivity:"));

    QVBoxLayout* verticalLayout = new QVBoxLayout();
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->setSpacing(0);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);



    QGridLayout* centralLayout = new QGridLayout();
    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralLayout->setSpacing(5);

    int row = 0;
    int col = 0;

    // Configure label column
    centralLayout->addWidget(&m_lblFromChurch, row, col, 1, 1, Qt::AlignRight);
    row = 1;
    centralLayout->addWidget(&m_lblFromStreet, row, col, 1, 1, Qt::AlignRight);
    row = 2;
    centralLayout->addWidget(&m_lblFromGarden, row, col, 1, 1, Qt::AlignRight);
    row = 3;
    centralLayout->addWidget(&m_lblDeclivity, row, col, 1, 1, Qt::AlignRight);

    // Configure editors column
    col = 1;
    row = 0;
    centralLayout->addWidget(&m_edFromChurch, row, col, 1, 1, Qt::AlignLeft);
    row = 1;
    centralLayout->addWidget(&m_edFromStreet, row, col, 1, 1, Qt::AlignLeft);
    row = 2;
    centralLayout->addWidget(&m_edFromGarden, row, col, 1, 1, Qt::AlignLeft);
    row = 3;
    centralLayout->addWidget(&m_edDeclivity, row, col, 1, 1, Qt::AlignLeft);

    verticalLayout->addSpacing(20);
    verticalLayout->addLayout(centralLayout);
    verticalLayout->addSpacing(20);
    verticalLayout->addStretch();

    mainLayout->addStretch();
    mainLayout->addLayout(verticalLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);
}
