#include "LocationInfo.h"

QString LocationInfo::STR_CREATE_TABLE = "Create table LocationInfo (\
Id varchar(50) primary key,\
NameRO varchar(255),\
NameDE varchar(255),\
NameSX varchar(255),\
NameHU varchar(255),\
IdLocality varchar(50),\
IdDeanery varchar(50),\
InventoryDate date,\
OldStatus text,\
FOREIGN KEY(IdLocality) REFERENCES Locality(Id),\
FOREIGN KEY(IdDeanery) REFERENCES Deanery(Id))";
QString LocationInfo::STR_TABLE_NAME = "LocationInfo";

LocationInfo::LocationInfo()
    :   m_Id(QUuid::createUuid()),
        m_NameRO(),
        m_NameDE(),
        m_NameSX(),
        m_NameHU(),
        m_DeaneryInfo(),
        m_InventoryDate(),
        m_OldStatus()
{}

LocationInfo::LocationInfo(const LocationInfo& li)
    :   m_Id(li.Id()),
        m_NameRO(li.NameRO()),
        m_NameDE(li.NameDE()),
        m_NameSX(li.NameSX()),
        m_NameHU(li.NameHU()),
        m_DeaneryInfo(li.DeaneryInfo()),
        m_InventoryDate(li.InventoryDate()),
        m_OldStatus(li.OldStatus())
{}

LocationInfo::~LocationInfo(){}

LocationInfo&
LocationInfo::operator=(const LocationInfo& li)
{
    m_Id = li.Id();
    m_NameRO = li.NameRO();
    m_NameDE = li.NameDE();
    m_NameSX = li.NameSX();
    m_NameHU = li.NameHU();
    m_DeaneryInfo = li.DeaneryInfo();
    m_InventoryDate = li.InventoryDate();
    m_OldStatus = li.OldStatus();

    return *this;
}

bool
LocationInfo::operator==(const LocationInfo& li)const
{
    return m_Id == li.Id();
}

bool
LocationInfo::operator!=(const LocationInfo& li)const
{
    return !(this->operator ==(li));
}

bool
LocationInfo::CreateTable()
{
    bool result = true;
    RunQuery(LocationInfo::STR_CREATE_TABLE, result);

    QString strQuery = QString("Insert Into LocationInfo (Id, NameRO, NameDE, NameSX, NameHU, IdLocality, IdDeanery, InventoryDate, OldStatus) \
Values ('{00000000-0000-0000-0000-000000000000}', 'N/A', 'N/A', 'N/A', 'N/A', '{00000000-0000-0000-0000-000000000000}',\
'{00000000-0000-0000-0000-000000000000}', '', 'N/A')");
    RunQuery(strQuery, result);

    return result;
}

bool
LocationInfo::TableExists()
{
    return ::TableExists(LocationInfo::STR_TABLE_NAME);
}
