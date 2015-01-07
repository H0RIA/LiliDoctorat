#ifndef DBMANAGER
#define DBMANAGER

#include "Language.h"

class DBManager
{
    DECLARE_SINGLETON_OBJECT(Language, Languages)

    public:
        static DBManager* instance();
        virtual ~DBManager();

        Language* findLanguage(const QString& name);
//        const Language* findLanguage(const QString& name)const;

    protected:
        DBManager();
        DBManager(const DBManager& dbm);

        DBManager& operator=(const DBManager& dbm);

    protected:
        QSqlDatabase* m_pDatabase;

    private:
        static DBManager* m_pInstance;

};

#endif // DBMANAGER

