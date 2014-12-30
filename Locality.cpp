#include "Locality.h"

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

