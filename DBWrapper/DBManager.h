#ifndef DBMANAGER
#define DBMANAGER

#include "TaxInfo.h"
#include "Language.h"

//#define DEFAULT_SQLITE_PATH "./LCP.sqlite"
#define DEFAULT_SQLITE_NAME "LCP.sqlite"

namespace DBWrapper
{
    class DBManager
    {
        DECLARE_SINGLETON_OBJECT(Language, Languages)

        public:
            static DBManager* instance();
            virtual ~DBManager();

            Language* findLanguage(const QString& name);

            QList<TaxInfo> findTaxByName(const QString& name);
            QList<TaxInfo> findTaxByDescr(const QString& descr);
            QList<TaxInfo> findTaxByFormula(const QString& formula);
            QList<TaxInfo> findTax(const QString& data);
            TaxInfo findTax(const QUuid& id);

            void clearData();
            void loadData();
            void saveData();

            void loadLanguages();
            void saveLanguages();

            void loadTaxes();
            void saveTaxes()const;

            QSqlDatabase* getDatabase();

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
            QList<TaxInfo> m_Taxes;

    };
}

#endif // DBMANAGER

