#include "HouseFunction.h"

HouseFunction::HouseFunction()
    :   m_Original(),
        m_Current(),
        m_LegalStatus(HouseLegalStatus::EvangelicalChurch)
{}

HouseFunction::HouseFunction(const HouseFunction& hf)
    :   m_Original(hf.Original()),
        m_Current(hf.Current()),
        m_LegalStatus(hf.LegalStatus())
{}

HouseFunction::~HouseFunction(){}

HouseFunction&
HouseFunction::operator=(const HouseFunction& hf)
{
    m_Original = hf.Original();
    m_Current = hf.Current();
    m_LegalStatus = hf.LegalStatus();

    return *this;
}

bool
HouseFunction::operator==(const HouseFunction& hf)const
{
    if(m_Original == hf.Original() && m_Current == hf.Current() && m_LegalStatus == hf.LegalStatus())
        return true;

    return false;
}

bool
HouseFunction::operator!=(const HouseFunction& hf)const
{
    return !(this->operator ==(hf));
}

