#include "Comune.h"

QString Comune::STR_CREATE_TABLE = "Create table Comune (\
Id varchar(50) primary key,\
NameRO varchar(255),\
NameDE varchar(255),\
NameSX varchar(255),\
NameHU varchar(255)\
)";

QString Comune::STR_TABLE_NAME = "Comune";

Comune::Comune()
    :   m_Id(QUuid::createUuid()),
        m_NameRO(),
        m_NameDE(),
        m_NameSX(),
        m_NameHU()
{}

Comune::Comune(const Comune& comune)
    :   m_Id(comune.Id()),
        m_NameRO(comune.NameRO()),
        m_NameDE(comune.NameDE()),
        m_NameSX(comune.NameSX()),
        m_NameHU(comune.NameHU())
{}

Comune::~Comune(){}

Comune&
Comune::operator=(const Comune& comune)
{
    m_Id = comune.Id();
    m_NameRO = comune.NameRO();
    m_NameDE = comune.NameDE();
    m_NameSX = comune.NameSX();
    m_NameHU = comune.NameHU();

    return *this;
}

bool
Comune::operator==(const Comune& comune)const
{
    if(m_Id == comune.Id())
        return true;

    return false;
}

bool
Comune::operator!=(const Comune& comune)const
{
    return !(this->operator ==(comune));
}

bool
Comune::CreateTable()
{
    bool result = true;
    RunQuery(Comune::STR_CREATE_TABLE, result);

    return result;
}

bool
Comune::TableExists()
{
    return ::TableExists(Comune::STR_TABLE_NAME);
}
