#ifndef HOUSE
#define HOUSE

#include "Base.h"
#include "PriestInfo.h"
#include "HouseFunction.h"
#include "TaxInfo.h"
#include "ImageInfo.h"
#include "HousePositioning.h"
#include "BuildingInfo.h"
#include "LocationInfo.h"

class House
{
    DECLARE_PROPERTY(QUuid, Id)                                 // Done
    DECLARE_PROPERTY(LocalizedName, Name)                       // Done
    DECLARE_PROPERTY(QString, Description)                      // Done
    DECLARE_PROPERTY(QUuid, LocationId)                         // Done
    DECLARE_PROPERTY(QString, HouseDating)                      // Done
    DECLARE_PROPERTY(QUuid, HouseFunctionId)                    // Done
    DECLARE_PROPERTY(QUuid, HousePositioningId)                 // HousePositioning - Done

    DECLARE_SINGLETON_OBJECT(PriestTenure, PriestTenures)       // Done
    DECLARE_SINGLETON_OBJECT(TaxInfo, Taxes)                    // Done
    DECLARE_PROPERTY(QUuid, BuildInfoId)                        // BuildingInfo - Done
    DECLARE_SINGLETON_OBJECT(ImageInfo, Images)                 // Done

    public:
        House();
        House(const House& house);
        virtual ~House();

        House& operator=(const House& house);
        bool operator==(const House& house)const;
        bool operator!=(const House& house)const;
};

#endif // HOUSE
