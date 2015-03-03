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
