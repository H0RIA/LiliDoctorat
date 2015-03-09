#ifndef COUNTY
#define COUNTY

#include "Base.h"

class County
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
        County();
        County(const County& county);
        virtual ~County();

        County& operator=(const County& county);
        bool operator==(const County& county)const;
        bool operator!=(const County& county)const;

        static bool CreateTable();
        static bool TableExists();
        bool LoadFromDB();
        bool SaveToDB()const;
        bool ExistsInDB()const;
};

#endif // COUNTY

