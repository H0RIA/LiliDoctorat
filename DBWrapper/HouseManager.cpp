#include "DBManager.h"
#include "HouseManager.h"

using namespace DBWrapper;

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

    Comune* comune = createComune();
    if(comune != nullptr){
        comune->setNameRO("ComunaTest");
        comune->setNameDE("TestComune");
        comune->setNameSX("TestenComune");
        comune->setNameHU("TudfighdkjfndComune");
    }

    County* county = createCounty();
    if(county != nullptr){
        county->setNameRO("Sibiu");
    }

    comune->setCounty(county->Id());

    Deanery* dioceza = createDeanery();
    if(dioceza != nullptr){
        dioceza->setNameRO("Smenul de aur");
    }

    Locality* loc = createLocality();
    if(loc != nullptr){
        loc->setNameRO("Sat Test");
        loc->setNameDE("Test Dorf");
        loc->setNameSX("Test Dorfen");
        loc->setNameHU("Test Falu");
        if(county != nullptr){
            loc->setComune(comune->Id());
        }
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
        house->setNameRO("Casa test");
        house->setNameDE("Das test casa");
        house->setNameSX("Das testen casa");
        house->setNameHU("KAEUtidghdtiogheiobnei opsjgdrighd");
        house->setDescription("Test house for Lili");
        house->setHouseDating("Datare inexistenta");
    }
}
