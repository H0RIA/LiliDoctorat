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
WndEditHouse::on_edLocality_doubleClicked()
{
    WndFilterBase filterLocality(Locality::STR_TABLE_NAME, this);
    filterLocality.exec();

    QUuid idLocality = filterLocality.getSelectedId();
    if(idLocality.isNull())
        m_edLocality.clear();
}
