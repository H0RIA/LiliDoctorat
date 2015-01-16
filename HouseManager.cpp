#include "DBManager.h"
#include "HouseManager.h"

HouseManager* HouseManager::m_pInstance = nullptr;

HouseManager*
HouseManager::instance()
{
    if(m_pInstance == nullptr){
        m_pInstance = new HouseManager();

        // TODO ???
    }

    return m_pInstance;
}

HouseManager::~HouseManager()
{
    // TODO ???
    while(!m_Houses.isEmpty()){
        House* currentHouse = m_Houses.front();
        m_Houses.pop_front();
        if(currentHouse != nullptr)
            delete currentHouse;
    }
}

void
HouseManager::reloadFromDatabase()
{
    // TODO
}

void
HouseManager::saveToDatabase()
{
    // TODO
}

HouseManager::HouseManager()
{
    // TODO
    addDefaultData();
}

HouseManager::HouseManager(const HouseManager& hm)
{
    Q_UNUSED(hm)
}

void
HouseManager::addDefaultData()
{
    PriestInfo* pi = createPriestInfo();
    if(pi != nullptr){
        pi->setFirstName("Eufigeniu");
        pi->setLastName("Agamemnon");
    }

    County* county = createCounty();
    if(county != nullptr){
        county->setName("Sibiu");
    }

    Deanery* dioceza = createDeanery();
    if(dioceza != nullptr){
        dioceza->setName("Smenul de aur");
    }

    Locality* loc = createLocality();
    if(loc != nullptr){
        LocalizedName locName;
        Language* lang = DBManager::instance()->findLanguage(QString("Romanian"));
        if(lang != nullptr)
            locName[lang->Id()] = "Sat Test";

        lang = DBManager::instance()->findLanguage(QString("German"));
        if(lang != nullptr)
            locName[lang->Id()] = "Test Dorf";

        lang = DBManager::instance()->findLanguage(QString("Hungarian"));
        if(lang != nullptr)
            locName[lang->Id()] = "Test Falu";

        lang = DBManager::instance()->findLanguage(QString("Saxon"));
        if(lang != nullptr)
            locName[lang->Id()] = "Test Dorfen";

        loc->setName(locName);
        if(county != nullptr){
            loc->setCounty(county->Id());
        }
    }

    Shire* shire = createShire();
    if(shire != nullptr){
        shire->setName("Testenshire");
    }

    TaxInfo* ti = createTaxInfo();
    if(ti != nullptr){
        ti->setDescription("Taxa pe smen");
        ti->setName("SmenTax");
        ti->setFormula("Se ia valoarea S de smen si se inmulteste cu valoarea V de valoare. Rezultatul se varsa la buget.");
    }

    auto ii = createImageInfo();
    if(ii != nullptr){
        ii->setName("Test image");
        ii->setDetails("Aceasta poza reprezinta un detaliu al smenurilor");
        ii->setPath("C:\\Users\\Horia_2\\Downloads\\img_5441250ec6518.jpg");
    }

    House* house = createHouse();
    if(house != nullptr){
        house->addImageInfo(ii);
        LocalizedName name;
        name[Language::LANGUAGE_ROMANIAN] = "Casa test";
        name[Language::LANGUAGE_GERMAN] = "Das test casa";
        house->setName(name);
        house->setDescription("Test house for Lili");
        house->setHouseDating("Datare inexistenta");
    }
}
