#include "House.h"

House::House()
    :   m_Id(QUuid::createUuid()),
        m_Name(),
        m_Description(),
        m_LocationId(),
        m_HouseDating(),
        m_Functionality(),
        m_Positioning(),
        m_PriestTenure_list(),
        m_TaxInfo_list(),
        m_BuildInfo(),
        m_ImageInfo_list()
{}

House::House(const House& house)
    :   m_Id(house.Id()),
        m_Name(house.Name()),
        m_Description(house.Description()),
        m_LocationId(house.LocationId()),
        m_HouseDating(house.HouseDating()),
        m_Functionality(house.Functionality()),
        m_Positioning(house.Positioning()),
        m_PriestTenure_list(house.getPriestTenureList()),
        m_TaxInfo_list(house.getTaxInfoList()),
        m_BuildInfo(house.BuildInfo()),
        m_ImageInfo_list(house.getImageInfoList())
{}

House::~House(){}

House&
House::operator=(const House& house)
{
    m_Id = house.Id();
    m_Name = house.Name();
    m_Description = house.Description();
    m_LocationId = house.LocationId();
    m_HouseDating = house.HouseDating();
    m_Functionality = house.Functionality();
    m_Positioning = house.Positioning();
    m_PriestTenure_list = house.getPriestTenureList();
    m_TaxInfo_list = house.getTaxInfoList();
    m_BuildInfo = house.BuildInfo();
    m_ImageInfo_list = house.getImageInfoList();

    return *this;
}

bool
House::operator==(const House& house)const
{
    return m_Id == house.Id();
}

bool
House::operator!=(const House& house)const
{
    return !(this->operator ==(house));
}

//void
//House::addImage(const ImageInfo& image)
//{
//    if(!m_ImageInfo_list.contains(image))
//        m_ImageInfo_list.append(image);
//}

//void
//House::addImage(ImageInfo* pImage)
//{
//    if(pImage == nullptr)
//        return;

//    if(!m_ImageInfo_list.contains(*pImage))
//        m_ImageInfo_list.append(*pImage);
//}
