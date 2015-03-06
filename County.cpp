#include "Language.h"
#include "County.h"

QString County::STR_CREATE_TABLE = "Create table County (\
Id varchar(50) primary key,\
IdLocale varchar(50),\
LocalizedName varchar(255))";
QString County::STR_TABLE_NAME = "County";

County::County()
    :   m_Id(QUuid::createUuid()),
        m_Name()
{}

County::County(const County& county)
    :   m_Id(county.Id()),
        m_Name(county.Name())
{}

County::~County(){}

void
County::setName(const QString& name, const QUuid& langId)
{
    m_Name[langId] = name;
}

County&
County::operator=(const County& county)
{
    m_Id = county.Id();
    m_Name = county.Name();

    return *this;
}

bool
County::operator==(const County& county)const
{
    if(m_Id == county.Id())
        return true;

    return false;
}

bool
County::operator!=(const County& county)const
{
    return !(this->operator ==(county));
}

bool
County::CreateTable()
{
    bool result = true;
    RunQuery(County::STR_CREATE_TABLE, result);

    return result;
}

bool
County::TableExists()
{
    return ::TableExists(County::STR_TABLE_NAME);
}

bool
County::LoadFromDB()
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select * From %1 Where Id = '%2'").arg(County::STR_TABLE_NAME).arg(m_Id.toString()));
    if(query.exec()){
        QSqlRecord record = query.record();

        LocalizedName name;
        name.insert(QUuid(record.value("IdLocale").toString()), record.value("LocalizedName").toString());

        setName(name);

        return true;
    }

    return false;
}

bool
County::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;
    QMap<QUuid /*LanguageId*/, QString>::const_iterator iter = m_Name.begin();

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, IdLocale, LocalizedName) Values('%2', '%3', '%4')")
                .arg(County::STR_TABLE_NAME).arg(m_Id.toString()).arg(iter.key().toString()).arg(iter.value());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set IdLocale = '%2', LocalizedName = '%3') Where Id = '%4'")
                .arg(County::STR_TABLE_NAME).arg(iter.key().toString()).arg(iter.value()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
County::ExistsInDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(County::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
