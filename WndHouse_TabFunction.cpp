#include "WndHouse_TabFunction.h"

WndHouse_TabFunction::WndHouse_TabFunction(QWidget* parent)
    :   QWidget(parent)
{
}

bool
WndHouse_TabFunction::saveToDB()
{
    bool result = false;

    // TODO

    return m_Function.saveToDB();
}

bool
WndHouse_TabFunction::loadFromDB(const QUuid& id)
{
    bool result = m_Function.loadFromDB(id);

    // TODO

    return result;
}
