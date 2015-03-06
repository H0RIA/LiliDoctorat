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

    QSqlQuery query(QString("Select * From Taxes Where Id = '%1'").arg(m_Id.toString()));
    if(query.exec()){
        QSqlRecord record = query.record();

        setName(record.value("Name").toString());
        setDescription(record.value("Description").toString());
        setFormula(record.value("Formula").toString());

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
        strQuery = QString("Insert into Taxes (Id, Name, Description, Formula) Values('%1', '%2', '%3', '%4');")
                .arg(m_Id.toString()).arg(m_Name).arg(m_Description).arg(m_Formula);
    }else{
        // We must update the old data
        strQuery = QString("Update Taxes Set Name = '%1', Description = '%2', Formula = '%3') Where Id = '%4';")
                .arg(m_Name).arg(m_Description).arg(m_Formula).arg(m_Id.toString());
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

    QSqlQuery query(QString("Select Count(*) As TaxExists From Taxes Where Id = '%1'").arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("TaxExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
