#include "Locality.h"
#include "WndFilterBase.h"
#include "WndEditHouse.h"
#include "Language.h"
#include "WndHouse_TabBuilding.h"
#include "WndHouse_TabFunction.h"
#include "WndHouse_TabPositioning.h"
#include "ui_WndEditHouse.h"

WndEditHouse::WndEditHouse(QWidget *parent, const QUuid& houseId)
    :   QDialog(parent),
        m_HouseId(houseId.isNull() ? QUuid::createUuid() : houseId)
{
    initializeData();

//    connect(ui->edLocality, SIGNAL(d))

    House* ptrHouse = HouseManager::instance()->findHouse(m_HouseId);
    QUuid id = QUuid();

    if(ptrHouse)
        id = ptrHouse->HousePositioningId();

//    ui->tabDetails->addTab(new WndHouse_TabPositioning(ui->tabDetails, id), tr("Pozitionare"));

//    // TODO
//    ui->tabDetails->addTab(new WndHouse_TabFunction(ui->tabDetails), tr("Functie"));
//    ui->tabDetails->addTab(new WndHouse_TabBuilding(ui->tabDetails), tr("Cladire"));

    loadHouseInfo();
}

WndEditHouse::~WndEditHouse()
{
}

void
WndEditHouse::initializeData()
{
    int labelWidth = 80;
    int editWidth = 150;

    m_lblComune.setText(tr("Comuna"));
    m_lblCounty.setText(tr("Judet"));
    m_lblDate.setText(tr("Datare"));
    m_lblLocality.setText(tr("Localitate"));
    m_lblNumeGerman.setText(tr("Nume german"));
    m_lblNumeMaghiar.setText(tr("Nume maghiar"));
    m_lblNumeRomanesc.setText(tr("Nume romanesc"));
    m_lblNumeSasesc.setText(tr("Nume sasesc"));
    m_lblOldStatus.setText(tr("Statut vechi"));

    m_lblComune.setAlignment(Qt::AlignRight);
    m_lblCounty.setAlignment(Qt::AlignRight);
    m_lblDate.setAlignment(Qt::AlignRight);
    m_lblLocality.setAlignment(Qt::AlignRight);
    m_lblNumeGerman.setAlignment(Qt::AlignRight);
    m_lblNumeMaghiar.setAlignment(Qt::AlignRight);
    m_lblNumeRomanesc.setAlignment(Qt::AlignRight);
    m_lblNumeSasesc.setAlignment(Qt::AlignRight);
    m_lblOldStatus.setAlignment(Qt::AlignRight);

    m_lblComune.setMinimumWidth(labelWidth);
    m_lblComune.setMaximumWidth(labelWidth);
    m_lblCounty.setMinimumWidth(labelWidth);
    m_lblCounty.setMaximumWidth(labelWidth);
    m_lblDate.setMinimumWidth(labelWidth);
    m_lblDate.setMaximumWidth(labelWidth);
    m_lblLocality.setMinimumWidth(labelWidth);
    m_lblLocality.setMaximumWidth(labelWidth);
    m_lblNumeGerman.setMinimumWidth(labelWidth);
    m_lblNumeGerman.setMaximumWidth(labelWidth);
    m_lblNumeMaghiar.setMinimumWidth(labelWidth);
    m_lblNumeMaghiar.setMaximumWidth(labelWidth);
    m_lblNumeRomanesc.setMinimumWidth(labelWidth);
    m_lblNumeRomanesc.setMaximumWidth(labelWidth);
    m_lblNumeSasesc.setMinimumWidth(labelWidth);
    m_lblNumeSasesc.setMaximumWidth(labelWidth);
    m_lblOldStatus.setMinimumWidth(labelWidth);
    m_lblOldStatus.setMaximumWidth(labelWidth);

    m_edComune.setMinimumWidth(editWidth);
    m_edComune.setMaximumWidth(editWidth);
    m_edCounty.setMinimumWidth(editWidth);
    m_edCounty.setMaximumWidth(editWidth);
    m_edDate.setMinimumWidth(editWidth);
    m_edDate.setMaximumWidth(editWidth);
    m_edLocality.setMinimumWidth(editWidth);
    m_edLocality.setMaximumWidth(editWidth);
    m_edNumeGerman.setMinimumWidth(editWidth);
    m_edNumeGerman.setMaximumWidth(editWidth);
    m_edNumeMaghiar.setMinimumWidth(editWidth);
    m_edNumeMaghiar.setMaximumWidth(editWidth);
    m_edNumeRomanesc.setMinimumWidth(editWidth);
    m_edNumeRomanesc.setMaximumWidth(editWidth);
    m_edNumeSasesc.setMinimumWidth(editWidth);
    m_edNumeSasesc.setMaximumWidth(editWidth);
    m_edOldStatus.setMinimumWidth(editWidth);
    m_edOldStatus.setMaximumWidth(editWidth);

    connect(&m_edLocality, SIGNAL(doubleClick(QMouseEvent*)), SLOT(on_edLocality_doubleClicked(QMouseEvent*)));

    QHBoxLayout* layoutNumeRO = new QHBoxLayout();
    layoutNumeRO->setContentsMargins(0, 0, 0, 0);
    layoutNumeRO->setSpacing(0);

    layoutNumeRO->addStretch();
    layoutNumeRO->addWidget(&m_lblNumeRomanesc);
    layoutNumeRO->addSpacing(10);
    layoutNumeRO->addWidget(&m_edNumeRomanesc);
    layoutNumeRO->addStretch();

    QHBoxLayout* layoutNumeDE = new QHBoxLayout();
    layoutNumeDE->setContentsMargins(0, 0, 0, 0);
    layoutNumeDE->setSpacing(0);

    layoutNumeDE->addStretch();
    layoutNumeDE->addWidget(&m_lblNumeGerman);
    layoutNumeDE->addSpacing(10);
    layoutNumeDE->addWidget(&m_edNumeGerman);
    layoutNumeDE->addStretch();

    QHBoxLayout* layoutNumeSX = new QHBoxLayout();
    layoutNumeSX->setContentsMargins(0, 0, 0, 0);
    layoutNumeSX->setSpacing(0);

    layoutNumeSX->addStretch();
    layoutNumeSX->addWidget(&m_lblNumeSasesc);
    layoutNumeSX->addSpacing(10);
    layoutNumeSX->addWidget(&m_edNumeSasesc);
    layoutNumeSX->addStretch();

    QHBoxLayout* layoutNumeHU = new QHBoxLayout();
    layoutNumeHU->setContentsMargins(0, 0, 0, 0);
    layoutNumeHU->setSpacing(0);

    layoutNumeHU->addStretch();
    layoutNumeHU->addWidget(&m_lblNumeMaghiar);
    layoutNumeHU->addSpacing(10);
    layoutNumeHU->addWidget(&m_edNumeMaghiar);
    layoutNumeHU->addStretch();

    QHBoxLayout* layoutOldStatus = new QHBoxLayout();
    layoutOldStatus->setContentsMargins(0, 0, 0, 0);
    layoutOldStatus->setSpacing(0);

    layoutOldStatus->addStretch();
    layoutOldStatus->addWidget(&m_lblOldStatus);
    layoutOldStatus->addSpacing(10);
    layoutOldStatus->addWidget(&m_edOldStatus);
    layoutOldStatus->addStretch();

    QHBoxLayout* layoutLocality = new QHBoxLayout();
    layoutLocality->setContentsMargins(0, 0, 0, 0);
    layoutLocality->setSpacing(0);

    layoutLocality->addStretch();
    layoutLocality->addWidget(&m_lblLocality);
    layoutLocality->addSpacing(10);
    layoutLocality->addWidget(&m_edLocality);
    layoutLocality->addStretch();

    QHBoxLayout* layoutComune = new QHBoxLayout();
    layoutComune->setContentsMargins(0, 0, 0, 0);
    layoutComune->setSpacing(0);

    layoutComune->addStretch();
    layoutComune->addWidget(&m_lblComune);
    layoutComune->addSpacing(10);
    layoutComune->addWidget(&m_edComune);
    layoutComune->addStretch();

    QHBoxLayout* layoutCounty = new QHBoxLayout();
    layoutCounty->setContentsMargins(0, 0, 0, 0);
    layoutCounty->setSpacing(0);

    layoutCounty->addStretch();
    layoutCounty->addWidget(&m_lblCounty);
    layoutCounty->addSpacing(10);
    layoutCounty->addWidget(&m_edCounty);
    layoutCounty->addStretch();

    QHBoxLayout* layoutDate = new QHBoxLayout();
    layoutDate->setContentsMargins(0, 0, 0, 0);
    layoutDate->setSpacing(0);

    layoutDate->addStretch();
    layoutDate->addWidget(&m_lblDate);
    layoutDate->addSpacing(10);
    layoutDate->addWidget(&m_edDate);
    layoutDate->addStretch();

    QVBoxLayout* layoutTopLeft = new QVBoxLayout();
    layoutTopLeft->setContentsMargins(0, 0, 0, 0);
    layoutTopLeft->setSpacing(0);

    layoutTopLeft->addStretch();
    layoutTopLeft->addLayout(layoutNumeRO);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutNumeDE);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutNumeSX);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutNumeHU);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutOldStatus);
    layoutTopLeft->addSpacing(20);
    layoutTopLeft->addLayout(layoutLocality);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutComune);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutCounty);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutDate);
    layoutTopLeft->addStretch();

    QHBoxLayout* layoutImgNextPrev = new QHBoxLayout();

    QVBoxLayout* layoutTopRight = new QVBoxLayout();
    layoutTopRight->setContentsMargins(0, 0, 0, 0);
    layoutTopRight->setSpacing(0);

    layoutTopRight->addStretch();
    layoutTopRight->addWidget(&m_Image);
    layoutTopRight->addSpacing(10);
    layoutTopRight->addLayout(layoutImgNextPrev);


    QHBoxLayout* layoutTop = new QHBoxLayout();
    layoutTop->setContentsMargins(0, 0, 0, 0);
    layoutTop->setSpacing(0);
    layoutTop->addLayout(layoutTopLeft);
    layoutTop->addSpacing(10);
    layoutTop->addLayout(layoutTopRight);

    QHBoxLayout* layoutBottom = new QHBoxLayout();
    layoutBottom->setContentsMargins(0, 0, 0, 0);
    layoutBottom->setSpacing(0);
    layoutBottom->addWidget(&m_Tab);

    QVBoxLayout* layoutMain = new QVBoxLayout();
    layoutMain->setContentsMargins(10, 10, 10, 10);
    layoutMain->setSpacing(0);

    layoutMain->addLayout(layoutTop);
    layoutMain->addSpacing(10);
    layoutMain->addLayout(layoutBottom);

    setLayout(layoutMain);
}

