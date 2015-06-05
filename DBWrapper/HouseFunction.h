#ifndef HOUSEFUNCTION
#define HOUSEFUNCTION

#include "Base.h"

namespace DBWrapper
{
    enum class HouseLegalStatus : quint8
    {
        EvangelicalChurch,
        OtherCults,
        PrivateProperty,
        DoesNotExist
    };

    class HouseFunction
    {
        DECLARE_PROPERTY(QUuid, Id)
        DECLARE_PROPERTY(QString, Original)
        DECLARE_PROPERTY(QString, Current)
        DECLARE_PROPERTY(HouseLegalStatus, LegalStatus)

        public:
            static QString STR_CREATE_TABLE;
            static QString STR_TABLE_NAME;

        public:
            HouseFunction();
            HouseFunction(const HouseFunction& hf);
            virtual ~HouseFunction();

            HouseFunction& operator=(const HouseFunction& hf);
            bool operator==(const HouseFunction& hf)const;
            bool operator!=(const HouseFunction& hf)const;

            bool saveToDB();
            bool loadFromDB(const QUuid& id);
            bool ExistsInDB()const;

            static bool CreateTable();
            static bool TableExists();
    };
}

#endif // HOUSEFUNCTION

