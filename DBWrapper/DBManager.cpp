#include "TaxInfo.h"
#include "Locality.h"
#include "Language.h"
#include "PriestInfo.h"
#include "County.h"
#include "Comune.h"
#include "Deanery.h"
#include "ImageInfo.h"
#include "HousePositioning.h"
#include "HouseFunction.h"
#include "BuildingInfo.h"
#include "House.h"
#include "DBManager.h"

using namespace DBWrapper;

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

QList<TaxInfo>
DBManager::findTaxByName(const QString& name)
{
    QList<TaxInfo> result;

    if(name.isEmpty())
        return result;

    foreach(const TaxInfo& tax, m_Taxes){
        if(tax.Name().contains(name))
            result.append(tax);
    }

    return result;
}

QList<TaxInfo>
DBManager::findTaxByDescr(const QString& descr)
{
    QList<TaxInfo> result;

    if(descr.isEmpty())
        return result;

    foreach(const TaxInfo& tax, m_Taxes){
        if(tax.Description().contains(descr))
            result.append(tax);
    }

    return result;
}

QList<TaxInfo>
DBManager::findTaxByFormula(const QString& formula)
{
    QList<TaxInfo> result;

    if(formula.isEmpty())
        return result;

    foreach(const TaxInfo& tax, m_Taxes){
        if(tax.Formula().contains(formula))
            result.append(tax);
    }

    return result;
}

QList<TaxInfo>
DBManager::findTax(const QString& data)
{
    QList<TaxInfo> result;

    if(data.isEmpty())
        return result;

    foreach(const TaxInfo& tax, m_Taxes){
        if(tax.Name().contains(data)
            || tax.Description().contains(data)
            || tax.Formula().contains(data))
            result.append(tax);
    }

    return result;
}

TaxInfo
DBManager::findTax(const QUuid& id)
{
    TaxInfo tax;

    if(id.isNull())
        return tax;

    foreach(const TaxInfo& taxInfo, m_Taxes){
        if(taxInfo.Id() == id)
            return taxInfo;
    }

    return tax;
}

void
DBManager::clearData()
{
    clearLanguages();
}

void
DBManager::loadData()
{
    loadTaxes();
    loadLanguages();
}

void
DBManager::saveData()
{
    saveTaxes();
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

void
DBManager::loadTaxes()
{
    QString strQuery = "Select * From TaxInfo;";
    QSqlQuery query(strQuery);
    while(query.next()){
        TaxInfo tax;
        tax.setId(QUuid(query.value("Id").toString()));
        tax.setName(query.value("Name").toString());
        tax.setDescription(query.value("Description").toString());
        tax.setFormula(query.value("Formula").toString());

        m_Taxes.append(tax);
    }
}

void
DBManager::saveTaxes()const
{
    foreach(const TaxInfo& tax, m_Taxes)
        tax.SaveToDB();
}

QSqlDatabase*
DBManager::getDatabase()
{
    return m_pDatabase;
}

bool
DBManager::createDatabase()
{
    if(m_pDatabase != nullptr)
        return false;

    QStringList strPathToDB = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    if(strPathToDB.isEmpty()){
        QMessageBox::critical(0, QObject::tr("Cannot create database"),
                              QObject::tr("Unable to create a SQLite database file.\n"), QMessageBox::Cancel);
        qApp->exit();
    }

    QString firstPath = strPathToDB.front();
    m_pDatabase = new QSqlDatabase();
    *m_pDatabase = QSqlDatabase::addDatabase("QSQLITE");
    firstPath += QDir::separator();
    QDir dir(firstPath);
    dir.mkpath(firstPath);
    firstPath += DEFAULT_SQLITE_NAME;
    m_pDatabase->setDatabaseName(firstPath);

    if(!m_pDatabase->open()){
        QMessageBox::critical(0, QObject::tr("Cannot open database"),
                              m_pDatabase->lastError().text(), QMessageBox::Cancel);
        qDebug() << m_pDatabase->lastError().text();
        qApp->exit();
        return false;
    }

    return true;
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

    // First we enable foreign keys
    QString strQuery = "PRAGMA foreign_keys = ON;";
    RunQuery(strQuery, result);

    // Create the language table
    if(!Language::TableExists())
        result = !result ? false : Language::CreateTable();

    // Create the Priest table
    if(!PriestInfo::TableExists())
        result = !result ? false : PriestInfo::CreateTable();

    // Create the County table
    if(!County::TableExists())
        result = !result ? false : County::CreateTable();

    // Create the Comune table
    if(!Comune::TableExists())
        result = !result ? false : Comune::CreateTable();

    // Create the Deanery table
    if(!Deanery::TableExists())
        result = !result ? false : Deanery::CreateTable();

    // Create the locality table
    if(!Locality::TableExists())
        result = !result ? false : Locality::CreateTable();

    // Create the TaxInfo table
    if(!TaxInfo::TableExists())
        result = !result ? false : TaxInfo::CreateTable();

    // Create the ImageInfo table
    if(!ImageInfo::TableExists())
        result = !result ? false : ImageInfo::CreateTable();

    // Create the HousePositioning table
    if(!HousePositioning::TableExists())
        result = !result ? false : HousePositioning::CreateTable();

    // Create the HouseFunction table
    if(!HouseFunction::TableExists())
        result = !result ? false : HouseFunction::CreateTable();

    // Create the BuildingInfo table
    if(!BuildingInfo::TableExists())
        result = !result ? false : BuildingInfo::CreateTable();

    // Create the House table
    if(!House::TableExists())
        result = !result ? false : House::CreateTable();

    // Create the HousePriests table
    if(!PriestTenure::TableExists())
        result = !result ? false : PriestTenure::CreateTable();

    // Create the HouseTaxes table
    if(! ::TableExists("HouseTaxes")){
        strQuery = "Create table HouseTaxes (IdHouse varchar(50),IdTax varchar(50),FOREIGN KEY(IdHouse) REFERENCES House(Id),FOREIGN KEY(IdTax) REFERENCES TaxInfo(Id))";
        RunQuery(strQuery, result);
    }

    // Create the HouseImages table
    if(! ::TableExists("HouseImages")){
        strQuery = "Create table HouseImages (IdHouse varchar(50),IdImage varchar(50),FOREIGN KEY(IdHouse) REFERENCES House(Id),FOREIGN KEY(IdImage) REFERENCES ImageInfo(Id))";
        RunQuery(strQuery, result);
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
