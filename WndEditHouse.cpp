#include "WndEditHouse.h"
#include "Language.h"
#include "HouseManager.h"
#include "ui_WndEditHouse.h"

WndEditHouse::WndEditHouse(QWidget *parent, const QUuid& houseId)
    :   QDialog(parent),
        ui(new Ui::WndEditHouse),
        m_HouseId(houseId.isNull() ? QUuid::createUuid() : houseId)
{
    ui->setupUi(this);
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
    }
}

void
WndEditHouse::on_btnNextImage_clicked()
{

}

void
WndEditHouse::on_btnPrevImage_clicked()
{

}
