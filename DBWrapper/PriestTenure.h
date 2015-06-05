#ifndef PRIESTTENURE
#define PRIESTTENURE

#include "Base.h"

namespace DBWrapper
{
    class PriestTenure
    {
        DECLARE_PROPERTY_GREF(QUuid, Id)
        DECLARE_PROPERTY_GREF(QUuid, HouseId)
        DECLARE_PROPERTY_GREF(QUuid, PriestId)
        DECLARE_PROPERTY_GREF(QDate, Start)
        DECLARE_PROPERTY_GREF(QDate, End)

        public:
            static QString STR_CREATE_TABLE;
            static QString STR_TABLE_NAME;

        public:
            PriestTenure();
            PriestTenure(const PriestTenure& pt);
            virtual ~PriestTenure();

            static bool CreateTable();
            static bool TableExists();
            bool LoadFromDB();
            bool SaveToDB()const;
            bool ExistsInDB()const;

            PriestTenure& operator=(const PriestTenure& pt);
            bool operator==(const PriestTenure& pt)const;
            bool operator!=(const PriestTenure& pt)const;
    };
}

#endif // PRIESTTENURE

