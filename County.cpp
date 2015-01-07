#include "County.h"

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


