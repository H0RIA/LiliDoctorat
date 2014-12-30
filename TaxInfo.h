#ifndef TAXINFO
#define TAXINFO

#include "Base.h"

class TaxInfo
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY(QString, Name)
    DECLARE_PROPERTY(QString, Description)
    DECLARE_PROPERTY(QString, Formula)

    public:
        TaxInfo();
        TaxInfo(const TaxInfo& ti);
        virtual ~TaxInfo();

        TaxInfo& operator=(const TaxInfo& ti);
        bool operator==(const TaxInfo& ti)const;
        bool operator!=(const TaxInfo& ti)const;
};

#endif // TAXINFO

