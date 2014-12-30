#ifndef HOUSEFUNCTION
#define HOUSEFUNCTION

#include "Base.h"

enum class HouseLegalStatus : quint8
{
    EvangelicalChurch,
    OtherCults,
    PrivateProperty,
    DoesNotExist
};

class HouseFunction
{
    DECLARE_PROPERTY(QString, Original)
    DECLARE_PROPERTY(QString, Current)
    DECLARE_PROPERTY(HouseLegalStatus, LegalStatus)

    public:
        HouseFunction();
        HouseFunction(const HouseFunction& hf);
        virtual ~HouseFunction();

        HouseFunction& operator=(const HouseFunction& hf);
        bool operator==(const HouseFunction& hf)const;
        bool operator!=(const HouseFunction& hf)const;
};

#endif // HOUSEFUNCTION

