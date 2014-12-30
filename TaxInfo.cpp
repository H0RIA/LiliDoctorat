#include "TaxInfo.h"

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
