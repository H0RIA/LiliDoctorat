#ifndef BUILDINGINFO
#define BUILDINGINFO

#include "Base.h"

class BuildingInfo
{
    DECLARE_PROPERTY(QString, Shape)
    DECLARE_PROPERTY(QString, RoomPlacement)
    DECLARE_PROPERTY(int, RoomCount)
    DECLARE_PROPERTY(int, FrontFloorCount)
    DECLARE_PROPERTY(int, BackFloorCount)
    DECLARE_PROPERTY(QString, FrontBay)
    DECLARE_PROPERTY(QString, SideBay)
    DECLARE_PROPERTY(QDate, BuildDate)
    DECLARE_PROPERTY(QString, ArchitecturalStyle)
    DECLARE_PROPERTY(QString, Doors)
    DECLARE_PROPERTY(QString, Windows)
    DECLARE_PROPERTY_GREF(QStringList, Notes)
    DECLARE_PROPERTY(QString, BasementVault)
    DECLARE_PROPERTY(QString, Roof)
    DECLARE_PROPERTY(QString, Ceiling)
    DECLARE_PROPERTY(QString, Pinion)

    public:
        BuildingInfo();
        BuildingInfo(const BuildingInfo& bi);
        virtual ~BuildingInfo();

        BuildingInfo& operator=(const BuildingInfo& bi);
        bool operator==(const BuildingInfo& bi)const;
        bool operator!=(const BuildingInfo& bi)const;
};

#endif // BUILDINGINFO

