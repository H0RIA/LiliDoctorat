#include "WndHouse_TabPositioning.h"

WndHouse_TabPositioning::WndHouse_TabPositioning(QWidget* parent, const QUuid& idPositioning)
    :   QWidget(parent),
        m_Positioning()
{
    if(!idPositioning.isNull())
        m_Positioning.loadFromDB(idPositioning);
}

bool
WndHouse_TabPositioning::saveToDB()
{
    return m_Positioning.saveToDB();
}

bool
WndHouse_TabPositioning::loadFromDB(const QUuid& idPositioning)
{
    if(idPositioning.isNull())
        return false;

    return m_Positioning.loadFromDB(idPositioning);

}
