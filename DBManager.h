#ifndef DBMANAGER
#define DBMANAGER

#include "Language.h"

#define DEFAULT_SQLITE_PATH "./LCP.sqlite"

class DBManager
{
    DECLARE_SINGLETON_OBJECT(Language, Languages)

    public:
        static DBManager* instance();
        virtual ~DBManager();

        Language* findLanguage(const QString& name);

        void clearData();
        void loadData();
        void saveData();

        void loadLanguages();
        void saveLanguages();

    protected:
        bool createDatabase();
        bool createTables();

        DBManager();
        DBManager(const DBManager& dbm);

        DBManager& operator=(const DBManager& dbm);

    protected:
        QSqlDatabase* m_pDatabase;

    private:
        static DBManager* m_pInstance;

};

#endif // DBMANAGER

