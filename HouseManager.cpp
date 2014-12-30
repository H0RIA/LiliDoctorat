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
    while(!m_House_list.isEmpty()){
        House* currentHouse = m_House_list.front();
        m_House_list.pop_front();
        if(currentHouse != nullptr)
            delete currentHouse;
    }
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
        locName[Language::Romanian] = "Sat Test";
        locName[Language::German] = "Test Dorf";
        locName[Language::Hungarian] = "Test Falu";
        locName[Language::Saxon] = "Test Dorfen";
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
        house->setName("Test house");
        house->setDescription("Test house for Lili");
        house->setHouseDating("Datare inexistenta");
    }
}
