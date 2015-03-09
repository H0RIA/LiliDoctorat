#ifndef HOUSEMANAGER
#define HOUSEMANAGER

#include "House.h"

class HouseManager
{
    DECLARE_SINGLETON_OBJECT(House, Houses)
    DECLARE_SINGLETON_OBJECT(Deanery, Deaneries)
    DECLARE_SINGLETON_OBJECT(Comune, Comunes)
    DECLARE_SINGLETON_OBJECT(Locality, Localities)
    DECLARE_SINGLETON_OBJECT(County, Counties)
    DECLARE_SINGLETON_OBJECT(LocationInfo, Locations)
    DECLARE_SINGLETON_OBJECT(ImageInfo, Images)
    DECLARE_SINGLETON_OBJECT(PriestInfo, Priests)
    DECLARE_SINGLETON_OBJECT(TaxInfo, Taxes)

    public:
        static QString STR_CREATE_TABLE;

    public:
        static HouseManager* instance();
        virtual ~HouseManager();

        House* findHouse(const QString& someText);

        void reloadFromDatabase();
        void saveToDatabase();

    private:
        HouseManager();
        HouseManager(const HouseManager& hm);

    protected:
        void addDefaultData();

    private:
        static HouseManager* m_pInstance;
};

#endif // HOUSEMANAGER

