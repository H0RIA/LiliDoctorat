#include "Language.h"

using namespace DBWrapper;

QUuid Language::LANGUAGE_ROMANIAN = QUuid("{A808E920-C40E-11E4-8830-0800200C9A66}");
QUuid Language::LANGUAGE_GERMAN = QUuid("{A2DF58D0-C40E-11E4-8830-0800200C9A66}");
QUuid Language::LANGUAGE_SAXON = QUuid("{ABA522B0-C40E-11E4-8830-0800200C9A66}");
QUuid Language::LANGUAGE_HUNGARIAN = QUuid("{B0FAF320-C40E-11E4-8830-0800200C9A66}");

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
    RunQuery("Insert into Language (Id, Name) Values ('{A808E920-C40E-11E4-8830-0800200C9A66}', 'Romana')", result);
    RunQuery("Insert into Language (Id, Name) Values ('{A2DF58D0-C40E-11E4-8830-0800200C9A66}', 'Deutsch')", result);
    RunQuery("Insert into Language (Id, Name) Values ('{ABA522B0-C40E-11E4-8830-0800200C9A66}', 'Saxon')", result);
    RunQuery("Insert into Language (Id, Name) Values ('{B0FAF320-C40E-11E4-8830-0800200C9A66}', 'Magyar')", result);

    return result;
}

bool
Language::TableExists()
{
    return ::TableExists(Language::STR_TABLE_NAME);
}
