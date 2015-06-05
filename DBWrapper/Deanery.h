#ifndef DEANERY
#define DEANERY

#include "Base.h"

namespace DBWrapper
{
    class Deanery
    {
        DECLARE_PROPERTY(QUuid, Id)
        DECLARE_PROPERTY_GREF(QString, NameRO)
        DECLARE_PROPERTY_GREF(QString, NameDE)
        DECLARE_PROPERTY_GREF(QString, NameSX)
        DECLARE_PROPERTY_GREF(QString, NameHU)

        public:
            static QString STR_CREATE_TABLE;
            static QString STR_TABLE_NAME;

        public:
            Deanery();
            Deanery(const Deanery& deanery);
            virtual ~Deanery();

            Deanery& operator=(const Deanery& deanery);
            bool operator==(const Deanery& deanery)const;
            bool operator!=(const Deanery& deanery)const;

            static bool CreateTable();
            static bool TableExists();
            bool LoadFromDB();
            bool SaveToDB()const;
            bool ExistsInDB()const;
    };
}

#endif // DEANERY

