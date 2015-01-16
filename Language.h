#ifndef LANGUAGE
#define LANGUAGE

#include "Base.h"

class Language
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY(QString, Name)

    public:
        Language();
        Language(const Language& lang);
        virtual ~Language();

        Language& operator=(const Language& lang);
        bool operator==(const Language& lang)const;
        bool operator!=(const Language& lang)const;

        static QUuid LANGUAGE_ROMANIAN;
        static QUuid LANGUAGE_GERMAN;
        static QUuid LANGUAGE_SAXON;
        static QUuid LANGUAGE_HUNGARIAN;
};



#endif // LANGUAGE

