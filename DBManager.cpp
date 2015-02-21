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

void
DBManager::clearData()
{
    clearLanguages();
}

void
DBManager::loadData()
{
    loadLanguages();
}

void
DBManager::saveData()
{
    saveLanguages();
}

void
DBManager::loadLanguages()
{
    if(m_pDatabase == nullptr)
        return;

    if(!m_pDatabase->isOpen() || m_pDatabase->isOpenError())
        return;

    QSqlQuery query(*m_pDatabase);
    if(query.exec("Select * From Languages")){

    }

    // TODO
    Language::LANGUAGE_ROMANIAN = QUuid::createUuid();
    Language::LANGUAGE_GERMAN = QUuid::createUuid();
    Language::LANGUAGE_SAXON = QUuid::createUuid();
    Language::LANGUAGE_HUNGARIAN = QUuid::createUuid();

}

void
DBManager::saveLanguages()
{
    // TODO
}

bool
DBManager::createDatabase()
{
    if(m_pDatabase != nullptr)
        return false;

    *m_pDatabase = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QDir::toNativeSeparators(DEFAULT_SQLITE_PATH);
    m_pDatabase->setDatabaseName(path);

    return m_pDatabase->open();
}

bool
DBManager::createTables()
{
    if(m_pDatabase == nullptr)
        return false;

    if(!m_pDatabase->isOpen()){
        if(!m_pDatabase->open())
            return false;
    }

    bool result = true;

    // Create the locality table
    {
        QSqlQuery query;
        QString strQuery = "Create table Locality (\
Id varchar(50) primary key,\
IdLocale varchar(50),\
LocalizedName varchar(255),\
IdCounty varchar(50))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the language table
    {
        QSqlQuery query;
        QString strQuery = "Create table Language (\
Id varchar(50) primary key,\
Name varchar(255))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the Priest table
    {
        QSqlQuery query;
        QString strQuery = "Create table Priest (\
Id varchar(50) primary key,\
FirstName varchar(255),\
LastName varchar(255))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the Shire table
    {
        QSqlQuery query;
        QString strQuery = "Create table Shire (\
Id varchar(50) primary key,\
IdLocale varchar(50),\
LocalizedName varchar(255))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the County table
    {
        QSqlQuery query;
        QString strQuery = "Create table County (\
Id varchar(50) primary key,\
IdLocale varchar(50),\
LocalizedName varchar(255))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the TaxInfo table
    {
        QSqlQuery query;
        QString strQuery = "Create table TaxInfo (\
Id varchar(50) primary key,\
Name varchar(255),\
Description text,\
Formula text)";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the ImageInfo table
    {
        QSqlQuery query;
        QString strQuery = "Create table ImageInfo (\
Id varchar(50) primary key,\
Path varchar(512),\
Name varchar(50),\
Details text)";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the LocationInfo table
    {
        QSqlQuery query;
        QString strQuery = "Create table LocationInfo (\
Id varchar(50) primary key,\
IdLocale varchar(50),\
LocalizedName varchar(255),\
IdComune varchar(50),\
IdDeanery varchar(50),\
InventoryDate date,\
OldStatus text)";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the HousePositioning table
    {
        QSqlQuery query;
        QString strQuery = "Create table HousePositioning (\
Id varchar(50) primary key,\
FromChurch text,\
FromRoad text,\
FromGarden text,\
Declivity text)";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the HouseFunction table
    {
        QSqlQuery query;
        QString strQuery = "Create table HouseFunction (\
Id varchar(50) primary key,\
Original text,\
Current text,\
LegalStatus int)";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the BuildingInfo table
    {
        QSqlQuery query;
        QString strQuery = "Create table BuildingInfo (\
Id varchar(50) primary key,\
Shape text,\
RoomPlacement text,\
RoomCount int,\
FrontFloorCount int,\
BackFloorCount int,\
FrontBay text,\
SideBay text,\
BuildDate date,\
ArchitecturalStyle text,\
Doors text,\
Windows text,\
BasementVault text,\
Roof text,\
Ceiling text,\
Pinion text)";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the House table
    {
        QSqlQuery query;
        QString strQuery = "Create table House (\
Id varchar(50) primary key,\
IdLocale varchar(50),\
LocalizedName varchar(255),\
Description text,\
IdLocation varchar(50),\
HouseDating text,\
IdBuildingInfo varchar(50),\
IdHouseFunction varchar(50),\
IdHousePositioning varchar(50))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the HousePriests table
    {
        QSqlQuery query;
        QString strQuery = "Create table HousePriests (\
IdHouse varchar(50),\
IdPriest varchar(50))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the HouseTaxes table
    {
        QSqlQuery query;
        QString strQuery = "Create table HouseTaxes (\
IdHouse varchar(50),\
IdTax varchar(50))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    // Create the HouseImages table
    {
        QSqlQuery query;
        QString strQuery = "Create table HouseImages (\
IdHouse varchar(50),\
IdImage varchar(50))";
        bool tempResult = query.exec(strQuery);
        result = !result ? false : tempResult;
    }

    return result;
}

DBManager::DBManager()
    :   m_pDatabase(nullptr)
{
    bool howAreWe = true;

    if(createDatabase()){
        howAreWe = createTables();
    }else
        howAreWe = false;

    if(!howAreWe){
        QMessageBox::critical(0, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish a database connection.\n"
                                 "This example needs SQLite support. Please read "
                                 "the Qt SQL driver documentation for information how "
                                 "to build it."), QMessageBox::Cancel);
        return;
    }

    loadData();
}

DBManager::DBManager(const DBManager& dbm)
    :   m_pDatabase(nullptr)
{
    Q_UNUSED(dbm);

    loadData();
}

DBManager&
DBManager::operator=(const DBManager& dbm)
{
    Q_UNUSED(dbm);

    return *this;
}
