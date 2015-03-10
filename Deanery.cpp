#include "Deanery.h"

QString Deanery::STR_CREATE_TABLE = "Create table Deanery (\
Id varchar(50) primary key,\
NameRO varchar(255),\
NameDE varchar(255),\
NameSX varchar(255),\
NameHU varchar(255)\
)";
QString Deanery::STR_TABLE_NAME = "Deanery";

Deanery::Deanery()
    :   m_Id(QUuid::createUuid()),
        m_NameRO(),
        m_NameDE(),
        m_NameSX(),
        m_NameHU()
{}

Deanery::Deanery(const Deanery& deanery)
    :   m_Id(deanery.Id()),
        m_NameRO(deanery.NameRO()),
        m_NameDE(deanery.NameDE()),
        m_NameSX(deanery.NameSX()),
        m_NameHU(deanery.NameHU())
{}

Deanery::~Deanery(){}

Deanery&
Deanery::operator=(const Deanery& deanery)
{
    m_Id = deanery.Id();
    m_NameRO = deanery.NameRO();
    m_NameDE = deanery.NameDE();
    m_NameSX = deanery.NameSX();
    m_NameHU = deanery.NameHU();

    return *this;
}

bool
Deanery::operator==(const Deanery& deanery)const
{
    if(m_Id == deanery.Id())
        return true;

    return false;
}

bool
Deanery::operator!=(const Deanery& deanery)const
{
    return !(this->operator ==(deanery));
}

bool
Deanery::CreateTable()
{
    bool result = true;
    RunQuery(Deanery::STR_CREATE_TABLE, result);

    QString strQuery = QString("Insert Into %1 (Id, NameRO, NameDE, NameSX, NameHU) Values ('{00000000-0000-0000-0000-000000000000}', 'N/A', 'N/A', 'N/A', 'N/A') ").arg(Deanery::STR_TABLE_NAME);
    RunQuery(strQuery, result);

    return result;
}

bool
Deanery::TableExists()
{
    return ::TableExists(Deanery::STR_TABLE_NAME);
}

bool
Deanery::LoadFromDB()
{
    QString strQuery = QString("Select * From %1 Where Id = '%2'").arg(Deanery::STR_TABLE_NAME).arg(m_Id.toString());
    QSqlQuery query(strQuery);
    if(query.next()){
        setNameRO(query.value("NameRO").toString());
        setNameDE(query.value("NameDE").toString());
        setNameSX(query.value("NameSX").toString());
        setNameHU(query.value("NameHU").toString());

        return true;
    }

    return false;
}

bool
Deanery::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, NameRO, NameDE, NameSX, NameHU) Values('%2', '%3', '%4', '%5', '%6')")
                .arg(Deanery::STR_TABLE_NAME).arg(m_Id.toString()).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set NameRO = '%2', NameDE = '%3', NameSX = '%4', NameHU = '%5' Where Id = '%6'")
                .arg(Deanery::STR_TABLE_NAME).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
Deanery::ExistsInDB()const
{
    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(Deanery::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
