#include "LocationInfo.h"

QString LocationInfo::STR_CREATE_TABLE = "Create table LocationInfo (\
Id varchar(50) primary key,\
IdLocale varchar(50),\
LocalizedName varchar(255),\
IdComune varchar(50),\
IdShire varchar(50),\
IdDeanery varchar(50),\
InventoryDate date,\
OldStatus text,\
FOREIGN KEY(IdComune) REFERENCES Locality(Id),\
FOREIGN KEY(IdShire) REFERENCES Shire(Id),\
FOREIGN KEY(IdDeanery) REFERENCES Deanery(Id))";
QString LocationInfo::STR_TABLE_NAME = "LocationInfo";

LocationInfo::LocationInfo()
    :   m_Id(QUuid::createUuid()),
        m_Name(),
        m_Comune(),
        m_ShireInfo(),
        m_DeaneryInfo(),
        m_InventoryDate(),
        m_OldStatus()
{}

LocationInfo::LocationInfo(const LocationInfo& li)
    :   m_Id(li.Id()),
        m_Name(li.Name()),
        m_Comune(li.Comune()),
        m_ShireInfo(li.ShireInfo()),
        m_DeaneryInfo(li.DeaneryInfo()),
        m_InventoryDate(li.InventoryDate()),
        m_OldStatus(li.OldStatus())
{}

LocationInfo::~LocationInfo(){}

LocationInfo&
LocationInfo::operator=(const LocationInfo& li)
{
    m_Id = li.Id();
    m_Name = li.Name();
    m_Comune = li.Comune();
    m_ShireInfo = li.ShireInfo();
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

    return result;
}

bool
LocationInfo::TableExists()
{
    return ::TableExists(LocationInfo::STR_TABLE_NAME);
}
