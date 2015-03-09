#include "Comune.h"

QString Comune::STR_CREATE_TABLE = "Create table Comune (\
Id varchar(50) primary key,\
NameRO varchar(255),\
NameDE varchar(255),\
NameSX varchar(255),\
NameHU varchar(255),\
IdCounty varchar(50),\
FOREIGN KEY(IdCounty) REFERENCES County(Id)\
)";

QString Comune::STR_TABLE_NAME = "Comune";

Comune::Comune()
    :   m_Id(QUuid::createUuid()),
        m_NameRO(),
        m_NameDE(),
        m_NameSX(),
        m_NameHU(),
        m_County()
{}

Comune::Comune(const Comune& comune)
    :   m_Id(comune.Id()),
        m_NameRO(comune.NameRO()),
        m_NameDE(comune.NameDE()),
        m_NameSX(comune.NameSX()),
        m_NameHU(comune.NameHU()),
        m_County(comune.County())
{}

Comune::~Comune(){}

Comune&
Comune::operator=(const Comune& comune)
{
    m_Id = comune.Id();
    m_NameRO = comune.NameRO();
    m_NameDE = comune.NameDE();
    m_NameSX = comune.NameSX();
    m_NameHU = comune.NameHU();
    m_County = comune.County();

    return *this;
}

bool
Comune::operator==(const Comune& comune)const
{
    if(m_Id == comune.Id())
        return true;

    return false;
}

bool
Comune::operator!=(const Comune& comune)const
{
    return !(this->operator ==(comune));
}

bool
Comune::CreateTable()
{
    bool result = true;
    RunQuery(Comune::STR_CREATE_TABLE, result);

    return result;
}

bool
Comune::TableExists()
{
    return ::TableExists(Comune::STR_TABLE_NAME);
}

bool
Comune::LoadFromDB()
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select * From %1 Where Id = '%2'").arg(Comune::STR_TABLE_NAME).arg(m_Id.toString()));
    if(query.next()){
        setCounty(QUuid(query.value("IdCounty").toString()));
        setNameRO(query.value("NameRO").toString());
        setNameDE(query.value("NameDE").toString());
        setNameSX(query.value("NameSX").toString());
        setNameHU(query.value("NameHU").toString());

        return true;
    }

    return false;
}

bool
Comune::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, NameRO, NameDE, NameSX, NameHU, IdCounty) Values('%2', '%3', '%4', '%5', '%6', '%7')")
                .arg(Comune::STR_TABLE_NAME).arg(m_Id.toString()).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU()).arg(m_County.toString());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set NameRO = '%2', NameDE = '%3', NameSX = '%4', NameHU = '%5', IdCounty = '%6' Where Id = '%7'")
                .arg(Comune::STR_TABLE_NAME).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU()).arg(m_County.toString()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
Comune::ExistsInDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(Comune::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
