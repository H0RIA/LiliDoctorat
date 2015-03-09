#include "HouseModel.h"
#include "ThumbnailDelegate.h"
#include "WndEditHouse.h"
#include "WndHouses.h"

using namespace UI;

WndHouses::WndHouses(QWidget* parent)
    :   QWidget(parent),
        m_View(this)
{
    initializeData();
}

WndHouses::~WndHouses()
{
}

void
WndHouses::onNewItem()
{
    WndEditHouse newEditor(this);
    newEditor.exec();
    resetModel();
}

void
WndHouses::resetModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString strQuery = QString("select\
                               House.Id, House.NameRO, House.NameDE, House.NameSX, House.NameHU, House.Description, House.HouseDating,\
                               LocationInfo.NameRO As LocationRO, LocationInfo.NameDE As LocationDE, LocationInfo.NameSX As LocationSX, LocationInfo.NameHU As LocationHU, LocationInfo.OldStatus,\
                               HouseFunction.Current As CurrentFunction\
                           from House\
                               Join LocationInfo On House.IdLocation = LocationInfo.Id\
                               Join BuildingInfo On House.IdBuildingInfo = BuildingInfo.Id\
                               Join HouseFunction On House.IdHouseFunction = HouseFunction.Id\
                               Join HousePositioning On House.IdHousePositioning = HousePositioning.Id");
    QSqlQuery query(strQuery);
    model->setQuery(query);
//    if(!model->select()){
//        qDebug() << model->lastError().text();
//    }else{
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name RO"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Name DE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Name SX"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Name HU"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Dating"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Location RO"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("Location DE"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Location SX"));
        model->setHeaderData(10, Qt::Horizontal, QObject::tr("Location HU"));
        model->setHeaderData(11, Qt::Horizontal, QObject::tr("Old Status"));
        model->setHeaderData(12, Qt::Horizontal, QObject::tr("Current function"));

        m_View.setModel(model);
        m_View.setColumnHidden(0, true);
//    }
}

void
WndHouses::initializeData()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 5, 0, 0);
    mainLayout->setSpacing(0);

    resetModel();

    mainLayout->addWidget(&m_View);

    setLayout(mainLayout);

    connect(&m_View, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)));
}

void
WndHouses::onDoubleClicked(const QModelIndex& index)
{
    if(!index.isValid())
        return;

    int row = index.row();
    House* ptrHouse = qobject_cast<HouseModel*>(m_View.model())->getHouseManager()->getHouses().at(row);
    if(ptrHouse != nullptr)
    {
        WndEditHouse dialog(ptrHouse->Id(), this);
        dialog.exec();
    }
}

