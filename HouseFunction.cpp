#include "HouseFunction.h"

QString HouseFunction::STR_CREATE_TABLE = "Create table HouseFunction (\
Id varchar(50) primary key,\
Original text,\
Current text,\
LegalStatus int)";
QString HouseFunction::STR_TABLE_NAME = "HouseFunction";

HouseFunction::HouseFunction()
    :   m_Id(QUuid::createUuid()),
        m_Original(),
        m_Current(),
        m_LegalStatus(HouseLegalStatus::EvangelicalChurch)
{}

HouseFunction::HouseFunction(const HouseFunction& hf)
    :   m_Id(hf.Id()),
        m_Original(hf.Original()),
        m_Current(hf.Current()),
        m_LegalStatus(hf.LegalStatus())
{}

HouseFunction::~HouseFunction(){}

HouseFunction&
HouseFunction::operator=(const HouseFunction& hf)
{
    m_Id = hf.Id();
    m_Original = hf.Original();
    m_Current = hf.Current();
    m_LegalStatus = hf.LegalStatus();

    return *this;
}

bool
HouseFunction::operator==(const HouseFunction& hf)const
{
    return m_Id == hf.Id();
}

bool
HouseFunction::operator!=(const HouseFunction& hf)const
{
    return !(this->operator ==(hf));
}

bool
HouseFunction::saveToDB()
{
    bool result = false;

    // TODO

    return result;
}

bool
HouseFunction::loadFromDB(const QUuid& id)
{
    bool result = false;

    if(id.isNull())
        return result;

    // TODO

    return result;
}

bool
HouseFunction::CreateTable()
{
    bool result = true;
    RunQuery(HouseFunction::STR_CREATE_TABLE, result);

    return result;
}

bool
HouseFunction::TableExists()
{
    return ::TableExists(HouseFunction::STR_TABLE_NAME);
}