void
WndEditHouse::loadHouseInfo()
{
    if(m_HouseId.isNull())
        return;

    House* ptrHouse = HouseManager::instance()->findHouse(m_HouseId);
    if(ptrHouse != nullptr){
        m_edNumeRomanesc.setText(ptrHouse->Name()[Language::LANGUAGE_ROMANIAN]);
        m_edNumeGerman.setText(ptrHouse->Name()[Language::LANGUAGE_GERMAN]);
        m_edNumeSasesc.setText(ptrHouse->Name()[Language::LANGUAGE_SAXON]);
        m_edNumeMaghiar.setText(ptrHouse->Name()[Language::LANGUAGE_HUNGARIAN]);
        m_edDate.setText(ptrHouse->HouseDating());
        m_Image.setPixmap(QPixmap(ptrHouse->getImages().front()->Path()));

//        QWidget* tabWidget = ui->tabDetails->widget(0);
//        if(tabWidget != nullptr){
//            qobject_cast<WndHouse_TabPositioning*>(tabWidget)->loadFromDB(ptrHouse->HouseFunctionId());
//        }
    }
}

void
WndEditHouse::onSave()
{
    if(m_pHouse == nullptr)
        return;

    if(m_pHouse->Id().isNull()){
        // The house is newly created => Insert in db
    }else{
        // This is an edit => Save in db
        m_pHouse->saveToDB();
    }
}

void
WndEditHouse::onCancel()
{
}

void
WndEditHouse::on_btnNextImage_clicked()
{

}

void
WndEditHouse::on_btnPrevImage_clicked()
{

}

void
WndEditHouse::on_edLocality_doubleClicked(QMouseEvent* ev)
{
    Q_UNUSED(ev);

    WndFilterBase filterLocality(Locality::STR_TABLE_NAME, this);
    filterLocality.exec();

    QUuid idLocality = filterLocality.getSelectedId();
    if(idLocality.isNull())
        m_edLocality.clear();

    // TODO
}
