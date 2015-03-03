#ifndef COUNTY
#define COUNTY

#include "Base.h"

class County
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(LocalizedName, Name)

    public:
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        County();
        County(const County& county);
        virtual ~County();

        void setName(const QString& name, const QUuid& langId = QUuid());

        County& operator=(const County& county);
        bool operator==(const County& county)const;
        bool operator!=(const County& county)const;

        static bool CreateTable();
        static bool TableExists();
};

#endif // COUNTY

