#include "Shire.h"

Shire::Shire()
    :   m_Id(QUuid::createUuid()),
        m_Name()
{}

Shire::Shire(const Shire& shire)
    :   m_Id(shire.Id()),
        m_Name(shire.Name())
{}

Shire::~Shire(){}

void
Shire::setName(const QString& name, const QUuid& langId)
{
    m_Name[langId] = name;
}

Shire&
Shire::operator=(const Shire& shire)
{
    m_Id = shire.Id();
    m_Name = shire.Name();

    return *this;
}

bool
Shire::operator==(const Shire& shire)const
{
    if(m_Id == shire.Id())
        return true;

    return false;
}

bool
Shire::operator!=(const Shire& shire)const
{
    return !(this->operator ==(shire));
}


