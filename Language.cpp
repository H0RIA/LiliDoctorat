#include "Language.h"

QUuid Language::LANGUAGE_ROMANIAN = QUuid();
QUuid Language::LANGUAGE_GERMAN = QUuid();
QUuid Language::LANGUAGE_SAXON = QUuid();
QUuid Language::LANGUAGE_HUNGARIAN = QUuid();

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
