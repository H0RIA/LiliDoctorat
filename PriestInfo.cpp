#include "PriestInfo.h"

QString PriestInfo::STR_CREATE_TABLE = "Create table Priest (\
        Id varchar(50) primary key,\
        FirstName varchar(255),\
        LastName varchar(255))";
QString PriestInfo::STR_TABLE_NAME = "Priest";

PriestInfo::PriestInfo()
    :   m_Id(QUuid::createUuid()),
        m_FirstName(),
        m_LastName()
{
}

PriestInfo::PriestInfo(const PriestInfo& pi)
    :   m_Id(pi.Id()),
        m_FirstName(pi.FirstName()),
        m_LastName(pi.LastName())
{
}

PriestInfo::~PriestInfo()
{
}

PriestInfo&
PriestInfo::operator=(const PriestInfo& pi)
{
    setFirstName(pi.FirstName());
    setLastName(pi.LastName());
    setId(pi.Id());

    return *this;
}

bool
PriestInfo::operator==(const PriestInfo& pi)const
{
    return Id() == pi.Id();
}

bool
PriestInfo::operator!=(const PriestInfo& pi)const
{
    return !(this->operator ==(pi));
}

bool
PriestInfo::CreateTable()
{
    bool result = true;
    RunQuery(PriestInfo::STR_CREATE_TABLE, result);

    return result;
}

bool
PriestInfo::TableExists()
{
    return ::TableExists(PriestInfo::STR_TABLE_NAME);
}

bool
PriestInfo::LoadFromDB()
{
    if(m_Id.isNull())
        return false;

    QString strQuery = QString("Select * From %1 Where Id = '%2'").arg(PriestInfo::STR_TABLE_NAME).arg(m_Id.toString());
    QSqlQuery query(strQuery);
    if(query.next()){
        setFirstName(query.value("FirstName").toString());
        setLastName(query.value("LastName").toString());

        return true;
    }

    return false;
}

bool
PriestInfo::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, FirstName, LastName) Values('%2', '%3', '%4')")
                .arg(PriestInfo::STR_TABLE_NAME).arg(m_Id.toString()).arg(FirstName()).arg(LastName());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set FirstName = '%2', LastName = '%3' Where Id = '%4'")
                .arg(PriestInfo::STR_TABLE_NAME).arg(FirstName()).arg(LastName()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
PriestInfo::ExistsInDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(PriestInfo::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}

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
