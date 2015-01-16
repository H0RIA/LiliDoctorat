#include "House.h"

House::House()
    :   m_Id(QUuid::createUuid()),
        m_Name(),
        m_Description(),
        m_LocationId(),
        m_HouseDating(),
        m_HouseFunctionId(),
        m_HousePositioningId(),
        m_PriestTenures(),
        m_Taxes(),
        m_BuildInfoId(),
        m_Images()
{}

House::House(const House& house)
    :   m_Id(house.Id()),
        m_Name(house.Name()),
        m_Description(house.Description()),
        m_LocationId(house.LocationId()),
        m_HouseDating(house.HouseDating()),
        m_HouseFunctionId(house.HouseFunctionId()),
        m_HousePositioningId(house.HousePositioningId()),
        m_PriestTenures(house.getPriestTenures()),
        m_Taxes(house.getTaxes()),
        m_BuildInfoId(house.BuildInfoId()),
        m_Images(house.getImages())
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
    m_HouseFunctionId = house.HouseFunctionId();
    m_HousePositioningId = house.HousePositioningId();
    m_PriestTenures = house.getPriestTenures();
    m_Taxes = house.getTaxes();
    m_BuildInfoId = house.BuildInfoId();
    m_Images = house.getImages();

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

bool
House::saveToDB()
{
    bool result = false;

    // TODO

    return result;
}

//void
//House::addImage(const ImageInfo& image)
//{
//    if(!m_Images.contains(image))
//        m_Images.append(image);
//}

//void
//House::addImage(ImageInfo* pImage)
//{
//    if(pImage == nullptr)
//        return;

//    if(!m_Images.contains(*pImage))
//        m_Images.append(*pImage);
//}
