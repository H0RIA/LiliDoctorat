#ifndef PRIESTINFO
#define PRIESTINFO

#include "Base.h"

namespace DBWrapper
{
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
}

#endif // PRIESTINFO

