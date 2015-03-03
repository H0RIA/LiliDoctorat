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
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        TaxInfo();
        TaxInfo(const TaxInfo& ti);
        virtual ~TaxInfo();

        TaxInfo& operator=(const TaxInfo& ti);
        bool operator==(const TaxInfo& ti)const;
        bool operator!=(const TaxInfo& ti)const;

        static bool CreateTable();
        static bool TableExists();
};

#endif // TAXINFO

