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
