#include "Locality.h"

QString Locality::STR_CREATE_TABLE = "Create table Locality (\
Id varchar(50) primary key,\
IdLocale varchar(50),\
LocalizedName varchar(255),\
IdCounty varchar(50))";

QString Locality::STR_TABLE_NAME = "Locality";

Locality::Locality()
    :   m_Id(QUuid::createUuid()),
        m_Name(),
        m_County()
{}

Locality::Locality(const Locality& loc)
    :   m_Id(loc.Id()),
        m_Name(loc.Name()),
        m_County(loc.County())
{}

Locality::~Locality(){}

Locality&
Locality::operator=(const Locality& loc)
{
    m_Id = loc.Id();
    m_Name = loc.Name();
    m_County = loc.County();

    return *this;
}

bool
Locality::operator==(const Locality& loc)const
{
    if(m_Id == loc.Id())
        return true;

    return false;
}

bool
Locality::operator!=(const Locality& loc)const
{
    return !(this->operator ==(loc));
}

bool
Locality::CreateTable()
{
    bool result = true;
    RunQuery(Locality::STR_CREATE_TABLE, result);

    return result;
}

bool
Locality::TableExists()
{
    return ::TableExists(Locality::STR_TABLE_NAME);
}

bool
Locality::LoadFromDB()
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select * From %1 Where Id = '%2'").arg(Locality::STR_TABLE_NAME).arg(m_Id.toString()));
    if(query.exec()){
        QSqlRecord record = query.record();

        LocalizedName name;
        name.insert(QUuid(record.value("IdLocale").toString()), record.value("LocalizedName").toString());

        setCounty(QUuid(record.value("IdCounty").toString()));
        setName(name);

        return true;
    }

    return false;
}

bool
Locality::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;
    QMap<QUuid /*LanguageId*/, QString>::const_iterator iter = m_Name.begin();

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, IdLocale, LocalizedName, IdCounty) Values('%2', '%3', '%4', '%5')")
                .arg(Locality::STR_TABLE_NAME).arg(m_Id.toString()).arg(iter.key().toString()).arg(iter.value()).arg(m_County.toString());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set IdLocale = '%2', LocalizedName = '%3', IdCounty = '%4') Where Id = '%5'")
                .arg(Locality::STR_TABLE_NAME).arg(iter.key().toString()).arg(iter.value()).arg(m_County.toString()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
Locality::ExistsInDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(Locality::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
