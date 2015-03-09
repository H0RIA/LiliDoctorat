#include "Locality.h"

QString Locality::STR_CREATE_TABLE = "Create table Locality (\
Id varchar(50) primary key,\
NameRO varchar(255),\
NameDE varchar(255),\
NameSX varchar(255),\
NameHU varchar(255),\
IdComune varchar(50),\
FOREIGN KEY(IdComune) REFERENCES Comune(Id)\
)";

QString Locality::STR_TABLE_NAME = "Locality";

Locality::Locality()
    :   m_Id(QUuid::createUuid()),
        m_NameRO(),
        m_NameDE(),
        m_NameSX(),
        m_NameHU(),
        m_Comune()
{}

Locality::Locality(const Locality& loc)
    :   m_Id(loc.Id()),
        m_NameRO(loc.NameRO()),
        m_NameDE(loc.NameDE()),
        m_NameSX(loc.NameSX()),
        m_NameHU(loc.NameHU()),
        m_Comune(loc.Comune())
{}

Locality::~Locality(){}

Locality&
Locality::operator=(const Locality& loc)
{
    m_Id = loc.Id();
    m_NameRO = loc.NameRO();
    m_NameDE = loc.NameDE();
    m_NameSX = loc.NameSX();
    m_NameHU = loc.NameHU();
    m_Comune = loc.Comune();

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
    if(query.next()){
        setComune(QUuid(query.value("IdComune").toString()));
        setNameRO(query.value("NameRO").toString());
        setNameDE(query.value("NameDE").toString());
        setNameSX(query.value("NameSX").toString());
        setNameHU(query.value("NameHU").toString());

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

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, NameRO, NameDE, NameSX, NameHU, IdComune) Values('%2', '%3', '%4', '%5', '%6', '%7')")
                .arg(Locality::STR_TABLE_NAME).arg(m_Id.toString()).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU()).arg(m_Comune.toString());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set NameRO = '%2', NameDE = '%3', NameSX = '%4', NameHU = '%5', IdComune = '%6' Where Id = '%7'")
                .arg(Locality::STR_TABLE_NAME).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU()).arg(m_Comune.toString()).arg(m_Id.toString());
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
