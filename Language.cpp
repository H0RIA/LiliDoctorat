#include "Language.h"

QUuid Language::LANGUAGE_ROMANIAN = QUuid();
QUuid Language::LANGUAGE_GERMAN = QUuid();
QUuid Language::LANGUAGE_SAXON = QUuid();
QUuid Language::LANGUAGE_HUNGARIAN = QUuid();

QString Language::STR_CREATE_TABLE = "Create table Language (\
Id varchar(50) primary key,\
Name varchar(255))";
QString Language::STR_TABLE_NAME = "Language";

Language::Language()
    :   m_Id(QUuid::createUuid()),
        m_Name()
{
}

//Language::Language(const QString& name)
//    :   m_Id(QUuid::createUuid()),
//        m_Name(name)
//{
//}

Language::Language(const Language& lang)
    :   m_Id(lang.Id()),
        m_Name(lang.Name())
{
}

Language::~Language(){}

Language&
Language::operator=(const Language& lang)
{
    m_Id = lang.Id();
    m_Name = lang.Name();

    return *this;
}

bool
Language::operator==(const Language& lang)const
{
    return m_Id == lang.Id();
}

bool
Language::operator!=(const Language& lang)const
{
    return !(this->operator ==(lang));
}

bool
Language::CreateTable()
{
    bool result = true;
    RunQuery(Language::STR_CREATE_TABLE, result);

    return result;
}

bool
Language::TableExists()
{
    return ::TableExists(Language::STR_TABLE_NAME);
}
