#include "HouseFunction.h"

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

