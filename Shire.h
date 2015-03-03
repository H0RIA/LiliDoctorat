#ifndef SHIRE
#define SHIRE

#include "Base.h"

class Shire
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(LocalizedName, Name)

    public:
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        Shire();
        Shire(const Shire& shire);
        virtual ~Shire();

        void setName(const QString& name, const QUuid& langId = QUuid());

        Shire& operator=(const Shire& shire);
        bool operator==(const Shire& shire)const;
        bool operator!=(const Shire& shire)const;

        static bool CreateTable();
        static bool TableExists();
};

#endif // SHIRE

