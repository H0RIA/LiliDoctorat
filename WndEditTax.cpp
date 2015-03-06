#include "TaxInfo.h"
#include "WndEditTax.h"

using namespace UI;

WndEditTax::WndEditTax(QWidget* parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_TaxId(QUuid::createUuid())
{    
    initializeData();
}

WndEditTax::WndEditTax(const QUuid& taxId, QWidget* parent)
    :   QDialog(parent),
        m_NewItem(taxId.isNull() ? true : false),
        m_TaxId(taxId.isNull() ? QUuid::createUuid() : taxId)
{
    initializeData();
}

WndEditTax::~WndEditTax()
{
}

void
WndEditTax::initializeData()
{
    if(!m_NewItem)
        loadFromDB();
}

void
WndEditTax::loadFromDB(const QUuid& id)
{
    if(!id.isNull())
        m_TaxId = id;
}

void
WndEditTax::saveToDB()
{
    // TODO
}
