#include "HousePositioning.h"

using namespace DBWrapper;

OutHouses::OutHouses()
    :   m_StillExisting(),
        m_Destroyed()
{}

OutHouses::OutHouses(const OutHouses& oh)
    :   m_StillExisting(oh.StillExisting()),
        m_Destroyed(oh.Destroyed())
{}

OutHouses::~OutHouses(){}

OutHouses&
OutHouses::operator=(const OutHouses& oh)
{
    m_StillExisting = oh.StillExisting();
    m_Destroyed = oh.Destroyed();

    return *this;
}

bool
OutHouses::operator==(const OutHouses& oh)const
{
    if(m_StillExisting.count() == oh.StillExisting().count()){
        // TODO
        int currentIndex = 0;
        for(currentIndex = 0; currentIndex < m_StillExisting.count(); currentIndex++){
            if(!oh.StillExisting().contains(m_StillExisting.at(currentIndex)))
                return false;
        }

        if(m_Destroyed.count() == oh.Destroyed().count()){
            for(currentIndex = 0; currentIndex < m_Destroyed.count(); currentIndex++){
                if(!oh.Destroyed().contains(m_Destroyed.at(currentIndex)))
                    return false;
            }

        }

        return true;
    }

    return false;
}

bool
OutHouses::operator!=(const OutHouses& oh)const
{
    return !(this->operator ==(oh));
}

QString HousePositioning::STR_CREATE_TABLE = "Create table HousePositioning (\
Id varchar(50) primary key,\
FromChurch text,\
FromRoad text,\
FromGarden text,\
Declivity text)";
QString HousePositioning::STR_TABLE_NAME = "HousePositioning";

HousePositioning::HousePositioning()
    :   m_Id(QUuid::createUuid()),
        m_FromChurch(),
        m_FromRoad(),
        m_FromGarden(),
        m_Declivity(),
        m_Outhouses()
{}

HousePositioning::HousePositioning(const HousePositioning& hp)
    :   m_Id(hp.Id()),
        m_FromChurch(hp.FromChurch()),
        m_FromRoad(hp.FromRoad()),
        m_FromGarden(hp.FromGarden()),
        m_Declivity(hp.Declivity()),
        m_Outhouses(hp.Outhouses())
{}

HousePositioning::~HousePositioning(){}

HousePositioning&
HousePositioning::operator=(const HousePositioning& hp)
{
    m_Id = hp.Id();
    m_FromChurch = hp.FromChurch();
    m_FromRoad = hp.FromRoad();
    m_FromGarden = hp.FromGarden();
    m_Declivity = hp.Declivity();
    m_Outhouses = hp.Outhouses();

    return *this;
}

bool
HousePositioning::operator==(const HousePositioning& hp)const
{
    return m_Id == hp.Id();
}

bool
HousePositioning::operator!=(const HousePositioning& hp)const
{
    return !(this->operator ==(hp));
}

bool
HousePositioning::loadFromDB(const QUuid& id)
{
    bool result = false;

    m_Id = id;
    if(id.isNull())
        return result;

    QString strQuery = QString("Select * From %1 Where Id = '%2'").arg(HousePositioning::STR_TABLE_NAME).arg(m_Id.toString());
    QSqlQuery query(strQuery);
    if(query.next()){
        setFromChurch(query.value("FromChurch").toString());
        setFromRoad(query.value("FromRoad").toString());
        setFromGarden(query.value("FromGarden").toString());
        setDeclivity(query.value("Declivity").toString());

        result = true;
    }

    return result;
}

bool
HousePositioning::saveToDB()const
{
    bool result = false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, FromChurch, FromRoad, FromGarden, Declivity) Values('%2', '%3', '%4', '%5', '%6')")
                .arg(HousePositioning::STR_TABLE_NAME).arg(m_Id.toString()).arg(FromChurch()).arg(FromRoad()).arg(FromGarden()).arg(Declivity());
    }else{
        // We must update the old data
        strQuery = QString("Update %1 Set FromChurch = '%2', FromRoad = '%3', FromGarden = '%4', Declivity = '%5' Where Id = '%6'")
                .arg(HousePositioning::STR_TABLE_NAME).arg(FromChurch()).arg(FromRoad()).arg(FromGarden()).arg(Declivity()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return result;
}

bool
HousePositioning::ExistsInDB()const
{
    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(HousePositioning::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}

bool
HousePositioning::CreateTable()
{
    bool result = true;
    RunQuery(HousePositioning::STR_CREATE_TABLE, result);

    QString strQuery = QString("Insert Into %1 (Id, FromChurch, FromRoad, FromGarden, Declivity) Values('{00000000-0000-0000-0000-000000000000}', 'N/A', 'N/A', 'N/A', 'N/A') ")
            .arg(HousePositioning::STR_TABLE_NAME);
    RunQuery(strQuery, result);

    return result;
}

bool
HousePositioning::TableExists()
{
    return ::TableExists(HousePositioning::STR_TABLE_NAME);
}
