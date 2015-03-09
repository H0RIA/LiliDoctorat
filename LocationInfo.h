#ifndef LOCATIONINFO
#define LOCATIONINFO

#include "Locality.h"
#include "County.h"
#include "Comune.h"
#include "Deanery.h"

class LocationInfo
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(QString, NameRO)
    DECLARE_PROPERTY_GREF(QString, NameDE)
    DECLARE_PROPERTY_GREF(QString, NameSX)
    DECLARE_PROPERTY_GREF(QString, NameHU)
    DECLARE_PROPERTY(QUuid, Locality)    // Locality
    DECLARE_PROPERTY(QUuid, DeaneryInfo) // Deanery
    DECLARE_PROPERTY(QDate, InventoryDate)
    DECLARE_PROPERTY(QString, OldStatus)

    public:
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        LocationInfo();
        LocationInfo(const LocationInfo& li);
        virtual ~LocationInfo();

        LocationInfo& operator=(const LocationInfo& li);
        bool operator==(const LocationInfo& li)const;
        bool operator!=(const LocationInfo& li)const;

        static bool CreateTable();
        static bool TableExists();
};

#endif // LOCATIONINFO

