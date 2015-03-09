#include "WndEditLocality.h"
#include "Locality.h"
#include "WndLocalities.h"

using namespace UI;

WndLocalities::WndLocalities(QWidget* parent)
    :   QWidget(parent),
        m_View(this)
{
    initializeData();
}

WndLocalities::~WndLocalities()
{
}

void
WndLocalities::onNewItem()
{
    WndEditLocality newEditor(this);
    newEditor.exec();
    resetModel();
}

void
WndLocalities::resetModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString strQuery = QString("Select %1.*, %2.NameRO As CountyRO, %3.NameDE As CountyDE, %4.NameSX As CountySX, %5.NameHU As CountyHU  From %6 Join %7 On %8.IdCounty = %9.Id")
            .arg(Locality::STR_TABLE_NAME).arg(County::STR_TABLE_NAME).arg(County::STR_TABLE_NAME).arg(County::STR_TABLE_NAME).arg(County::STR_TABLE_NAME)
            .arg(Locality::STR_TABLE_NAME).arg(County::STR_TABLE_NAME).arg(Locality::STR_TABLE_NAME).arg(County::STR_TABLE_NAME);
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
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("CountyId"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("County RO"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("County DE"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("County SX"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("County HU"));
        m_View.setModel(model);
        m_View.setColumnHidden(0, true);
        m_View.setColumnHidden(5, true);
//    }
}

void
WndLocalities::initializeData()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 5, 0, 0);
    mainLayout->setSpacing(0);

    resetModel();

    mainLayout->addWidget(&m_View);

    setLayout(mainLayout);
}
