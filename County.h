#ifndef COUNTY
#define COUNTY

#include "Base.h"

class County
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(LocalizedName, Name)

    public:
        County();
        County(const County& county);
        virtual ~County();

        void setName(const QString& name, const QUuid& langId = QUuid());

        County& operator=(const County& county);
        bool operator==(const County& county)const;
        bool operator!=(const County& county)const;
};

#endif // COUNTY

