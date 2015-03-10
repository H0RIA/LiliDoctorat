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

bool
House::LoadFromDB()
{
    if(m_Id.isNull())
        return false;

    QString strQuery = QString("Select * From %1 Where Id = '%2'").arg(House::STR_TABLE_NAME).arg(m_Id.toString());
    QSqlQuery query(strQuery);
    if(query.next()){
        setNameRO(query.value("NameRO").toString());
        setNameDE(query.value("NameDE").toString());
        setNameSX(query.value("NameSX").toString());
        setNameHU(query.value("NameHU").toString());
        setDescription(query.value("Description").toString());
        setLocationId(QUuid(query.value("IdLocation").toString()));
        setHouseDating(query.value("HouseDating").toString());
        setBuildInfoId(QUuid(query.value("IdBuildingInfo").toString()));
        setHouseFunctionId(QUuid(query.value("IdHouseFunction").toString()));
        setHousePositioningId(QUuid(query.value("IdHousePositioning").toString()));

        // Load Images
        strQuery = QString("Select IdImage from HouseImages Where IdHouse = '%1'").arg(Id().toString());
        QSqlQuery queryHouseImages(strQuery);
        while(queryHouseImages.next()){
            ImageInfo* ii = new ImageInfo();
            ii->setId(QUuid(queryHouseImages.value("IdImage").toString()));
            if(ii->LoadFromDB()){
                addImageInfo(ii);
            }
        }

        return true;
    }

    return false;
}

bool
House::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, NameRO, NameDE, NameSX, NameHU, Description, IdLocation, HouseDating, IdBuildingInfo, IdHouseFunction, \
IdHousePositioning) Values('%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12')")
                .arg(House::STR_TABLE_NAME).arg(m_Id.toString()).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU())
                .arg(Description()).arg(LocationId().toString()).arg(HouseDating()).arg(HouseFunctionId().toString()).arg(HousePositioningId().toString());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set NameRO = '%2', NameDE = '%3', NameSX = '%4', NameHU = '%5', Description = '%6', IdLocation = '%7', HouseDating = '%8', IdBuildingInfo = '%9', \
 IdHouseFunction = '%10', IdHousePositioning = '%11' Name Where Id = '%12'")
                .arg(House::STR_TABLE_NAME).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU())
                .arg(Description()).arg(LocationId().toString()).arg(HouseDating()).arg(BuildInfoId().toString())
                .arg(HouseFunctionId().toString()).arg(HousePositioningId().toString()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    // Save images
    QList<ImageInfo*> imageList = getImages();
    foreach(ImageInfo* image, imageList){
        if(image != nullptr){
            bool result = true;
            strQuery = QString("Select Count(*) As ItemExists From HouseImages Where IdHouse = '%1' and IdImage = '%2'").arg(Id().toString()).arg(image->Id().toString());
            QSqlQuery queryExists(strQuery);
            if(queryExists.next()){
                if(queryExists.value("ItemExists").toInt() == 0){
                    strQuery = QString("Insert Into HouseImages (IdHouse, IdImage) Values('%1', '%2')").arg(Id().toString()).arg(image->Id().toString());
                    RunQuery(strQuery, result);
                }
            }
        }
    }

    return true;
}

bool
House::ExistsInDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(House::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
