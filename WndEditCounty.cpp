#include "Language.h"
#include "WndEditCounty.h"

using namespace UI;

WndEditCounty::WndEditCounty(QWidget *parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_County(),
        m_lblLanguage(this),
        m_cbLanguage(this),
        m_lblName(this),
        m_edName(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    initializeData();
}

WndEditCounty::WndEditCounty(const QUuid& countyId, QWidget* parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_County(),
        m_lblLanguage(this),
        m_cbLanguage(this),
        m_lblName(this),
        m_edName(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    m_County.setId(countyId);

    initializeData();
}

WndEditCounty::~WndEditCounty()
{

}

void
WndEditCounty::initializeData()
{
    if(!m_NewItem)
        loadFromDB();

    m_btnCancel.setText(tr("Cancel"));
    m_btnApply.setText(tr("Apply"));
    m_btnOK.setText(tr("OK"));

    connect(&m_btnApply, SIGNAL(clicked()), SLOT(onApply()));
    connect(&m_btnCancel, SIGNAL(clicked()), SLOT(onCancel()));
    connect(&m_btnOK, SIGNAL(clicked()), SLOT(onOK()));

    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(0);
    btnLayout->setContentsMargins(0, 0, 0, 0);

    btnLayout->addStretch();
    btnLayout->addWidget(&m_btnCancel);
    btnLayout->addSpacing(5);
    btnLayout->addWidget(&m_btnOK);
    btnLayout->addSpacing(5);
    btnLayout->addWidget(&m_btnApply);
    btnLayout->addStretch();

    // TODO

    int labelWidth = 60;
    int editWidth = 180;

    m_lblName.setMinimumWidth(labelWidth);
    m_lblName.setMaximumWidth(labelWidth);
    m_lblLanguage.setMinimumWidth(labelWidth);
    m_lblLanguage.setMaximumWidth(labelWidth);

    m_edName.setMaximumWidth(editWidth);
    m_edName.setMinimumWidth(editWidth);
    m_cbLanguage.setMaximumWidth(editWidth);
    m_cbLanguage.setMinimumWidth(editWidth);

    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable(Language::STR_TABLE_NAME);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!model->select()){
        qDebug() << model->lastError().text();
    }else{
        m_cbLanguage.setModel(model);
        m_cbLanguage.setModelColumn(1);
    }

    QHBoxLayout* layoutLanguage = new QHBoxLayout();
    layoutLanguage->setContentsMargins(0, 0, 0, 0);
    layoutLanguage->setSpacing(0);

    layoutLanguage->addSpacing(20);
    layoutLanguage->addStretch();
    layoutLanguage->addWidget(&m_lblLanguage);
    layoutLanguage->addSpacing(10);
    layoutLanguage->addWidget(&m_cbLanguage);
    layoutLanguage->addStretch();
    layoutLanguage->addSpacing(20);

    QHBoxLayout* layoutName = new QHBoxLayout();
    layoutName->setContentsMargins(0, 0, 0, 0);
    layoutName->setSpacing(0);

    layoutName->addSpacing(20);
    layoutName->addStretch();
    layoutName->addWidget(&m_lblName);
    layoutName->addSpacing(10);
    layoutName->addWidget(&m_edName);
    layoutName->addStretch();
    layoutName->addSpacing(20);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addStretch();
    mainLayout->addSpacing(20);
    mainLayout->addLayout(layoutLanguage);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutName);
    mainLayout->addSpacing(10);
    mainLayout->addStretch();

    setLayout(mainLayout);
}

bool
WndEditCounty::loadFromDB(const QUuid& id)
{
    if(!id.isNull())
        m_County.setId(id);

//    if(m_County.LoadFromDB()){
//        m_edName.setText(m_County.Name());

//        QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database());
//        model->setTable(Language::STR_TABLE_NAME);
//        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//        if(!model->select()){
//            qDebug() << model->lastError().text();
//        }else{
//            m_cbLanguage.setModel(model);
//        }

//        return true;
//    }

    return false;
}

bool
WndEditCounty::saveToDB()
{
    return false;
}

void
WndEditCounty::onLanguageChanged()
{
}

void
WndEditCounty::onCancel()
{
    done(-1);
}

void
WndEditCounty::onOK()
{
    saveToDB();
    done(0);
}

void
WndEditCounty::onApply()
{
    saveToDB();
}
