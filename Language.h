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
};

#endif // LANGUAGE

