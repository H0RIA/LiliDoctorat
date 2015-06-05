#ifndef HOUSE
#define HOUSE

#include "Base.h"
#include "PriestInfo.h"
#include "HouseFunction.h"
#include "TaxInfo.h"
#include "ImageInfo.h"
#include "HousePositioning.h"
#include "BuildingInfo.h"

namespace DBWrapper
{
    class House
    {
        DECLARE_PROPERTY(QUuid, Id)                                 // Done
        DECLARE_PROPERTY_GREF(QString, NameRO)                      // Done
        DECLARE_PROPERTY_GREF(QString, NameDE)                      // Done
        DECLARE_PROPERTY_GREF(QString, NameSX)                      // Done
        DECLARE_PROPERTY_GREF(QString, NameHU)                      // Done
        DECLARE_PROPERTY(QString, Description)                      // Done

        DECLARE_PROPERTY(QUuid, IdLocality)    // Locality
        DECLARE_PROPERTY(QUuid, IdDeanery) // Deanery
        DECLARE_PROPERTY(QDate, InventoryDate)
        DECLARE_PROPERTY(QString, OldStatus)

        DECLARE_PROPERTY(QString, HouseDating)                      // Done
        DECLARE_PROPERTY(QUuid, HouseFunctionId)                    // Done
        DECLARE_PROPERTY(QUuid, HousePositioningId)                 // HousePositioning - Done

        DECLARE_SINGLETON_OBJECT(PriestTenure, PriestTenures)       // Done
        DECLARE_SINGLETON_OBJECT(TaxInfo, Taxes)                    // Done
        DECLARE_PROPERTY(QUuid, BuildInfoId)                        // BuildingInfo - Done
        DECLARE_SINGLETON_OBJECT(ImageInfo, Images)                 // Done

        public:
            static QString STR_CREATE_TABLE;
            static QString STR_TABLE_NAME;

        public:
            House();
            House(const House& house);
            virtual ~House();

            bool hasNextImage(const QUuid& idCurrentImage)const;
            bool hasPrevImage(const QUuid& idCurrentImage)const;

            QString getNextImagePath(const QUuid& idCurrentImage)const;
            QUuid getNextImageId(const QUuid& idCurrentImage)const;
            QString getPrevImagePath(const QUuid& idCurrentImage)const;
            QUuid getPrevImageId(const QUuid& idCurrentImage)const;

            House& operator=(const House& house);
            bool operator==(const House& house)const;
            bool operator!=(const House& house)const;

            static bool CreateTable();
            static bool TableExists();
            bool LoadFromDB();
            bool SaveToDB()const;
            bool ExistsInDB()const;
    };
}

#endif // HOUSE
