#include "BuildingInfo.h"

QString BuildingInfo::STR_CREATE_TABLE = "Create table BuildingInfo (\
Id varchar(50) primary key,\
Shape text,\
RoomPlacement text,\
RoomCount int,\
FrontFloorCount int,\
BackFloorCount int,\
FrontBay text,\
SideBay text,\
BuildDate date,\
ArchitecturalStyle text,\
Doors text,\
Windows text,\
BasementVault text,\
Roof text,\
Ceiling text,\
Pinion text)";
QString BuildingInfo::STR_TABLE_NAME = "BuildingInfo";

BuildingInfo::BuildingInfo()
    :   m_Id(QUuid::createUuid()),
        m_Shape(),
        m_RoomPlacement(),
        m_RoomCount(0),
        m_FrontFloorCount(0),
        m_BackFloorCount(0),
        m_FrontBay(),
        m_SideBay(),
        m_BuildDate(),
        m_ArchitecturalStyle(),
        m_Doors(),
        m_Windows(),
        m_Notes(),
        m_BasementVault(),
        m_Roof(),
        m_Ceiling(),
        m_Pinion()
{}

BuildingInfo::BuildingInfo(const BuildingInfo& bi)
    :   m_Id(bi.Id()),
        m_Shape(bi.Shape()),
        m_RoomPlacement(bi.RoomPlacement()),
        m_RoomCount(bi.RoomCount()),
        m_FrontFloorCount(bi.FrontFloorCount()),
        m_BackFloorCount(bi.BackFloorCount()),
        m_FrontBay(bi.FrontBay()),
        m_SideBay(bi.SideBay()),
        m_BuildDate(bi.BuildDate()),
        m_ArchitecturalStyle(bi.ArchitecturalStyle()),
        m_Doors(bi.Doors()),
        m_Windows(bi.Windows()),
        m_Notes(bi.Notes()),
        m_BasementVault(bi.BasementVault()),
        m_Roof(bi.Roof()),
        m_Ceiling(bi.Ceiling()),
        m_Pinion(bi.Pinion())
{}

BuildingInfo::~BuildingInfo(){}

BuildingInfo&
BuildingInfo::operator=(const BuildingInfo& bi)
{
    m_Id = bi.Id();
    m_Shape = bi.Shape();
    m_RoomPlacement = bi.RoomPlacement();
    m_RoomCount = bi.RoomCount();
    m_FrontFloorCount = bi.FrontFloorCount();
    m_BackFloorCount = bi.BackFloorCount();
    m_FrontBay = bi.FrontBay();
    m_SideBay = bi.SideBay();
    m_BuildDate = bi.BuildDate();
    m_ArchitecturalStyle = bi.ArchitecturalStyle();
    m_Doors = bi.Doors();
    m_Windows = bi.Windows();
    m_Notes = bi.Notes();
    m_BasementVault = bi.BasementVault();
    m_Roof = bi.Roof();
    m_Ceiling = bi.Ceiling();
    m_Pinion = bi.Pinion();

    return *this;
}

bool
BuildingInfo::operator==(const BuildingInfo& bi)const
{
    return m_Id == bi.Id();
}

bool
BuildingInfo::operator!=(const BuildingInfo& bi)const
{
    return !(this->operator ==(bi));
}

bool
BuildingInfo::CreateTable()
{
    bool result = true;
    RunQuery(BuildingInfo::STR_CREATE_TABLE, result);

    return result;
}

bool
BuildingInfo::TableExists()
{
    return ::TableExists(BuildingInfo::STR_TABLE_NAME);
}
