#ifndef LOCALITY
#define LOCALITY

#include "Base.h"
#include "County.h"

class Locality
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(LocalizedName, Name)
    DECLARE_PROPERTY(QUuid, County)

    public:
        Locality();
        Locality(const Locality& loc);
        virtual ~Locality();

        Locality& operator=(const Locality& loc);
        bool operator==(const Locality& loc)const;
        bool operator!=(const Locality& loc)const;
};

#endif // LOCALITY

