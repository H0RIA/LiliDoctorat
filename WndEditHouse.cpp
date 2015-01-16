#include "WndEditHouse.h"
#include "Language.h"
#include "WndHouse_TabBuilding.h"
#include "WndHouse_TabFunction.h"
#include "WndHouse_TabPositioning.h"
#include "ui_WndEditHouse.h"

WndEditHouse::WndEditHouse(QWidget *parent, const QUuid& houseId)
    :   QDialog(parent),
        ui(new Ui::WndEditHouse),
        m_HouseId(houseId.isNull() ? QUuid::createUuid() : houseId)
{
    ui->setupUi(this);

    ui->tabDetails->clear();
    House* ptrHouse = HouseManager::instance()->findHouse(m_HouseId);
    QUuid id = QUuid();

    if(ptrHouse)
        id = ptrHouse->HousePositioningId();

    ui->tabDetails->addTab(new WndHouse_TabPositioning(ui->tabDetails, id), tr("Pozitionare"));

    // TODO
    ui->tabDetails->addTab(new WndHouse_TabFunction(ui->tabDetails), tr("Functie"));
    ui->tabDetails->addTab(new WndHouse_TabBuilding(ui->tabDetails), tr("Cladire"));

    loadHouseInfo();
}

WndEditHouse::~WndEditHouse()
{
    delete ui;
}

void
WndEditHouse::loadHouseInfo()
{
    if(m_HouseId.isNull())
        return;

    House* ptrHouse = HouseManager::instance()->findHouse(m_HouseId);
    if(ptrHouse != nullptr){
        ui->edHouseName_RO->setText(ptrHouse->Name()[Language::LANGUAGE_ROMANIAN]);
        ui->edHouseName_DE->setText(ptrHouse->Name()[Language::LANGUAGE_GERMAN]);
        ui->edHouseName_SX->setText(ptrHouse->Name()[Language::LANGUAGE_SAXON]);
        ui->edHouseName_HU->setText(ptrHouse->Name()[Language::LANGUAGE_HUNGARIAN]);
        ui->edDate->setText(ptrHouse->HouseDating());
        ui->lblImage->setPixmap(QPixmap(ptrHouse->getImages().front()->Path()));

        QWidget* tabWidget = ui->tabDetails->widget(0);
        if(tabWidget != nullptr){
            qobject_cast<WndHouse_TabPositioning*>(tabWidget)->loadFromDB(ptrHouse->HouseFunctionId());
        }
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
