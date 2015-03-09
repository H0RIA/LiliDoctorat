#ifndef COMUNE
#define COMUNE

#include "Base.h"

class Comune
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(QString, NameRO)
    DECLARE_PROPERTY_GREF(QString, NameDE)
    DECLARE_PROPERTY_GREF(QString, NameSX)
    DECLARE_PROPERTY_GREF(QString, NameHU)
    DECLARE_PROPERTY(QUuid, County)

    public:
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        Comune();
        Comune(const Comune& comune);
        virtual ~Comune();

        Comune& operator=(const Comune& comune);
        bool operator==(const Comune& comune)const;
        bool operator!=(const Comune& comune)const;

        static bool CreateTable();
        static bool TableExists();
        bool LoadFromDB();
        bool SaveToDB()const;
        bool ExistsInDB()const;
};

#endif // COMUNE

