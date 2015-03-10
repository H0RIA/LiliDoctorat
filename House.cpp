#include "House.h"

QString House::STR_CREATE_TABLE = "Create table House (\
Id varchar(50) primary key,\
NameRO varchar(255),\
NameDE varchar(255),\
NameSX varchar(255),\
NameHU varchar(255),\
Description text,\
IdLocality varchar(50),\
IdDeanery varchar(50),\
InventoryDate date,\
OldStatus text,\
HouseDating text,\
IdBuildingInfo varchar(50),\
IdHouseFunction varchar(50),\
IdHousePositioning varchar(50),\
FOREIGN KEY(IdLocality) REFERENCES Locality(Id),\
FOREIGN KEY(IdDeanery) REFERENCES Deanery(Id),\
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
        m_IdLocality(),
        m_IdDeanery(),
        m_InventoryDate(),
        m_OldStatus(),
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
        m_IdLocality(house.IdLocality()),
        m_IdDeanery(house.IdDeanery()),
        m_InventoryDate(house.InventoryDate()),
        m_OldStatus(house.OldStatus()),
        m_HouseDating(house.HouseDating()),
        m_HouseFunctionId(house.HouseFunctionId()),
        m_HousePositioningId(house.HousePositioningId()),
        m_PriestTenures(house.getPriestTenures()),
        m_Taxes(house.getTaxes()),
        m_BuildInfoId(house.BuildInfoId()),
        m_Images(house.getImages())
{}

House::~House(){}

bool
House::hasNextImage(const QUuid& idCurrentImage)const
{
    bool result = false;

    QList<ImageInfo*> images = getImages();
    if(images.isEmpty())
        return result;

    ImageInfo* currentImage = nullptr;
    QList<ImageInfo*>::const_iterator iter;
    for(iter = images.begin(); iter != images.end(); iter++){
        ImageInfo* image = (*iter);
        if(image != nullptr){
            if(image->Id() == idCurrentImage){
                currentImage = image;
                break;
            }
        }
    }

    if(currentImage != nullptr){
        iter++;
        result = iter == images.end();
    }

    return result;
}

bool
House::hasPrevImage(const QUuid& idCurrentImage)const
{
    bool result = false;

    QList<ImageInfo*> images = getImages();
    if(images.isEmpty())
        return result;

    ImageInfo* currentImage = nullptr;
    QList<ImageInfo*>::const_iterator iter;
    for(iter = images.begin(); iter != images.end(); iter++){
        ImageInfo* image = (*iter);
        if(image != nullptr){
            if(image->Id() == idCurrentImage){
                currentImage = image;
                break;
            }
        }
    }

    if(currentImage != nullptr){
        iter--;
        result = iter == images.end();
    }

    return result;
}

QString
House::getNextImagePath(const QUuid& idCurrentImage)const
{
    QString path;

    QList<ImageInfo*> images = getImages();
    if(images.isEmpty())
        return path;

    if(!hasNextImage(idCurrentImage))
        return path;

    ImageInfo* currentImage = nullptr;
    QList<ImageInfo*>::const_iterator iter;
    for(iter = images.begin(); iter != images.end(); iter++){
        ImageInfo* image = *iter;
        if(image != nullptr){
            if(image->Id() == idCurrentImage){
                currentImage = image;
                break;
            }
        }
    }

    if(currentImage != nullptr){
        iter++;
        if(*iter != nullptr){
            path = (*iter)->Path();
        }
    }

    return path;
}

QUuid
House::getNextImageId(const QUuid& idCurrentImage)const
{
    QUuid id;

    QList<ImageInfo*> images = getImages();
    if(images.isEmpty())
        return id;

    if(!hasNextImage(idCurrentImage))
        return id;

    ImageInfo* currentImage = nullptr;
    QList<ImageInfo*>::const_iterator iter;
    for(iter = images.begin(); iter != images.end(); iter++){
        ImageInfo* image = *iter;
        if(image != nullptr){
            if(image->Id() == idCurrentImage){
                currentImage = image;
                break;
            }
        }
    }

    if(currentImage != nullptr){
        iter++;
        if(*iter != nullptr){
            id = (*iter)->Id();
        }
    }

    return id;
}

