#ifndef DEANERY
#define DEANERY

#include "Base.h"

class Deanery
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY_GREF(LocalizedName, Name)

    public:
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        Deanery();
        Deanery(const Deanery& deanery);
        virtual ~Deanery();

        void setName(const QString& name, const QUuid& langId = QUuid());

        Deanery& operator=(const Deanery& deanery);
        bool operator==(const Deanery& deanery)const;
        bool operator!=(const Deanery& deanery)const;

        static bool CreateTable();
        static bool TableExists();
};

#endif // DEANERY

