#ifndef PRIESTINFO
#define PRIESTINFO

#include "Base.h"

class PriestInfo
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY(QString, FirstName)
    DECLARE_PROPERTY(QString, LastName)

    public:
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        DECLARE_DEF_METHODS(PriestInfo)

        PriestInfo& operator=(const PriestInfo& pi);
        bool operator==(const PriestInfo& pi)const;
        bool operator!=(const PriestInfo& pi)const;

        static bool CreateTable();
        static bool TableExists();
        bool LoadFromDB();
        bool SaveToDB()const;
        bool ExistsInDB()const;
};

class PriestTenure
{
    DECLARE_PROPERTY_GREF(QUuid, Id)
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

        PriestTenure& operator=(const PriestTenure& pt);
        bool operator==(const PriestTenure& pt)const;
        bool operator!=(const PriestTenure& pt)const;
};

#endif // PRIESTINFO

