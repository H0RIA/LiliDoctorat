#include "BuildingInfo.h"

using namespace DBWrapper;

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

    QString strQuery = QString("Insert Into %1 (Id, Shape, RoomPlacement, RoomCount, FrontFloorCount, BackFloorCount, \
FrontBay, SideBay, ArchitecturalStyle, Doors, Windows, BasementVault, Roof, Ceiling, Pinion) \
Values('{00000000-0000-0000-0000-000000000000}', 'N/A', 'N/A', -1, 0, 0, 'N/A', 'N/A', 'N/A', 'N/A', 'N/A', 'N/A', 'N/A', 'N/A', 'N/A') ")
            .arg(BuildingInfo::STR_TABLE_NAME);
    RunQuery(strQuery, result);

    return result;
}

bool
BuildingInfo::TableExists()
{
    return ::TableExists(BuildingInfo::STR_TABLE_NAME);
}

bool
BuildingInfo::LoadFromDB()
{
    QString strQuery = QString("Select * From %1 Where Id = '%2'").arg(BuildingInfo::STR_TABLE_NAME).arg(m_Id.toString());
    QSqlQuery query(strQuery);
    if(query.next()){
        setShape(query.value("Shape").toString());
        setRoomPlacement(query.value("RoomPlacement").toString());
        setRoomCount(query.value("RoomCount").toInt());
        setFrontFloorCount(query.value("FrontFloorCount").toInt());
        setBackFloorCount(query.value("BackFloorCount").toInt());
        setFrontBay(query.value("FrontBay").toString());
        setSideBay(query.value("SideBay").toString());
        setBuildDate(QDate::fromJulianDay(query.value("BuildDate").toInt()));
        setArchitecturalStyle(query.value("ArchitecturalStyle").toString());
        setDoors(query.value("Doors").toString());
        setWindows(query.value("Windows").toString());
        setBasementVault(query.value("BasementVault").toString());
        setRoof(query.value("Roof").toString());
        setCeiling(query.value("Ceiling").toString());
        setPinion(query.value("Pinion").toString());

        return true;
    }

    return false;
}

bool
BuildingInfo::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, Shape, RoomPlacement, RoomCount, FrontFloorCount,\
BakFloorCount, FrontBay, SideBay, BuildDate, ArchitecturalStyle, Doors, Windows, BasementVault, Roof, Ceiling, Pinion) \
Values('%2', '%3', %4, %5, %6, '%7', '%8', %9, '%10', '%11', '%12', '%13', '%14', '%15', '%16')")
                .arg(BuildingInfo::STR_TABLE_NAME).arg(m_Id.toString()).arg(Shape()).arg(RoomPlacement()).arg(RoomCount()).arg(FrontFloorCount())
                .arg(BackFloorCount()).arg(FrontBay()).arg(SideBay()).arg(BuildDate().toJulianDay()).arg(ArchitecturalStyle()).arg(Doors())
                .arg(Windows()).arg(BasementVault()).arg(Roof()).arg(Ceiling()).arg(Pinion());
    }else{
        // We must update the old data

        // TODO
//        strQuery = QString("Update %1 Set NameRO = '%2', NameDE = '%3', NameSX = '%4', NameHU = '%5' Where Id = '%6'")
//                .arg(County::STR_TABLE_NAME).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
BuildingInfo::ExistsInDB()const
{
    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(BuildingInfo::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
