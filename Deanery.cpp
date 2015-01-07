#include "Deanery.h"

Deanery::Deanery()
    :   m_Id(QUuid::createUuid()),
        m_Name()
{}

Deanery::Deanery(const Deanery& deanery)
    :   m_Id(deanery.Id()),
        m_Name(deanery.Name())
{}

Deanery::~Deanery(){}

void
Deanery::setName(const QString& name, const QUuid& langId)
{
    m_Name[langId] = name;
}

Deanery&
Deanery::operator=(const Deanery& deanery)
{
    m_Id = deanery.Id();
    m_Name = deanery.Name();

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

