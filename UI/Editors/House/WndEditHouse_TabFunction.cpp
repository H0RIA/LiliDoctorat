#include "UI/Core/WndFilterBase.h"
#include "WndEditHouse_TabFunction.h"

using namespace UI::Editors::House;

WndEditHouse_TabFunction::WndEditHouse_TabFunction(DBWrapper::House* pHouse, bool newItem, QWidget* parent)
    :   QWidget(parent)
        ,m_lblOriginal(this)
        ,m_edOriginal(this)
        ,m_lblCurrent(this)
        ,m_edCurrent(this)
        ,m_lblLegalStatus(this)
        ,m_cbLegal(this)
{
    initializeData();

    if(newItem){
        if(pHouse != nullptr)
            pHouse->setHouseFunctionId(m_Function.Id());
    }else{
        if(!pHouse->HouseFunctionId().isNull()){
            loadFromDB(pHouse->HouseFunctionId());
        }
        else
            pHouse->setHouseFunctionId(m_Function.Id());
    }
}

bool
WndEditHouse_TabFunction::saveToDB()
{
    m_Function.setOriginal(m_edOriginal.text());
    m_Function.setCurrent(m_edCurrent.text());
    m_Function.setLegalStatus((DBWrapper::HouseLegalStatus)m_cbLegal.currentData().toInt());

    return m_Function.saveToDB();
}

bool
WndEditHouse_TabFunction::loadFromDB(const QUuid& id)
{
    bool result = m_Function.loadFromDB(id);

    if(result){
        m_edCurrent.setText(m_Function.Current());
        m_edOriginal.setText(m_Function.Original());
        m_cbLegal.setCurrentIndex(m_cbLegal.findData((int)m_Function.LegalStatus()));
    }

    return result;
}

void
WndEditHouse_TabFunction::initializeData()
{
    m_lblOriginal.setText(tr("Original:"));
    m_lblCurrent.setText(tr("Current:"));
    m_lblLegalStatus.setText(tr("Legal status:"));

    m_cbLegal.addItem(tr("Evangelical church"), (int)DBWrapper::HouseLegalStatus::EvangelicalChurch);
    m_cbLegal.addItem(tr("Other cults"), (int)DBWrapper::HouseLegalStatus::OtherCults);
    m_cbLegal.addItem(tr("Private property"), (int)DBWrapper::HouseLegalStatus::PrivateProperty);
    m_cbLegal.addItem(tr("Does not exist"), (int)DBWrapper::HouseLegalStatus::DoesNotExist);

    QVBoxLayout* verticalLayout = new QVBoxLayout();
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->setSpacing(0);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);



    QGridLayout* centralLayout = new QGridLayout();
    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralLayout->setSpacing(5);

    int row = 0;
    int col = 0;

    // Configure label column
    centralLayout->addWidget(&m_lblOriginal, row, col, 1, 1, Qt::AlignRight);
    row = 1;
    centralLayout->addWidget(&m_lblCurrent, row, col, 1, 1, Qt::AlignRight);
    row = 2;
    centralLayout->addWidget(&m_lblLegalStatus, row, col, 1, 1, Qt::AlignRight);

    // Configure editors column
    col = 1;
    row = 0;
    centralLayout->addWidget(&m_edOriginal, row, col, 1, 1, Qt::AlignLeft);
    row = 1;
    centralLayout->addWidget(&m_edCurrent, row, col, 1, 1, Qt::AlignLeft);
    row = 2;
    centralLayout->addWidget(&m_cbLegal, row, col, 1, 1, Qt::AlignLeft);

    verticalLayout->addSpacing(50);
    verticalLayout->addLayout(centralLayout);
    verticalLayout->addStretch();

    mainLayout->addStretch();
    mainLayout->addLayout(verticalLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);
}
