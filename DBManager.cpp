#include "DBManager.h"

DBManager* DBManager::m_pInstance = nullptr;

DBManager*
DBManager::instance()
{
    if(m_pInstance == nullptr){
        m_pInstance = new DBManager();
    }

    return m_pInstance;
}

DBManager::~DBManager()
{
    // TODO
}

Language*
DBManager::findLanguage(const QString& name)
{
    Language* lang = nullptr;

    if(name.isEmpty() || m_Languages.isEmpty())
        return lang;

    foreach (Language* currentLang, m_Languages) {
        if(currentLang != nullptr){
            if(currentLang->Name() == name){
                lang = currentLang;
                break;
            }
        }
    }

    return lang;
}

//const Language*
//DBManager::findLanguage(const QString& name)const
//{
//    const Language* lang = nullptr;

//    if(name.isEmpty() || m_Languages.isEmpty())
//        return lang;

//    foreach (const Language* currentLang, m_Languages) {
//        if(currentLang != nullptr){
//            if(currentLang->Name() == name){
//                lang = currentLang;
//                break;
//            }
//        }
//    }

//    return lang;
//}

DBManager::DBManager()
    :   m_pDatabase(nullptr)
{
    m_pDatabase = new QSqlDatabase();
    if(m_pDatabase != nullptr){
        (*m_pDatabase) = QSqlDatabase::addDatabase("QSQLITE");
    }

    m_pDatabase->setDatabaseName("./LCP.sqlite");
    if(!m_pDatabase->open()){
        QMessageBox::critical(0, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish a database connection.\n"
                                 "This example needs SQLite support. Please read "
                                 "the Qt SQL driver documentation for information how "
                                 "to build it."), QMessageBox::Cancel);
        return;
    }
}

DBManager::DBManager(const DBManager& dbm)
    :   m_pDatabase(nullptr)
{
    Q_UNUSED(dbm);
}

DBManager&
DBManager::operator=(const DBManager& dbm)
{
    Q_UNUSED(dbm);

    return *this;
}
