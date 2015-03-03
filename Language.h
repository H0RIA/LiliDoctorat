#ifndef LANGUAGE
#define LANGUAGE

#include "Base.h"

class Language
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY(QString, Name)

    public:
        static QString STR_CREATE_TABLE;
        static QString STR_TABLE_NAME;

    public:
        Language();
        Language(const Language& lang);
        virtual ~Language();

        Language& operator=(const Language& lang);
        bool operator==(const Language& lang)const;
        bool operator!=(const Language& lang)const;

        static bool CreateTable();
        static bool TableExists();

        static QUuid LANGUAGE_ROMANIAN;
        static QUuid LANGUAGE_GERMAN;
        static QUuid LANGUAGE_SAXON;
        static QUuid LANGUAGE_HUNGARIAN;
};



#endif // LANGUAGE

