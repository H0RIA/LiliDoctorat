#include "DBWrapper/House.h"
#include "WndEditHouse_TabBuilding.h"

using namespace UI::Editors::House;

WndEditHouse_TabBuilding::WndEditHouse_TabBuilding(DBWrapper::House* pHouse, bool newItem, QWidget* parent)
    :   QWidget(parent),
        m_NewItem(newItem),
        m_pHouse(pHouse),
        m_Building(),
        m_lblShape(this),
        m_edShape(this),
        m_lblRoomPlacement(this),
        m_edRoomPlacement(this),
        m_lblRoomCount(this),
        m_edRoomCount(this),
        m_lblFrontFloorCount(this),
        m_edFrontFloorCount(this),
        m_lblBackFloorCount(this),
        m_edBackFloorCount(this),
        m_lblFrontBay(this),
        m_edFrontBay(this),
        m_lblSideBay(this),
        m_edSideBay(this),
        m_lblBuildDate(this),
        m_edBuildDate(this),
        m_lblArchitecturalStyle(this),
        m_edArchitecturalStyle(this),
        m_lblDoors(this),
        m_edDoors(this),
        m_lblWindows(this),
        m_edWindows(this),
        m_lblBasementVault(this),
        m_edBasementVault(this),
        m_lblRoof(this),
        m_edRoof(this),
        m_lblCeiling(this),
        m_edCeiling(this),
        m_lblPinion(this),
        m_edPinion(this)
{
    initializeData();
}

WndEditHouse_TabBuilding::~WndEditHouse_TabBuilding(){}

void
WndEditHouse_TabBuilding::loadFromDB()
{
    if(m_NewItem || m_pHouse == nullptr)
        return;

    if(m_pHouse->BuildInfoId().isNull())
        m_pHouse->setBuildInfoId(m_Building.Id());
    else
        m_Building.setId(m_pHouse->BuildInfoId());

    if(m_Building.LoadFromDB()){
        m_edShape.setText(m_Building.Shape());
        m_edRoomPlacement.setText(m_Building.RoomPlacement());

        m_edRoomCount.setText(QString("%1").arg(m_Building.RoomCount()));
        m_edFrontFloorCount.setText(QString("%1").arg(m_Building.FrontFloorCount()));
        m_edBackFloorCount.setText(QString("%1").arg(m_Building.BackFloorCount()));

        m_edFrontBay.setText(m_Building.FrontBay());
        m_edSideBay.setText(m_Building.SideBay());
        m_edBuildDate.setText(m_Building.BuildDate().toString());

        m_edArchitecturalStyle.setText(m_Building.ArchitecturalStyle());
        m_edDoors.setText(m_Building.Doors());
        m_edWindows.setText(m_Building.Windows());

        m_edBasementVault.setText(m_Building.BasementVault());
        m_edCeiling.setText(m_Building.Ceiling());
        m_edPinion.setText(m_Building.Pinion());
        m_edRoof.setText(m_Building.Roof());
    }
}

bool
WndEditHouse_TabBuilding::saveToDB()
{
    m_Building.setShape(m_edShape.text());
    m_Building.setRoomPlacement(m_edRoomPlacement.text());

    m_Building.setRoomCount(m_edRoomCount.text().toInt());
    m_Building.setFrontFloorCount(m_edFrontFloorCount.text().toInt());
    m_Building.setBackFloorCount(m_edBackFloorCount.text().toInt());

    m_Building.setFrontBay(m_edFrontBay.text());
    m_Building.setSideBay(m_edSideBay.text());
    m_Building.setBuildDate(QDate::fromString(m_edBuildDate.text()));

    m_Building.setArchitecturalStyle(m_edArchitecturalStyle.text());
    m_Building.setDoors(m_edDoors.text());
    m_Building.setWindows(m_edWindows.text());

    m_Building.setBasementVault(m_edBasementVault.text());
    m_Building.setCeiling(m_edCeiling.text());
    m_Building.setPinion(m_edPinion.text());
    m_Building.setRoof(m_edRoof.text());

    return m_Building.SaveToDB();
}

bool
WndEditHouse_TabBuilding::eventFilter(QObject* o, QEvent * ev)
{
    Q_UNUSED(o)
    Q_UNUSED(ev)

    // TODO
    return false;
}

