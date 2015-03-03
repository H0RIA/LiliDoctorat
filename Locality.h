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
};

#endif // LOCALITY

