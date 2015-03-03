#ifndef HOUSEPOSITIONING
#define HOUSEPOSITIONING

#include "Base.h"

class OutHouses
{
    DECLARE_PROPERTY_GREF(QStringList, StillExisting)
    DECLARE_PROPERTY_GREF(QStringList, Destroyed)

    public:
        OutHouses();
        OutHouses(const OutHouses& oh);
        virtual ~OutHouses();

        OutHouses& operator=(const OutHouses& oh);
        bool operator==(const OutHouses& oh)const;
        bool operator!=(const OutHouses& oh)const;
};

class HousePositioning
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(QString, FromChurch)
    DECLARE_PROPERTY_GREF(QString, FromRoad)
    DECLARE_PROPERTY_GREF(QString, FromGarden)
    DECLARE_PROPERTY_GREF(QString, Declivity)
    DECLARE_PROPERTY(OutHouses, Outhouses)
//    DECLARE_PROPERTY_GREF(OutHouses, Outhouses)

    public:
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        HousePositioning();
        HousePositioning(const HousePositioning& cp);
        virtual ~HousePositioning();

        HousePositioning& operator=(const HousePositioning& hp);
        bool operator==(const HousePositioning& hp)const;
        bool operator!=(const HousePositioning& hp)const;

        bool loadFromDB(const QUuid& id);
        bool saveToDB()const;

        static bool CreateTable();
        static bool TableExists();
};

#endif // HOUSEPOSITIONING

