#ifndef BUILDINGINFO
#define BUILDINGINFO

#include "Base.h"

class BuildingInfo
{
    DECLARE_PROPERTY(QUuid, Id)                         // Done
    DECLARE_PROPERTY(QString, Shape)                    // Done
    DECLARE_PROPERTY(QString, RoomPlacement)            // Done
    DECLARE_PROPERTY(int, RoomCount)                    // Done
    DECLARE_PROPERTY(int, FrontFloorCount)              // Done
    DECLARE_PROPERTY(int, BackFloorCount)               // Done
    DECLARE_PROPERTY(QString, FrontBay)                 // Done
    DECLARE_PROPERTY(QString, SideBay)                  // Done
    DECLARE_PROPERTY(QDate, BuildDate)                  // Done
    DECLARE_PROPERTY(QString, ArchitecturalStyle)       // Done
    DECLARE_PROPERTY(QString, Doors)                    // Done
    DECLARE_PROPERTY(QString, Windows)                  // Done
    DECLARE_PROPERTY_GREF(QStringList, Notes)           // Done
    DECLARE_PROPERTY(QString, BasementVault)            // Done
    DECLARE_PROPERTY(QString, Roof)                     // Done
    DECLARE_PROPERTY(QString, Ceiling)                  // Done
    DECLARE_PROPERTY(QString, Pinion)                   // Done

    public:
        BuildingInfo();
        BuildingInfo(const BuildingInfo& bi);
        virtual ~BuildingInfo();

        BuildingInfo& operator=(const BuildingInfo& bi);
        bool operator==(const BuildingInfo& bi)const;
        bool operator!=(const BuildingInfo& bi)const;
};

#endif // BUILDINGINFO

