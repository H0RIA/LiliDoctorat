#include "HouseFunction.h"

using namespace DBWrapper;

QString HouseFunction::STR_CREATE_TABLE = "Create table HouseFunction (\
Id varchar(50) primary key,\
Original text,\
Current text,\
LegalStatus int)";
QString HouseFunction::STR_TABLE_NAME = "HouseFunction";

HouseFunction::HouseFunction()
    :   m_Id(QUuid::createUuid()),
        m_Original(),
        m_Current(),
        m_LegalStatus(HouseLegalStatus::EvangelicalChurch)
{}

HouseFunction::HouseFunction(const HouseFunction& hf)
    :   m_Id(hf.Id()),
        m_Original(hf.Original()),
        m_Current(hf.Current()),
        m_LegalStatus(hf.LegalStatus())
{}

HouseFunction::~HouseFunction(){}

HouseFunction&
HouseFunction::operator=(const HouseFunction& hf)
{
    m_Id = hf.Id();
    m_Original = hf.Original();
    m_Current = hf.Current();
    m_LegalStatus = hf.LegalStatus();

    return *this;
}

bool
HouseFunction::operator==(const HouseFunction& hf)const
{
    return m_Id == hf.Id();
}

bool
HouseFunction::operator!=(const HouseFunction& hf)const
{
    return !(this->operator ==(hf));
}

bool
HouseFunction::saveToDB()
{
    bool result = false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, Original, Current, LegalStatus) Values('%2', '%3', '%4', '%5')")
                .arg(HouseFunction::STR_TABLE_NAME).arg(m_Id.toString()).arg(Original()).arg(Current()).arg((int)LegalStatus());
    }else{
        // We must update the old data
        strQuery = QString("Update %1 Set Original = '%2', Current = '%3', LegalStatus = '%4' Where Id = '%5'")
                .arg(HouseFunction::STR_TABLE_NAME).arg(Original()).arg(Current()).arg((int)LegalStatus()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return result;
}

bool
HouseFunction::loadFromDB(const QUuid& id)
{
    bool result = false;

    if(id.isNull())
        return result;

    m_Id = id;

    QString strQuery = QString("Select * From %1 Where Id = '%2'").arg(HouseFunction::STR_TABLE_NAME).arg(m_Id.toString());
    QSqlQuery query(strQuery);
    if(query.next()){
        setCurrent(query.value("Current").toString());
        setLegalStatus((HouseLegalStatus)query.value("LegalStatus").toInt());
        setOriginal(query.value("Original").toString());

        result = true;
    }else{
        qDebug() << "Cannot read from DB: " << query.lastError().text();
    }

    return result;
}

bool
HouseFunction::ExistsInDB()const
{
    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(HouseFunction::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}

bool
HouseFunction::CreateTable()
{
    bool result = true;
    RunQuery(HouseFunction::STR_CREATE_TABLE, result);

    QString strQuery = QString("Insert Into %1 (Id, Original, Current, LegalStatus) Values('{00000000-0000-0000-0000-000000000000}', '', '', %2) ")
            .arg(HouseFunction::STR_TABLE_NAME).arg((int)HouseLegalStatus::DoesNotExist);
    RunQuery(strQuery, result);

    return result;
}

bool
HouseFunction::TableExists()
{
    return ::TableExists(HouseFunction::STR_TABLE_NAME);
}
