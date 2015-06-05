#include "PriestTenure.h"

using namespace DBWrapper;

QString PriestTenure::STR_CREATE_TABLE = "Create table HousePriests (\
        Id varchar(50), \
        IdHouse varchar(50), \
        IdPriest varchar(50), \
        StartDate BIGINT, \
        EndDate BIGINT, \
        FOREIGN KEY(IdHouse) REFERENCES House(Id),\
        FOREIGN KEY(IdPriest) REFERENCES Priest(Id))";
QString PriestTenure::STR_TABLE_NAME = "HousePriests";

PriestTenure::PriestTenure()
    :   m_Id(QUuid::createUuid()),
        m_PriestId(),
        m_Start(),
        m_End()
{}

PriestTenure::PriestTenure(const PriestTenure& pt)
    :   m_Id(pt.Id()),
        m_PriestId(pt.PriestId()),
        m_Start(pt.Start()),
        m_End(pt.End())
{}

PriestTenure::~PriestTenure(){}

bool
PriestTenure::CreateTable()
{
    bool result = true;
    RunQuery(PriestTenure::STR_CREATE_TABLE, result);

    return result;
}

bool
PriestTenure::TableExists()
{
    return ::TableExists(PriestTenure::STR_TABLE_NAME);
}

bool
PriestTenure::LoadFromDB()
{
    if(m_Id.isNull())
        return false;

    QString strQuery = QString("Select * From %1 Where Id = '%2'").arg(PriestTenure::STR_TABLE_NAME).arg(m_Id.toString());
    QSqlQuery query(strQuery);
    if(query.next()){
        setEnd(QDate::fromJulianDay(query.value("EndDate").toLongLong()));
        setStart(QDate::fromJulianDay(query.value("StartDate").toLongLong()));
        setHouseId(query.value("IdHouse").toUuid());
        setPriestId(query.value("IdPriest").toUuid());

        return true;
    }

    return false;
}

bool
PriestTenure::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, IdHouse, IdPriest, StartDate, EndDate) Values('%2', '%3', '%4', %5, %6)")
                .arg(PriestTenure::STR_TABLE_NAME).arg(m_Id.toString()).arg(m_HouseId.toString()).arg(m_PriestId.toString()).arg(Start().toJulianDay()).arg(End().toJulianDay());
    }else{
        // We must update the old data
        strQuery = QString("Update %1 Set IdHouse = '%2', IdPriest = '%3', StartDate = %4, EndDate = %5 Where Id = '%6'")
                .arg(PriestTenure::STR_TABLE_NAME).arg(m_HouseId.toString()).arg(m_PriestId.toString()).arg(Start().toJulianDay()).arg(End().toJulianDay()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
PriestTenure::ExistsInDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(PriestTenure::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}


PriestTenure&
PriestTenure::operator=(const PriestTenure& pt)
{
    m_Id = pt.Id();
    m_PriestId = pt.PriestId();
    m_Start = pt.Start();
    m_End = pt.End();

    return *this;
}

bool
PriestTenure::operator==(const PriestTenure& pt)const
{
    if(m_PriestId == pt.PriestId() &&  m_Start == pt.Start() &&  m_End == pt.End())
        return true;

    return false;
}

bool
PriestTenure::operator!=(const PriestTenure& pt)const
{
    return !(this->operator ==(pt));
}
