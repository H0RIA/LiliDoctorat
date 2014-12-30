#include "PriestInfo.h"

PriestInfo::PriestInfo()
    :   m_Id(QUuid::createUuid()),
        m_FirstName(),
        m_LastName()
{
}

PriestInfo::PriestInfo(const PriestInfo& pi)
    :   m_Id(pi.Id()),
        m_FirstName(pi.FirstName()),
        m_LastName(pi.LastName())
{
}

PriestInfo::~PriestInfo()
{
}

PriestInfo&
PriestInfo::operator=(const PriestInfo& pi)
{
    setFirstName(pi.FirstName());
    setLastName(pi.LastName());
    setId(pi.Id());

    return *this;
}

bool
PriestInfo::operator==(const PriestInfo& pi)const
{
    return Id() == pi.Id();
}

bool
PriestInfo::operator!=(const PriestInfo& pi)const
{
    return !(this->operator ==(pi));
}

PriestTenure::PriestTenure()
    :   m_Id(QUuid::createUuid()),
        m_PriestId(),
        m_Start(),
        m_End()
{}

PriestTenure::PriestTenure(const PriestTenure& pt)
    :   m_Id(pt.Id()),
        m_PriestId(pt.PriestId()),
        m_Start(pt.Start()),
        m_End(pt.End())
{}

PriestTenure::~PriestTenure(){}

PriestTenure&
PriestTenure::operator=(const PriestTenure& pt)
{
    m_Id = pt.Id();
    m_PriestId = pt.PriestId();
    m_Start = pt.Start();
    m_End = pt.End();

    return *this;
}

bool
PriestTenure::operator==(const PriestTenure& pt)const
{
    if(m_PriestId == pt.PriestId() &&  m_Start == pt.Start() &&  m_End == pt.End())
        return true;

    return false;
}

bool
PriestTenure::operator!=(const PriestTenure& pt)const
{
    return !(this->operator ==(pt));
}
