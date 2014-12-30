#ifndef HOUSEMANAGER
#define HOUSEMANAGER

#include "House.h"

class HouseManager
{
    DECLARE_SINGLETON_OBJECT(House)
    DECLARE_SINGLETON_OBJECT(Deanery)
    DECLARE_SINGLETON_OBJECT(Shire)
    DECLARE_SINGLETON_OBJECT(Locality)
    DECLARE_SINGLETON_OBJECT(County)
    DECLARE_SINGLETON_OBJECT(LocationInfo)
    DECLARE_SINGLETON_OBJECT(ImageInfo)
    DECLARE_SINGLETON_OBJECT(PriestInfo)
    DECLARE_SINGLETON_OBJECT(TaxInfo)

    public:
        static HouseManager* instance();
        virtual ~HouseManager();

        House* findHouse(const QString& someText);

    private:
        HouseManager();
        HouseManager(const HouseManager& hm);

    protected:
        void addDefaultData();

    private:
        static HouseManager* m_pInstance;
};

#endif // HOUSEMANAGER

