#include "TaxInfo.h"

QString TaxInfo::STR_CREATE_TABLE = "Create table TaxInfo (\
Id varchar(50) primary key,\
Name varchar(255),\
Description text,\
Formula text)";

QString TaxInfo::STR_TABLE_NAME = "TaxInfo";

TaxInfo::TaxInfo()
    :   m_Name(),
        m_Description(),
        m_Formula()
{}

TaxInfo::TaxInfo(const TaxInfo& ti)
    :   m_Name(ti.Name()),
        m_Description(ti.Description()),
        m_Formula(ti.Formula())
{}

TaxInfo::~TaxInfo(){}

TaxInfo&
TaxInfo::operator=(const TaxInfo& ti)
{
    m_Name = ti.Name();
    m_Description = ti.Description();
    m_Formula = ti.Formula();

    return *this;
}

bool
TaxInfo::operator==(const TaxInfo& ti)const
{
    if(m_Name == ti.Name() && m_Description == ti.Description() && m_Formula == ti.Formula())
        return true;

    return false;
}

bool
TaxInfo::operator!=(const TaxInfo& ti)const
{
    return !(this->operator ==(ti));
}

bool
TaxInfo::CreateTable()
{
    bool result = true;
    RunQuery(TaxInfo::STR_CREATE_TABLE, result);

    return result;
}

bool
TaxInfo::TableExists()
{
    return ::TableExists(TaxInfo::STR_TABLE_NAME);
}

bool
TaxInfo::LoadFromDB()
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select * From %1 Where Id = '%2'").arg(TaxInfo::STR_TABLE_NAME).arg(m_Id.toString()));
    if(query.next()){
        setName(query.value("Name").toString());
        setDescription(query.value("Description").toString());
        setFormula(query.value("Formula").toString());

        return true;
    }

    return false;
}

bool
TaxInfo::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;
    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, Name, Description, Formula) Values('%2', '%3', '%4', '%5')")
                .arg(TaxInfo::STR_TABLE_NAME).arg(m_Id.toString()).arg(m_Name).arg(m_Description).arg(m_Formula);
    }else{
        // We must update the old data
        strQuery = QString("Update %1 Set Name = '%2', Description = '%3', Formula = '%4' Where Id = '%5'")
                .arg(TaxInfo::STR_TABLE_NAME).arg(m_Name).arg(m_Description).arg(m_Formula).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
TaxInfo::ExistsInDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(TaxInfo::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
