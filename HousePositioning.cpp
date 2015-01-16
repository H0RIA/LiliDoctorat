#include "HousePositioning.h"

OutHouses::OutHouses()
    :   m_StillExisting(),
        m_Destroyed()
{}

OutHouses::OutHouses(const OutHouses& oh)
    :   m_StillExisting(oh.StillExisting()),
        m_Destroyed(oh.Destroyed())
{}

OutHouses::~OutHouses(){}

OutHouses&
OutHouses::operator=(const OutHouses& oh)
{
    m_StillExisting = oh.StillExisting();
    m_Destroyed = oh.Destroyed();

    return *this;
}

bool
OutHouses::operator==(const OutHouses& oh)const
{
    if(m_StillExisting.count() == oh.StillExisting().count()){
        // TODO
        int currentIndex = 0;
        for(currentIndex = 0; currentIndex < m_StillExisting.count(); currentIndex++){
            if(!oh.StillExisting().contains(m_StillExisting.at(currentIndex)))
                return false;
        }

        if(m_Destroyed.count() == oh.Destroyed().count()){
            for(currentIndex = 0; currentIndex < m_Destroyed.count(); currentIndex++){
                if(!oh.Destroyed().contains(m_Destroyed.at(currentIndex)))
                    return false;
            }

        }

        return true;
    }

    return false;
}

bool
OutHouses::operator!=(const OutHouses& oh)const
{
    return !(this->operator ==(oh));
}


HousePositioning::HousePositioning()
    :   m_Id(QUuid::createUuid()),
        m_FromChurch(),
        m_FromRoad(),
        m_FromGarden(),
        m_Declivity(),
        m_Outhouses()
{}

HousePositioning::HousePositioning(const HousePositioning& hp)
    :   m_Id(hp.Id()),
        m_FromChurch(hp.FromChurch()),
        m_FromRoad(hp.FromRoad()),
        m_FromGarden(hp.FromGarden()),
        m_Declivity(hp.Declivity()),
        m_Outhouses(hp.Outhouses())
{}

HousePositioning::~HousePositioning(){}

HousePositioning&
HousePositioning::operator=(const HousePositioning& hp)
{
    m_Id = hp.Id();
    m_FromChurch = hp.FromChurch();
    m_FromRoad = hp.FromRoad();
    m_FromGarden = hp.FromGarden();
    m_Declivity = hp.Declivity();
    m_Outhouses = hp.Outhouses();

    return *this;
}

bool
HousePositioning::operator==(const HousePositioning& hp)const
{
    return m_Id == hp.Id();
}

bool
HousePositioning::operator!=(const HousePositioning& hp)const
{
    return !(this->operator ==(hp));
}

bool
HousePositioning::loadFromDB(const QUuid& id)
{
    bool result = false;

    if(id.isNull())
        return result;

    // TODO

    return result;
}

bool
HousePositioning::saveToDB()const
{
    bool result = false;

    if(Id().isNull()){
        // Create new entry => Insert in SQL
    }else{
        // Save changes => Update in SQL
    }

    return result;
}
