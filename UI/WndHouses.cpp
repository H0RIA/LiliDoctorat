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
    QAbstractItemModel* oldModel = m_View.model();
    if(oldModel != nullptr)
        oldModel->deleteLater();

    QSqlQueryModel* model = new QSqlQueryModel();
    QString strQuery = QString("select\
                               House.Id, House.NameRO, House.NameDE, House.NameSX, House.NameHU, House.Description, House.HouseDating,\
                               Locality.NameRO As LocalityRO, Locality.NameDE As LocalityDE, Locality.NameSX As LocalitySX, Locality.NameHU As LocalityHU, House.OldStatus,\
                               HouseFunction.Current As CurrentFunction\
                           from House\
                               Join Locality On House.IdLocality = Locality.Id\
                               Join BuildingInfo On House.IdBuildingInfo = BuildingInfo.Id\
                               Join HouseFunction On House.IdHouseFunction = HouseFunction.Id\
                               Join HousePositioning On House.IdHousePositioning = HousePositioning.Id");
    QSqlQuery query(strQuery);
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name RO"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Name DE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Name SX"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Name HU"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Dating"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Locality RO"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Locality DE"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Locality SX"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Locality HU"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Old Status"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Current function"));

    m_View.setModel(model);
    m_View.setColumnHidden(0, true);
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

    QModelIndex indexId = index.model()->index(index.row(), 0);
    QUuid idHouse = index.model()->data(indexId).toUuid();
    if(!idHouse.isNull()){
        WndEditHouse dialog(idHouse, this);
        dialog.exec();
        resetModel();
    }
}

