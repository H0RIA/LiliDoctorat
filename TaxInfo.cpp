#include "TaxInfo.h"

QString TaxInfo::STR_CREATE_TABLE = "Create table TaxInfo (\
Id varchar(50) primary key,\
Name varchar(255),\
Description text,\
Formula text)";

QString TaxInfo::STR_TABLE_NAME = "TaxInfo";

TaxInfo::TaxInfo()
    :   m_Name(),
        m_Description(),
        m_Formula()
{}

TaxInfo::TaxInfo(const TaxInfo& ti)
    :   m_Name(ti.Name()),
        m_Description(ti.Description()),
        m_Formula(ti.Formula())
{}

TaxInfo::~TaxInfo(){}

TaxInfo&
TaxInfo::operator=(const TaxInfo& ti)
{
    m_Name = ti.Name();
    m_Description = ti.Description();
    m_Formula = ti.Formula();

    return *this;
}

bool
TaxInfo::operator==(const TaxInfo& ti)const
{
    if(m_Name == ti.Name() && m_Description == ti.Description() && m_Formula == ti.Formula())
        return true;

    return false;
}

bool
TaxInfo::operator!=(const TaxInfo& ti)const
{
    return !(this->operator ==(ti));
}

bool
TaxInfo::CreateTable()
{
    bool result = true;
    RunQuery(TaxInfo::STR_CREATE_TABLE, result);

    return result;
}

bool
TaxInfo::TableExists()
{
    return ::TableExists(TaxInfo::STR_TABLE_NAME);
}
