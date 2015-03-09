#include "House.h"

QString House::STR_CREATE_TABLE = "Create table House (\
Id varchar(50) primary key,\
NameRO varchar(255),\
NameDE varchar(255),\
NameSX varchar(255),\
NameHU varchar(255),\
Description text,\
IdLocation varchar(50),\
HouseDating text,\
IdBuildingInfo varchar(50),\
IdHouseFunction varchar(50),\
IdHousePositioning varchar(50),\
FOREIGN KEY(IdLocation) REFERENCES LocationInfo(Id),\
FOREIGN KEY(IdBuildingInfo) REFERENCES BuildingInfo(Id),\
FOREIGN KEY(IdHouseFunction) REFERENCES HouseFunction(Id),\
FOREIGN KEY(IdHousePositioning) REFERENCES HousePositioning(Id))";
QString House::STR_TABLE_NAME = "House";

House::House()
    :   m_Id(QUuid::createUuid()),
        m_NameRO(),
        m_NameDE(),
        m_NameSX(),
        m_NameHU(),
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
        m_NameRO(house.NameRO()),
        m_NameDE(house.NameDE()),
        m_NameSX(house.NameSX()),
        m_NameHU(house.NameHU()),
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
    m_NameRO = house.NameRO();
    m_NameDE = house.NameDE();
    m_NameSX = house.NameSX();
    m_NameHU = house.NameHU();
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

bool
House::CreateTable()
{
    bool result = true;
    RunQuery(House::STR_CREATE_TABLE, result);

    return result;
}

bool
House::TableExists()
{
    return ::TableExists(House::STR_TABLE_NAME);
}
