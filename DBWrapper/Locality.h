#ifndef LOCALITY
#define LOCALITY

#include "Base.h"
#include "Comune.h"

namespace DBWrapper
{
    class Locality
    {
        DECLARE_PROPERTY(QUuid, Id)
        DECLARE_PROPERTY_GREF(QString, NameRO)
        DECLARE_PROPERTY_GREF(QString, NameDE)
        DECLARE_PROPERTY_GREF(QString, NameSX)
        DECLARE_PROPERTY_GREF(QString, NameHU)
        DECLARE_PROPERTY(QUuid, Comune)

        public:
            static QString STR_CREATE_TABLE;
            static QString STR_TABLE_NAME;

        public:
            Locality();
            Locality(const Locality& loc);
            virtual ~Locality();

            Locality& operator=(const Locality& loc);
            bool operator==(const Locality& loc)const;
            bool operator!=(const Locality& loc)const;

            static bool CreateTable();
            static bool TableExists();
            bool LoadFromDB();
            bool SaveToDB()const;
            bool ExistsInDB()const;
    };
}

#endif // LOCALITY