void
WndEditHouse_TabBuilding::initializeData()
{
    m_lblShape.setText(tr("Shape"));
    m_lblRoomPlacement.setText(tr("Rooom placement"));
    m_lblRoomCount.setText(tr("Room count"));
    m_lblFrontFloorCount.setText(tr("Front floor count"));
    m_lblBackFloorCount.setText(tr("Back floor count"));
    m_lblFrontBay.setText(tr("Front bay"));
    m_lblSideBay.setText(tr("Side bay"));
    m_lblBuildDate.setText(tr("Build date"));
    m_lblArchitecturalStyle.setText(tr("Architectural style"));
    m_lblDoors.setText(tr("Doors"));
    m_lblWindows.setText(tr("Windows"));
    m_lblBasementVault.setText(tr("Basement vault"));
    m_lblRoof.setText(tr("Roof"));
    m_lblCeiling.setText(tr("Ceiling"));
    m_lblPinion.setText(tr("Pinion"));

    int labelWidth = 80;
    int editWidth = 80;

    m_lblShape.setFixedWidth(labelWidth);
    m_lblRoomPlacement.setFixedWidth(labelWidth);
    m_lblRoomCount.setFixedWidth(labelWidth);
    m_lblFrontFloorCount.setFixedWidth(labelWidth);
    m_lblBackFloorCount.setFixedWidth(labelWidth);
    m_lblFrontBay.setFixedWidth(labelWidth);
    m_lblSideBay.setFixedWidth(labelWidth);
    m_lblBuildDate.setFixedWidth(labelWidth);
    m_lblArchitecturalStyle.setFixedWidth(labelWidth);
    m_lblDoors.setFixedWidth(labelWidth);
    m_lblWindows.setFixedWidth(labelWidth);
    m_lblBasementVault.setFixedWidth(labelWidth);
    m_lblRoof.setFixedWidth(labelWidth);
    m_lblCeiling.setFixedWidth(labelWidth);
    m_lblPinion.setFixedWidth(labelWidth);

    m_edShape.setFixedWidth(editWidth);
    m_edRoomPlacement.setFixedWidth(editWidth);
    m_edRoomCount.setFixedWidth(editWidth);
    m_edFrontFloorCount.setFixedWidth(editWidth);
    m_edBackFloorCount.setFixedWidth(editWidth);
    m_edFrontBay.setFixedWidth(editWidth);
    m_edSideBay.setFixedWidth(editWidth);
    m_edBuildDate.setFixedWidth(editWidth);
    m_edArchitecturalStyle.setFixedWidth(editWidth);
    m_edDoors.setFixedWidth(editWidth);
    m_edWindows.setFixedWidth(editWidth);
    m_edBasementVault.setFixedWidth(editWidth);
    m_edRoof.setFixedWidth(editWidth);
    m_edCeiling.setFixedWidth(editWidth);
    m_edPinion.setFixedWidth(editWidth);

    CREATE_LABELEDIT_LAYOUT(Shape, m_lblShape, m_edShape);
    CREATE_LABELEDIT_LAYOUT(RoomPlacement, m_lblRoomPlacement, m_edRoomPlacement);
    CREATE_LABELEDIT_LAYOUT(RoomCount, m_lblRoomCount, m_edRoomCount);
    CREATE_LABELEDIT_LAYOUT(FrontFloorCount, m_lblFrontFloorCount, m_edFrontFloorCount);
    CREATE_LABELEDIT_LAYOUT(BackFloorCount, m_lblBackFloorCount, m_edBackFloorCount);

    CREATE_LABELEDIT_LAYOUT(FrontBay, m_lblFrontBay, m_edFrontBay);
    CREATE_LABELEDIT_LAYOUT(SideBay, m_lblSideBay, m_edSideBay);
    CREATE_LABELEDIT_LAYOUT(BuildDate, m_lblBuildDate, m_edBuildDate);
    CREATE_LABELEDIT_LAYOUT(ArchitecturalStyle, m_lblArchitecturalStyle, m_edArchitecturalStyle);
    CREATE_LABELEDIT_LAYOUT(Doors, m_lblDoors, m_edDoors);
    CREATE_LABELEDIT_LAYOUT(Windows, m_lblWindows, m_edWindows);

    CREATE_LABELEDIT_LAYOUT(BasementVault, m_lblBasementVault, m_edBasementVault);
    CREATE_LABELEDIT_LAYOUT(Roof, m_lblRoof, m_edRoof);
    CREATE_LABELEDIT_LAYOUT(Ceiling, m_lblCeiling, m_edCeiling);
    CREATE_LABELEDIT_LAYOUT(Pinion, m_lblPinion, m_edPinion);

    QVBoxLayout* layoutLeft = new QVBoxLayout();
    layoutLeft->setContentsMargins(0, 0, 0, 0);
    layoutLeft->setSpacing(0);

    layoutLeft->addLayout(layoutShape);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutRoomPlacement);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutRoomCount);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutFrontFloorCount);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutBackFloorCount);
    layoutLeft->addStretch();

    QVBoxLayout* layoutCenter = new QVBoxLayout();
    layoutCenter->setContentsMargins(0, 0, 0, 0);
    layoutCenter->setSpacing(0);

    layoutLeft->addLayout(layoutFrontBay);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutSideBay);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutBuildDate);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutArchitecturalStyle);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutDoors);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutWindows);
    layoutLeft->addStretch();

    QVBoxLayout* layoutRight = new QVBoxLayout();
    layoutRight->setContentsMargins(0, 0, 0, 0);
    layoutRight->setSpacing(0);

    layoutLeft->addLayout(layoutBasementVault);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutRoof);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutCeiling);
    layoutLeft->addSpacing(5);
    layoutLeft->addLayout(layoutPinion);
    layoutLeft->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addSpacing(5);
    mainLayout->addLayout(layoutLeft);
    mainLayout->addSpacing(5);
    mainLayout->addLayout(layoutCenter);
    mainLayout->addSpacing(5);
    mainLayout->addLayout(layoutRight);
    mainLayout->addSpacing(5);

    setLayout(mainLayout);

    loadFromDB();
}
