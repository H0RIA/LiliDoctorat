#include "LocationInfo.h"

LocationInfo::LocationInfo()
    :   m_Id(QUuid::createUuid()),
        m_Name(),
        m_Comune(),
        m_ShireInfo(),
        m_DeaneryInfo(),
        m_InventoryDate(),
        m_OldStatus()
{}

LocationInfo::LocationInfo(const LocationInfo& li)
    :   m_Id(li.Id()),
        m_Name(li.Name()),
        m_Comune(li.Comune()),
        m_ShireInfo(li.ShireInfo()),
        m_DeaneryInfo(li.DeaneryInfo()),
        m_InventoryDate(li.InventoryDate()),
        m_OldStatus(li.OldStatus())
{}

LocationInfo::~LocationInfo(){}

LocationInfo&
LocationInfo::operator=(const LocationInfo& li)
{
    m_Id = li.Id();
    m_Name = li.Name();
    m_Comune = li.Comune();
    m_ShireInfo = li.ShireInfo();
    m_DeaneryInfo = li.DeaneryInfo();
    m_InventoryDate = li.InventoryDate();
    m_OldStatus = li.OldStatus();

    return *this;
}

bool
LocationInfo::operator==(const LocationInfo& li)const
{
    return m_Id == li.Id();
}

bool
LocationInfo::operator!=(const LocationInfo& li)const
{
    return !(this->operator ==(li));
}
