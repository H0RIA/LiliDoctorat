#include "WndEditHouse_TabFunction.h"

using namespace UI;

WndEditHouse_TabFunction::WndEditHouse_TabFunction(const QUuid& houseId, bool newItem, QWidget* parent)
    :   QWidget(parent)
{
}

bool
WndEditHouse_TabFunction::saveToDB()
{
    bool result = false;

    // TODO

    return m_Function.saveToDB();
}

bool
WndEditHouse_TabFunction::loadFromDB(const QUuid& id)
{
    bool result = m_Function.loadFromDB(id);

    // TODO

    return result;
}
