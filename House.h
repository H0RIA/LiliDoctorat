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
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY(QString, Name)
    DECLARE_PROPERTY(QString, Description)
    DECLARE_PROPERTY(QUuid, LocationId)
    DECLARE_PROPERTY(QString, HouseDating)
    DECLARE_PROPERTY_GREF(HouseFunction, Functionality)
    DECLARE_PROPERTY_GREF(HousePositioning, Positioning)

    DECLARE_SINGLETON_OBJECT(PriestTenure)
    //DECLARE_PROPERTY_GREF(QList<PriestTenure>, Priests)
    DECLARE_SINGLETON_OBJECT(TaxInfo)
//    DECLARE_PROPERTY_GREF(QList<TaxInfo>, Taxes)
    DECLARE_PROPERTY_GREF(BuildingInfo, BuildInfo)
    DECLARE_SINGLETON_OBJECT(ImageInfo)
//    DECLARE_PROPERTY_GREF(QList<ImageInfo>, Images)

    public:
        House();
        House(const House& house);
        virtual ~House();

        House& operator=(const House& house);
        bool operator==(const House& house)const;
        bool operator!=(const House& house)const;
};

#endif // HOUSE
