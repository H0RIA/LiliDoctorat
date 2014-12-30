#ifndef SHIRE
#define SHIRE

#include "Base.h"

class Shire
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(LocalizedName, Name)

    public:
        Shire();
        Shire(const Shire& shire);
        virtual ~Shire();

        void setName(const QString& name, Language lang = Language::Romanian);

        Shire& operator=(const Shire& shire);
        bool operator==(const Shire& shire)const;
        bool operator!=(const Shire& shire)const;
};

#endif // SHIRE

