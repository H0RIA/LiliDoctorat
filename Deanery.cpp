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

    return result;
}

bool
Deanery::TableExists()
{
    return ::TableExists(Deanery::STR_TABLE_NAME);
}
