#include "WndEditHouse_TabPositioning.h"

using namespace UI;

WndEditHouse_TabPositioning::WndEditHouse_TabPositioning(const QUuid& houseId, bool newItem, QWidget* parent)
    :   QWidget(parent),
        m_Positioning()
{
//    if(!idPositioning.isNull())
//        m_Positioning.loadFromDB(idPositioning);
}

bool
WndEditHouse_TabPositioning::saveToDB()
{
    return m_Positioning.saveToDB();
}

bool
WndEditHouse_TabPositioning::loadFromDB(const QUuid& idPositioning)
{
    if(idPositioning.isNull())
        return false;

    return m_Positioning.loadFromDB(idPositioning);

}