QString
House::getPrevImagePath(const QUuid& idCurrentImage)const
{
    QString path;

    QList<ImageInfo*> images = getImages();
    if(images.isEmpty())
        return path;

    if(!hasPrevImage(idCurrentImage))
        return path;

    ImageInfo* currentImage = nullptr;
    QList<ImageInfo*>::const_iterator iter;
    for(iter = images.begin(); iter != images.end(); iter++){
        ImageInfo* image = *iter;
        if(image != nullptr){
            if(image->Id() == idCurrentImage){
                currentImage = image;
                break;
            }
        }
    }

    if(currentImage != nullptr){
        iter--;
        if(*iter != nullptr){
            path = (*iter)->Path();
        }
    }

    return path;
}

QUuid
House::getPrevImageId(const QUuid& idCurrentImage)const
{
    QUuid id;

    QList<ImageInfo*> images = getImages();
    if(images.isEmpty())
        return id;

    if(!hasPrevImage(idCurrentImage))
        return id;

    ImageInfo* currentImage = nullptr;
    QList<ImageInfo*>::const_iterator iter;
    for(iter = images.begin(); iter != images.end(); iter++){
        ImageInfo* image = *iter;
        if(image != nullptr){
            if(image->Id() == idCurrentImage){
                currentImage = image;
                break;
            }
        }
    }

    if(currentImage != nullptr){
        iter--;
        if(*iter != nullptr){
            id = (*iter)->Id();
        }
    }

    return id;
}

House&
House::operator=(const House& house)
{
    m_Id = house.Id();
    m_NameRO = house.NameRO();
    m_NameDE = house.NameDE();
    m_NameSX = house.NameSX();
    m_NameHU = house.NameHU();
    m_Description = house.Description();
    m_IdLocality = house.IdLocality();
    m_IdDeanery = house.IdDeanery();
    m_InventoryDate = house.InventoryDate();
    m_OldStatus = house.OldStatus();
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
        setIdLocality(QUuid(query.value("IdLocality").toString()));
        setIdDeanery(QUuid(query.value("IdDeanery").toString()));
        setInventoryDate(query.value("InventoryDate").toDate());
        setOldStatus(query.value("OldStatus").toString());
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

    if(!InventoryDate().isValid()){
        QDate currentDate = QDate::currentDate();
        currentDate.addYears(-2000);
        const_cast<House*>(this)->setInventoryDate(currentDate);
    }

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, NameRO, NameDE, NameSX, NameHU, Description, IdLocality, IdDeanery, InventoryDate, \
OldStatus, HouseDating, IdBuildingInfo, IdHouseFunction, \
IdHousePositioning) Values('%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', %10, '%11', '%12', '%13', '%14', '%15')")
                .arg(House::STR_TABLE_NAME).arg(m_Id.toString()).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU())
                .arg(Description()).arg(IdLocality().toString()).arg(IdDeanery().toString()).arg(InventoryDate().toJulianDay()).arg(OldStatus())
                .arg(HouseDating()).arg(BuildInfoId().toString()).arg(HouseFunctionId().toString()).arg(HousePositioningId().toString());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set NameRO = '%2', NameDE = '%3', NameSX = '%4', NameHU = '%5', Description = '%6', \
IdLocality = '%7', IdDeanery = '%8', InventoryDate = %9, OldStatus = '%10', HouseDating = '%11', IdBuildingInfo = '%12', \
IdHouseFunction = '%13', IdHousePositioning = '%14' Where Id = '%15'")
                .arg(House::STR_TABLE_NAME).arg(NameRO()).arg(NameDE()).arg(NameSX()).arg(NameHU())
                .arg(Description()).arg(IdLocality().toString()).arg(IdDeanery().toString()).arg(InventoryDate().toJulianDay()).arg(OldStatus())
                .arg(HouseDating()).arg(BuildInfoId().toString()).arg(HouseFunctionId().toString()).arg(HousePositioningId().toString()).arg(m_Id.toString());
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
